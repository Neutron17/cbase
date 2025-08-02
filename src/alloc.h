#ifndef _NTR_ALLOC_H_
#define _NTR_ALLOC_H_ 1
#include <stddef.h>

typedef struct Alloc_t {
	size_t size;
	size_t used;
	void *memory;

	void *(*alloc)(struct Alloc_t *, size_t) __attribute__ ((alloc_size (2)));
	void *(*calloc)(struct Alloc_t *, size_t,size_t) __attribute__ ((alloc_size (2, 3)));
	void *(*realloc)(struct Alloc_t *,void *,size_t) __attribute__ ((alloc_size (3)));
	void (*free)(struct Alloc_t *, void *,size_t);
} Allocator;

Allocator pageAllocator();
Allocator arenaInit(size_t size);
Allocator fixedBuffInit(size_t size, void *buff);

#endif /* ifndef _NTR_ALLOC_H_ 1 */

