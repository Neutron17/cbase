#include <stdlib.h>
#include <stdio.h>

#include "../src/arr.h"
#include "../src/error.h"

void foreachCB(void *data);

int main(int argc, char *argv[]) {
	Array_t arr; // int
	UNWRAP_TO_COMPLEX_FN(array_init(arenaInit(1000000*sizeof(int)), int, 1000000), arr, Array_t);
	for(int i = 0; i<1000000;i++) {
		except(array_push(&arr, i), "push failed");
	}
	//unwrap(array_for_each(arr, foreachCB));
	//array_print(arr);

	puts("");

	Array_t rangeArr;
	UNWRAP_TO_COMPLEX_FN(array_sub_array(pageAllocator(), arr, 342, 23414), rangeArr, Array_t);
	//unwrap(array_for_each(rangeArr, foreachCB));

	puts("");

	int ints[5] = { 1,2,3,4, 69 };
	array_append_simple(&rangeArr, ints, 4);
	//array_print(rangeArr);

	array_destroy(&arr);
	array_destroy(&rangeArr);
	return 0;
}

void foreachCB(void *data) {
	printf("%d\n", *(int *)data);
}
