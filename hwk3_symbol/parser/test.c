#include <stdlib.h>
#include <stdio.h>

int *array;
int size=1;

int main() {
	
	array = calloc(size, sizeof(int));

	array = realloc(array,sizeof(int)*size*2);

	array = realloc(array, sizeof(int)*size*100);

	return 0;
}