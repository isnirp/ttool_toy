#include "T2.h"

#define STATE__START__STATE 0
#define STATE__messageDecrypted 1
#define STATE__SecretDataReceived 2
#define STATE__messageDecrypt 3
#define STATE__waitingForMessage 4
#define STATE__STOP__STATE 5

int T2__encrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "encrypt", my__attr);
  return msg__data;
}


int T2__decrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "decrypt", my__attr);
  return msg__data;
}


int T2__sencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "sencrypt", my__attr);
  return msg__data;
}


int T2__sdecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "sdecrypt", my__attr);
  return msg__data;
}


int T2__MAC(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "MAC", my__attr);
  return msg__data;
}


bool T2__verifyMAC(int msg__data, int k__data, int macmsg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,k__data,macmsg__data);
  traceFunctionCall("T2", "verifyMAC", my__attr);
  return msg__data;
}


int T2__concat2(int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg1__data,msg2__data);
  traceFunctionCall("T2", "concat2", my__attr);
  return msg1__data;
}


int T2__concat3(int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,msg2__data,msg3__data);
  traceFunctionCall("T2", "concat3", my__attr);
  return msg1__data;
}


int T2__concat4(int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("T2", "concat4", my__attr);
  return msg1__data;
}


void T2__get2(int msg__data, int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,msg1__data,msg2__data);
  traceFunctionCall("T2", "get2", my__attr);
}


void T2__get3(int msg__data, int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data);
  traceFunctionCall("T2", "get3", my__attr);
}


void T2__get4(int msg__data, int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("T2", "get4", my__attr);
}


int T2__aencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "aencrypt", my__attr);
  return msg__data;
}


int T2__adecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "adecrypt", my__attr);
  return msg__data;
}


int T2__pk(int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",k__data);
  traceFunctionCall("T2", "pk", my__attr);
  return k__data;
}


int T2__sign(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("T2", "sign", my__attr);
  return msg__data;
}


bool T2__verifySign(int msg1__data, int sig__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,sig__data,k__data);
  traceFunctionCall("T2", "verifySign", my__attr);
  return msg1__data;
}


int T2__cert(int k__data, int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",k__data,msg__data);
  traceFunctionCall("T2", "cert", my__attr);
  return k__data;
}


bool T2__verifyCert(int cert__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",cert__data,k__data);
  traceFunctionCall("T2", "verifyCert", my__attr);
  return cert__data;
}


int T2__getpk(int cert__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",cert__data);
  traceFunctionCall("T2", "getpk", my__attr);
  return cert__data;
}


int T2__DH(int pubK__data, int privK__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",pubK__data,privK__data);
  traceFunctionCall("T2", "DH", my__attr);
  return pubK__data;
}


int T2__hash(int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",msg__data);
  traceFunctionCall("T2", "hash", my__attr);
  return msg__data;
}


void *mainFunc__T2(void *arg){
  int m__data = 0;
  int m2__data = 0;
  int sk__data = 0;
  int receivedData = 0;
  
  int __currentState = STATE__START__STATE;
  __attribute__((unused)) request __req0;
  __attribute__((unused))int *__params0[1];
  __attribute__((unused))setOfRequests __list;
  __attribute__((unused))pthread_cond_t __myCond;
  __attribute__((unused))request *__returnRequest;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond, NULL);
  
  fillListOfRequests(&__list, __myname, &__myCond, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      __currentState = STATE__waitingForMessage;
      break;
      
      case STATE__messageDecrypted: 
      traceStateEntering(__myname, "messageDecrypted");
      receivedData = m__data;
      traceVariableModification("T2", "receivedData", receivedData,0);
      __currentState = STATE__SecretDataReceived;
      break;
      
      case STATE__SecretDataReceived: 
      traceStateEntering(__myname, "SecretDataReceived");
      __currentState = STATE__STOP__STATE;
      break;
      
      case STATE__messageDecrypt: 
      traceStateEntering(__myname, "messageDecrypt");
      m__data = T2__sdecrypt(m2__data, sk__data);
      traceVariableModification("T2", "m__data", m__data,0);
      __currentState = STATE__messageDecrypted;
      break;
      
      case STATE__waitingForMessage: 
      traceStateEntering(__myname, "waitingForMessage");
      __params0[0] = &m2__data;
      makeNewRequest(&__req0, 491, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0);
      __req0.syncChannel = &__System_chin__System_chout;
      __returnRequest = executeOneRequest(&__list, &__req0);
      clearListOfRequests(&__list);
      traceRequest(__myname, __returnRequest);
      __currentState = STATE__messageDecrypt;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

