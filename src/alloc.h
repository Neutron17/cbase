#ifndef _NTR_ALLOC_H_
#define _NTR_ALLOC_H_ 1
#include <stddef.h>

typedef struct Alloc_t {
	long size;
	long used;
	void *memory;

	void *(*alloc)(struct Alloc_t *, size_t);
	void *(*calloc)(struct Alloc_t *, size_t,size_t);
	void (*free)(struct Alloc_t *, void *);
} Allocator;

Allocator pageAllocator();
Allocator arenaInit(size_t size);
Allocator fixedBuffInit(size_t size, void *buff);

#endif /* ifndef _NTR_ALLOC_H_ 1 */

