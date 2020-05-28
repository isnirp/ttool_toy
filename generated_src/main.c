#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "request.h"
#include "syncchannel.h"
#include "request_manager.h"
#include "debug.h"
#include "random.h"
#include "tracemanager.h"
#include "ssl_wrapper.h"

/* Main mutex */
pthread_mutex_t __mainMutex;

/* Synchronous channels */
syncchannel __System_chin__System_chout;
/* Asynchronous channels */

#include "System.h"
#include "T1.h"
#include "T2.h"

int main(int argc, char *argv[])
{

  /* disable buffering on stdout */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* Synchronous channels */
  __System_chin__System_chout.inname = "chin";
  __System_chin__System_chout.outname = "chout";
  /* Asynchronous channels */

  /* Threads of tasks */
  pthread_t thread__System;
  pthread_t thread__T1;
  pthread_t thread__T2;
  /* Activating tracing  */
  if (argc > 1)
  {
    activeTracingInFile(argv[1]);
  }
  else
  {
    activeTracingInConsole();
  }
  /* Activating randomness */
  initRandom();
  /* Initializing the main mutex */
  if (pthread_mutex_init(&__mainMutex, NULL) < 0)
  {
    exit(-1);
  }

  /*
  *PRINCE
  * initialize ssl
  * **/
  init_ssl();

  /* Initializing mutex of messages */
  initMessages();

  pthread_create(&thread__System, NULL, mainFunc__System, (void *)"System");
  pthread_create(&thread__T1, NULL, mainFunc__T1, (void *)"T1");
  pthread_create(&thread__T2, NULL, mainFunc__T2, (void *)"T2");

  pthread_join(thread__System, NULL);
  pthread_join(thread__T1, NULL);
  pthread_join(thread__T2, NULL);

  return 0;
}
