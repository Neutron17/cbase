/************************
*  Lifetime functions	*
************************/
#ifndef _NTR_LT_H_
#define _NTR_LT_H_ 1

typedef void (*ltfunc_init)(void *, void *);
typedef void (*ltfunc_def)(void *);

struct LTHandler {
	ltfunc_init init;
	void *init_param[2];
	ltfunc_def defer;
	void *defer_param;
};

typedef struct LT {
	struct LTHandler *handlers;
	unsigned size;
} LT_t;

void init(LT_t lt);
__attribute__((noreturn))
void cleanUp(int ret);

#endif /* ifndef _NTR_LT_H_ */
