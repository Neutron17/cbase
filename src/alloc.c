#include "alloc.h"
#include <stdlib.h>
#include <string.h>

void *pageAlloc(Allocator *a, size_t s) {
	return malloc(s);
}
void *pageCalloc(Allocator *a, size_t n,size_t s) {
	return calloc(n,s);
}
void pageFree(Allocator *a, void *ptr) {
	free(ptr);
}

Allocator pageAllocator() {
	return (Allocator){
		.alloc=pageAlloc,
		.calloc=pageCalloc,
		.free=pageFree
	};
}


void *arenaAlloc(Allocator *a, size_t size) {
	a->used+=size;
	if(a->used > a->size)
		return NULL;
	return a->memory+a->used-size;
}
void *arenaCalloc(Allocator *a, size_t n, size_t size) {
	a->used += size;
	if(a->used > a->size)
		return NULL;
	memset(a->memory+a->used, 0, size);
	return a->memory+a->used-size;
}
void arenaFree(Allocator *a, void *ptr) {
	return;
}

Allocator arenaInit(size_t size) {
	Allocator ret = {
		.size = size,
		.memory = malloc(size),
		.alloc = arenaAlloc,
		.calloc = arenaCalloc,
		.free = arenaFree
	};

	return ret;
}


void *fixedBuffAlloc(Allocator *a, size_t size) {
	a->used+=size;
	if(a->used > a->size)
		return NULL;
	return a->memory+a->used-size;
}
void *fixedBuffCalloc(Allocator *a, size_t n, size_t size) {
	a->used += size;
	if(a->used > a->size)
		return NULL;
	memset(a->memory+a->used, 0, size);
	return a->memory+a->used-size;
}
void fixedBuffFree(Allocator *a,void *ptr) {
	return;
}

Allocator fixedBuffInit(size_t size, void *buff) {
	Allocator ret = {
		.size = size,
		.memory = buff,
		.alloc = fixedBuffAlloc,
		.calloc = fixedBuffCalloc,
		.free = fixedBuffFree
	};

	return ret;
}

