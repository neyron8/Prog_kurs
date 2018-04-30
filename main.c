#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
 
int main(int argc, char *argv[])
{

	if (argc != 3){
		printf("Not enough arguments\n");
		return 2;
	}

	int sum = 0, num = my_atoi(argv[2], sum);
	int *array = malloc( sizeof(int) * num);
	int i, flag = 1, helper;
	if (num < 1){
		printf("Incorrect value\n");
		return 2;
	}
    
	helper = num;
	printf("Unsorted:\n");
	for ( i = 0; i < num; ++i ){
		array[i] = helper;
		helper --;
		//array[i] = i;
		//array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	if ((same_string (argv[1], "heap")) == 0){  
		flag = 0;  
		heap_sort(array, num);
    	printf("\nSorted by Heap Sort:\n");
		for ( i = 0; i < num; ++i ){
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	if ((same_string (argv[1], "insert")) == 0){ 
		flag = 0;   
		insert_sort(array, num);
    	printf("\nSorted by Insertion Sort:\n");
		for ( i = 0; i < num; ++i ){
			//printf("%d ", array[i]);
		}
		printf("\n");
	}

	if (flag == 1) {
		printf("\nIncorrect argument\n");
		free(array);
		array = NULL;
		return -2;
	}

	free(array);
	array = NULL;
	
	return 0;
}
