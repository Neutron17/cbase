#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "alloc.h"
#include "error.h"
#include "log.h"
#include "lt.h"
#include "exitCodes.h"
#include "arr.h"

#define BUFF_SZ 16

void printer(void *data) {
	printf("%d\t", *((int *)data));
}

__attribute__((noreturn))
void _defer(int ret) {
	logdestroy();
	exit(ret);
}

int main(int argc, char *argv[]) {
	loginit(L_ALL,L_ALL);
	cleanUp = _defer;
	LOG(L_INFO, "Hello World");

	Array_t arr;
	UNWRAP_TO_COMPLEX_FN(array_init(arenaInit(20*4), int, 10), arr, Array_t);
	int b = 1;
	for(int i = 0; i < 20; i++) {
		array_add(&arr, 0, b);
		array_print(arr);
		b++;
	}
	Array_t sub;
	//array_for_each(arr, printer);
	//puts("");
	array_print(arr);
	UNWRAP_TO_COMPLEX_FN(array_sub_array(pageAllocator(),arr, 5, 10), sub, Array_t);

	array_for_each(arr, printer);
	puts("");
	printf("%lu\n", sub.used);
	array_for_each(sub, printer);
	puts("");

	array_destroy(&sub);
	array_destroy(&arr);

	cleanUp(E_SUCCESS);
}

