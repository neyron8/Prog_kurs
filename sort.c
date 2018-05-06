#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "sort.h"
 
void swap(int * array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
 
void heap_it(int *array, int length, int root)
{

    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int biggest = root;
    
    if ( left < length && array[root] < array[left] )
        biggest = left;
    if ( right < length && array[biggest] < array[right] )
        biggest = right;
    if ( biggest != root ) {
        swap(array, biggest, root);
        heap_it(array, length, biggest);
    }
}
 
void make_heap(int * array, int length)
{

    int i = length / 2 - 1;
 
    for ( ; i >= 0; --i )
        heap_it(array, length, i);
}
 
void heap_sort(int * array, int elements)
{

    int end;
    
    make_heap(array, elements);
    for ( end = elements - 1; end > 0; --end ) {
        swap(array, 0, end);
        heap_it(array, end, 0);
    }
}

int my_atoi(char *str, int sum)
{

	if (*str == '\0') {
		return sum;
	}
    if ((*str <= 'Z' && *str >= 'A') ||((*str <= 'z' && *str >= 'a'))) {
        printf("ERROR INPUT\n");
		exit(2);
	}
	sum = sum + (*str - 48) * pow(10, slen(str) - 1);
	str = str + 1;
	return my_atoi(str, sum);
}

void line(int count)
{

   int i;
	
   for(i = 0;i < count-1;i++) {
      printf("=");
   }
	
   printf("=\n");
}

int same_string(char *first, char *second)
{

	int i = 0, flag;
	
	for (i; i < slen(first); i++) {

		if (first[i] == second[i]) {

			flag = 0;

		} else {

        	flag = 1;
			return 2;

		}
	}
	if (flag == 0){
		return 0;
	}
}

int slen(char *c)
{

	int i = 0;
	for (i; c[i] != NULL; i++);

	return i;

}

int insert_sort (int *array, int count)
{
	int insert, i, tmp;
	for (i = 1; i <= count - 1; i++) {
		insert = i;

		while (insert > 0 && array[insert] < array[insert - 1]) {

			tmp = array[insert];
			array[insert] = array[insert - 1];
			array[insert - 1] = tmp;

			insert--;

		}
	}
	return 0;
}

