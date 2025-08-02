#ifndef _NTR_STR_H_
#define _NTR_STR_H_ 1
#include "arr.h"

typedef struct {
	/** Null-terminated string */
	const char *bytes;
	/** Number of chars (without null) */
	unsigned long len;
} String;

#define NSTR(A) ((String) { .bytes=(A), .len=strlen((A)) })

typedef bool (*strCondFn)(char);

String nstrSlice(String str, int start, int end);
int nstrcmp(String a, String b);
String nstrJoin(Array_t strs, String delim);
String nstrJoin_c(Array_t strs, const char *delim);
String nstrFilter(String str, strCondFn fn);

String nstrTake(String str, int n);
String nstrTakeIf(String str, strCondFn fn);
String nstrTakeWhile(String, strCondFn fn);
String nstrDrop(String str, int n);
String nstrDropIf(String str, strCondFn fn);
String nstrDropWhile(String str, strCondFn fn);

#endif /* ifndef _NTR_STR_H_ */

