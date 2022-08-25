#include "lt.h"
#include <stdlib.h>
#include <pthread.h>

#include "log.h"

extern pthread_mutex_t logmutex;

void init() {
	loginit(L_ALL, L_ALL);
}

__attribute__((noreturn))
void cleanUp(int ret) {
	logdestroy();
	exit(ret);
}

