#include <aio.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error.h"
#include "global.h"
#include "log.h"
#include "lt.h"
#include "exitCodes.h"
#include "stdext.h"
#include "arr.h"

#define BUFF_SZ 16

void printer(void *data) {
	printf("%d\t", *((int *)data));
}

int main(int argc, char *argv[]) {
	init((LT_t) {
			.handlers = (struct LTHandler[]) { 
				{
					(ltfunc_init) loginit, 
					{ (void *)L_ALL, (void *)L_ALL },
					(ltfunc_def) logdestroy,
					NULL
				} 
			}, .size = 1});
	LOG(L_INFO, "Hello World");

	Array_t arr;
	UNWRAP_TO_COMPLEX(array_init(int, 10), arr, Array_t);
	int b = 1;
	for(int i = 0; i < 20; i++) {
		unwrap(array_add(&arr, 0, &b));
		array_print(arr);
		b++;
	}
	Array_t sub;
	//array_for_each(arr, printer);
	//puts("");
	array_print(arr);
	UNWRAP_TO_COMPLEX(array_sub_array(arr, 5, 10), sub, Array_t);

	array_for_each(arr, printer);
	puts("");
	printf("%d\n", sub.used);
	array_for_each(sub, printer);
	puts("");

	array_destroy(&sub);
	array_destroy(&arr);

	cleanUp(E_SUCCESS);
}

