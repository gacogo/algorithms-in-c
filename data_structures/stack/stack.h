#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef struct{

	int *elems;
	int alloclen;
	int stackpointer;
}stack;

void stacknew(stack *s);
void stackpush(stack *s, int elem);
void stackprint(stack *s);
