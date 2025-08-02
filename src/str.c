#include "str.h"
#include <string.h>

String nstrSlice(String str, int start, int end);
int nstrcmp(String a, String b) {
	if(a.len != b.len)
		return b.len-a.len;
	return memcmp(a.bytes, b.bytes, a.len);
}
String nstrJoin(Array_t strs, String delim);
String nstrJoin_c(Array_t strs, const char *delim);
String nstrFilter(String str, strCondFn fn);

String nstrTake(String str, int n);
String nstrTakeIf(String str, strCondFn fn);
String nstrTakeWhile(String, strCondFn fn);
String nstrDrop(String str, int n);
String nstrDropIf(String str, strCondFn fn);
String nstrDropWhile(String str, strCondFn fn);
