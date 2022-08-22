#include "lt.h"
#include <stdlib.h>
#include <pthread.h>

#include "log.h"

extern pthread_mutex_t logmutex;

void init() {
	pthread_mutex_init(&logmutex, 0);
	loginit(L_ALL, L_ALL);
}

__attribute__((noreturn))
void cleanUp(int ret) {
	pthread_mutex_destroy(&logmutex);
	logdestroy();
	exit(ret);
}

