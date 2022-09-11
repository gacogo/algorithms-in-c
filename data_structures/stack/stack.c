#include "stack.h"
void stackpush(stack *s, int elem){
	//make sure there's space in our allocation
	//if not, double allocation from what was there before.
	if (s->stackpointer == s->alloclen){
		s->alloclen *=2 ;
		s->elems = realloc(s->elems, s->alloclen*sizeof(int));
		assert(s !=NULL);
	}
	s->elems[s->stackpointer] = elem;
	s->stackpointer++;
}


int stackpop(stack *s)
{	//make sure we have something in the stack;
	assert(s->stackpointer>0);
	s->stackpointer--;
	return s->elems[s->stackpointer];
}

void stacknew(stack *s){
	s->alloclen = 4;
	s->stackpointer = 0;
	s->elems = malloc(4*sizeof(int));
	assert(s->elems != NULL);
}

void stackdestroy(stack *s){
	assert(s->elems != NULL);
	free(s->elems);
}

void stackprint(stack *s){
	
	assert(s->elems !=NULL);
	int pointer = s->stackpointer;
	while(pointer >=0){
		printf("%d\n", s->elems[pointer]);
		pointer--;
	}
}

void pop_into_array(stack *s, int *address){
	int i=0;
	while(s->stackpointer>0){
		*(address+i) = stackpop(s);
	       i++;	
	}
}
int main(){

	stack s;
	stacknew(&s);
	int stack_items[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 101, 102, 130, 140, 150, 170, 120, 821};
	for (int i=0; i<sizeof(stack_items)/sizeof(int); i++){
		stackpush(&s, stack_items[i]);
		printf("pushing %d\n", stack_items[i]);
	}
	stackprint(&s);
	int popped_items[sizeof(stack_items)/sizeof(int)]={};
	pop_into_array(&s, popped_items);
	for(int i=0; i<(sizeof(popped_items)/sizeof(int)); i++){
		printf("array item %d is %d\n",i, popped_items[i]);
	}	
	stackdestroy(&s);
	return 0;
}
