#ifndef SSL_WRAPPER_H
#define SSL_WRAPPER_H

void init_ssl();
int open_connection(const char *hostname, int port);
int do_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext);
int do_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext);
int sendData(unsigned char *ciphertext, int clen)

#endif