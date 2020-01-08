#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	int n;
	int *rocks;
	int value;

	srand(time(NULL));
	n = rand() % 90 + 10;
	rocks = createRandomArray(n);
	if (rand() % 2)
		value = rand() % 30;
	else
		value = rocks[rand() % n];

	/*-------------------
	launch your test here
	--------------------*/
	printArray(rocks, n);
	printf("Value %d at index %d\n", value, searchShifted(rocks, n, value));

	printf("\n");
	int	n1 = 27;
	int arr1[27] = {20,21,21,21,21,1,1,3,3,4,4,8,8,8,8,8,8,8,8,12,14,17,17,17,20,20,20};
	printArray(arr1, n1);
	printf("Value %d at index %d\n", 21, searchShifted(arr1, n1, 21));

	printf("\n");
	int n2 = 56;
	int arr2[56] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,
		8,8,8,8,8,8,8,8,8,12,12,13,13,13,13,13,13,15,15,17,20,20,
		20,20,20,20,20,20,20,20,20,20,20,20,20,20,1,4};
	printArray(arr2, n2);
	printf("Value %d at index %d\n", 17, searchShifted(arr2, n2, 17));

	printf("\n");
	int n3= 54;
	int arr3[54] = {9,9,9,13,13,13,13,13,13,13,13,15,15,15,15,15,15,15,15,15,
		19,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
	printArray(arr3, n3);
	printf("Value %d at index %d\n", 15, searchShifted(arr3, n3, 15));

}



// Function used for the test
// Don't go further :)

int *createRandomArray(int n) {
	int *arr, *arrShifted;
	int shift;
	int value = 1;

	if (!(arr = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	for (int i = 0; i < n; i++) {
		if (rand() % 5 == 0)
			value += rand() % 5;
		arr[i] = value;
	}
	if (!(arrShifted = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	shift = rand() % 100;
	for (int i = 0; i < n; i++) {
		arrShifted[i] = arr[(i + shift) % n];
	}
	free(arr);
	return (arrShifted);
}

void printArray(int *arr, int n) {
	printf("Rocks (%d): ", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
