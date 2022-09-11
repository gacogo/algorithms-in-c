#include "stack.c"
/*************
 * using stack to reverse an array of integers
 * ****************************************
 */


/*********
 * given an array of integers and the size of the array
 * print the element in reverse order
 * ex;
 * int arr[] = {1, 2, 3, 4,5};
 * reversed(arr,5) 
 * {5, 4, 3, 2, 1}
 * */
void printreversed(int *items, int number){
	stack rev;
	stacknew(&rev);
	int *reversed = malloc(number*sizeof(int));
	
	for(int i=0; i<number; i++)
	stackpush(&rev, *(items+i));
	
	stackprint(&rev);
}

