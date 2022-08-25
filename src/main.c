#include <aio.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "log.h"
#include "lt.h"
#include "exitCodes.h"
#include "stdext.h"
#include "global.h"

#define BUFF_SZ 16

int main(int argc, char *argv[]) {
	init();
	LOG(L_INFO, "Hello World");
	cleanUp(E_SUCCESS);
}

