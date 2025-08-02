#include <stdlib.h>
#include <stdio.h>

#include "../src/arr.h"
#include "../src/error.h"
#include "../src/str.h"

int main(int argc, char *argv[]) {
	Array_t strArr;
	UNWRAP_TO_COMPLEX_FN(array_init(String, 4), strArr, Array_t);

	String a = NSTR("Hello");
	String b = NSTR("World");

	array_push(&strArr, a);
	array_push(&strArr, b);

	printf("%s\n", nstrJoin(strArr, NSTR(" ")).bytes);

	array_destroy(&strArr);
	return 0;
}
