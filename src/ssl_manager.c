#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/bio.h> /* BasicInput/Output streams */
#include <openssl/err.h> /* errors */
#include <openssl/ssl.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include "ssl_wrapper.h"

unsigned char *key = (unsigned char *)"01234567890123456789012345678901"; /* A 256 bit key */
unsigned char *iv = (unsigned char *)"0123456789012345";                  /* A 128 bit IV */

//handle errors
void log_errors(const char *msg)
{
    perror(msg);
    ERR_print_errors_fp(stderr);
    exit(-1);
}
//clean up

/*
*TAG sockets
*Assuming communication is done through sockets
*open connection socket
*/
int open_connection(const char *hostname, int port)
{
    int sockfd;
    struct hostent *host;
    struct sockaddr_in addr;
    if ((host = gethostbyname(hostname)) == NULL)
    {
        perror(hostname);
        abort();
    }
    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) != 0)
    {
        close(sockfd);
        perror(hostname);
        abort();
    }
    return sockfd;
}

/*
*TAG openssl
*initialize openssl
*/
void init_ssl()
{
    SSL_library_init();
    SSL_load_error_strings();     /*register error messages*/
    OpenSSL_add_all_algorithms(); /*Load cryptos*/
}

/*
*TAG openssl
*get security context
*/
SSL_CTX *init_CTX(void)
{
    const SSL_METHOD *method = TLSv1_2_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    if (ctx == NULL)
    {
        log_errors(stderr);
    }
    return ctx;
}

/*
*TAG openssl
*do encryption
*We are using EVP interface for encryption and decryption of messages
*EVP provides a set of user-level functions that can be used to perform various cryptographic operations
*/
int do_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new()))
        log_errors(stderr);

    /* using 256 bit AES */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        log_errors(stderr);

    /*
     * Provide the message to be encrypted, and obtain the encrypted output.
     * EVP_EncryptUpdate can be called multiple times if necessary
     */
    // EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
    //                             int *outl, const unsigned char *in, int inl)
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        log_errors(stderr);
    ciphertext_len = len;

    /*
     * Finalise the encryption. Further ciphertext bytes may be written at
     * this stage.
     */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        log_errors(stderr);
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

/*
*TAG openssl
*do decryption
*We are using EVP interface for encryption and decryption of messages
*EVP provides a set of user-level functions that can be used to perform various cryptographic operations
*/
int do_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new()))
        log_errors(stderr);

    /* using 256 bit AES  */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        log_errors(stderr);

    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    // EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
    //                            int *outl, const unsigned char *in, int inl)
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        log_errors(stderr);
    plaintext_len = len;

    /*
     * Finalise the decryption. Further plaintext bytes may be written at
     * this stage.
     */
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        log_errors(stderr);
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

/*
*TAG openssl
*using BIO to write to channel
*
*/
int sendData(int socket, unsigned char *ciphertext, int clen)
{
    /* create a socket BIO */
    /*BIO *bio = BIO_new(BIO_s_socket());
    BIO_set_fd(bio, sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);*/
    BIO *bio, *bio_buff, bio_ssl;
    bio = BIO_new_socket(socket, BIO_NOCLOSE);
    bio_ssl = BIO_new(BIO_f_ssl());
    bio_buff = BIO_new(BIO_f_buffer());
    SSL_set_bio(bio_ssl, bio, bio);

    //send data
    int ret = BIO_write(bio_buff, ciphertext, clen);

    BIO_free_all(bio);

    return ret;
}

/*
*TAG openssl
*using BIO to read from channel
*
*/
void readData()
{
}

/*
*TAG openssl
*write to channel
*openssl SSL_write() encrypts and sends message
*/
void writeToChannel(const char *hostname, int port, char *msg)
{
    SSL_CTX *ctx = init_CTX();
    int host = open_connection(hostname, port);
    SSL *ssl = SSL_new(ctx);
    /* attach the socket descriptor */
    SSL_set_fd(ssl, host);

    if (SSL_connect(ssl) == FAIL) /* perform the connection */
        log_errors(stderr);
    else
    {
        /* encrypt & send message */
        SSL_write(ssl, msg, strlen(msg));
        SSL_free(ssl);
    }
}

/*
*TAG openssl
*read from channel
*openssl SSL_read() decrypt & send message
*/
void readFromChannel(const char *hostname, int port, char *msg)
{
    SSL_CTX *ctx = init_CTX();
    int server = open_connection(hostname, port);
    SSL *ssl = SSL_new(ctx);
    /* attach the socket descriptor */
    SSL_set_fd(ssl, server);

    if (SSL_connect(ssl) == FAIL) /* perform the connection */
        log_errors(stderr);
    else
    {
        /* decrypt & send message */
        SSL_read(ssl, msg, strlen(msg));
        SSL_free(ssl);
    }
}
