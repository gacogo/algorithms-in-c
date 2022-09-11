#include "stack.h"
void stackpush(stack *s, int elem){
	//make sure there's space in our allocation
	//if not, double allocation from what was there before.
	if (s->stackpointer == s->alloclen){
		//printf("We have to ask for more memory\n");
		s->alloclen *=2 ;
		printf("it is %d\n", s->alloclen);
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
	printf("popping %d\n from the stack\n", s->elems[s->stackpointer]);
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
	printf("stackpointer is at %d\n", s->stackpointer);
	for(int i=0; i < (s->stackpointer); i++){
		*(address+i) = stackpop(s);
	}
}

int main(){

	stack s;
	stacknew(&s);
	int stack_items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 12, 21};
	for (int i=0; i<sizeof(stack_items)/sizeof(int); i++){
		stackpush(&s, stack_items[i]);
		printf("pushing %d\n", stack_items[i]);
	}
	stackprint(&s);
	int popped_items[sizeof(stack_items)/sizeof(int)]={0};
	pop_into_array(&s, popped_items);
	for(int i=0; i<(sizeof(popped_items)/sizeof(int)); i++){
		printf("array item %d is %d\n",i, popped_items[i]);
	}	
	stackdestroy(&s);
	return 0;
}
