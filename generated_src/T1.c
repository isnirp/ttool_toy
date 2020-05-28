#include "T1.h"

#define STATE__START__STATE 0
#define STATE__beforeFinish 1
#define STATE__sendingMessage 2
#define STATE__makingMessage 3
#define STATE__STOP__STATE 4

/*
  *PRINCE
  * 
  * **/
int sock;
char host = "T2";
char port = "some_port";

int T1__encrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "encrypt", my__attr);
  return msg__data;
}

int T1__decrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "decrypt", my__attr);
  return msg__data;
}

int T1__sencrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "sencrypt", my__attr);
  return msg__data;
}

int T1__sdecrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "sdecrypt", my__attr);
  return msg__data;
}

int T1__MAC(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "MAC", my__attr);
  return msg__data;
}

bool T1__verifyMAC(int msg__data, int k__data, int macmsg__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d", msg__data, k__data, macmsg__data);
  traceFunctionCall("T1", "verifyMAC", my__attr);
  return msg__data;
}

int T1__concat2(int msg1__data, int msg2__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg1__data, msg2__data);
  traceFunctionCall("T1", "concat2", my__attr);
  return msg1__data;
}

int T1__concat3(int msg1__data, int msg2__data, int msg3__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d", msg1__data, msg2__data, msg3__data);
  traceFunctionCall("T1", "concat3", my__attr);
  return msg1__data;
}

int T1__concat4(int msg1__data, int msg2__data, int msg3__data, int msg4__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d", msg1__data, msg2__data, msg3__data, msg4__data);
  traceFunctionCall("T1", "concat4", my__attr);
  return msg1__data;
}

void T1__get2(int msg__data, int msg1__data, int msg2__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d", msg__data, msg1__data, msg2__data);
  traceFunctionCall("T1", "get2", my__attr);
}

void T1__get3(int msg__data, int msg1__data, int msg2__data, int msg3__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d", msg__data, msg1__data, msg2__data, msg3__data);
  traceFunctionCall("T1", "get3", my__attr);
}

void T1__get4(int msg__data, int msg1__data, int msg2__data, int msg3__data, int msg4__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d,%d", msg__data, msg1__data, msg2__data, msg3__data, msg4__data);
  traceFunctionCall("T1", "get4", my__attr);
}

int T1__aencrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "aencrypt", my__attr);
  return msg__data;
}

int T1__adecrypt(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "adecrypt", my__attr);
  return msg__data;
}

int T1__pk(int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d", k__data);
  traceFunctionCall("T1", "pk", my__attr);
  return k__data;
}

int T1__sign(int msg__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", msg__data, k__data);
  traceFunctionCall("T1", "sign", my__attr);
  return msg__data;
}

bool T1__verifySign(int msg1__data, int sig__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d", msg1__data, sig__data, k__data);
  traceFunctionCall("T1", "verifySign", my__attr);
  return msg1__data;
}

int T1__cert(int k__data, int msg__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", k__data, msg__data);
  traceFunctionCall("T1", "cert", my__attr);
  return k__data;
}

bool T1__verifyCert(int cert__data, int k__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", cert__data, k__data);
  traceFunctionCall("T1", "verifyCert", my__attr);
  return cert__data;
}

int T1__getpk(int cert__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d", cert__data);
  traceFunctionCall("T1", "getpk", my__attr);
  return cert__data;
}

int T1__DH(int pubK__data, int privK__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d", pubK__data, privK__data);
  traceFunctionCall("T1", "DH", my__attr);
  return pubK__data;
}

int T1__hash(int msg__data)
{
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d", msg__data);
  traceFunctionCall("T1", "hash", my__attr);
  return msg__data;
}

void *mainFunc__T1(void *arg)
{
  int secretData = 0;
  int m__data = 0;
  int m1__data = 0;
  int sk__data = 0;

  /*
  *PRINCE
  * open connection where message is being sent
  * **/
  sock = open_connection(host, port);

  int __currentState = STATE__START__STATE;
  __attribute__((unused)) request __req0;
  __attribute__((unused)) int *__params0[1];
  __attribute__((unused)) setOfRequests __list;
  __attribute__((unused)) pthread_cond_t __myCond;
  __attribute__((unused)) request *__returnRequest;

  char *__myname = (char *)arg;

  pthread_cond_init(&__myCond, NULL);

  fillListOfRequests(&__list, __myname, &__myCond, &__mainMutex);
  //printf("my name = %s\n", __myname);

  /* Main loop on states */
  while (__currentState != STATE__STOP__STATE)
  {
    switch (__currentState)
    {
    case STATE__START__STATE:
      traceStateEntering(__myname, "__StartState");
      __currentState = STATE__makingMessage;
      break;

    case STATE__beforeFinish:
      traceStateEntering(__myname, "beforeFinish");
      __currentState = STATE__STOP__STATE;
      break;

    case STATE__sendingMessage:
      traceStateEntering(__myname, "sendingMessage");
      __params0[0] = &m1__data;
      makeNewRequest(&__req0, 471, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0);
      __req0.syncChannel = &__System_chin__System_chout;
      __returnRequest = executeOneRequest(&__list, &__req0);
      clearListOfRequests(&__list);
      traceRequest(__myname, __returnRequest);
      /*
  *PRINCE
  * encrypt message
  * **/
      sendData(__params0[0], sizeof(__params0[0]));

      __currentState = STATE__beforeFinish;
      break;

    case STATE__makingMessage:
      traceStateEntering(__myname, "makingMessage");
      //m__data = secretData;
      /*
  *PRINCE
  * encrypt message
  * **/
      unsigned char ciphertext[128];
      m__data = do_encrypt(msg__data, sk__data, ciphertext);

      traceVariableModification("T1", "m__data", m__data, 0);
      m1__data = T1__sencrypt(m__data, sk__data);
      traceVariableModification("T1", "m1__data", m1__data, 0);
      __currentState = STATE__sendingMessage;
      break;
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}
