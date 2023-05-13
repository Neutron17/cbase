#include "lt.h"
#include <stdlib.h>
#include <pthread.h>

#include "log.h"

static LT_t lt;

void init(LT_t _lt) {
	lt = _lt;
	for(int i = 0; i < lt.size; i++)
		lt.handlers[i].init(lt.handlers[i].init_param[0], lt.handlers[i].init_param[1]);
	loginit(L_ALL, L_ALL);
}

__attribute__((noreturn))
void cleanUp(int ret) {
	for(int i = 0; i < lt.size; i++)
		lt.handlers[i].defer(lt.handlers[i].defer_param);
	//logdestroy();
	exit(ret);
}

