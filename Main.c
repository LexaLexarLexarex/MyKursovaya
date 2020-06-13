#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"
#include "tests.h"

#define SIZEBIG 100000000
enum TEST {
	test1 = 1, test2, test3, test4, test5, test6, test7, test8, test9, test10
};

int main() {
	srand(time(0));
	int size, SIZE = 100000;
	int* array;
	array = (int*)malloc(SIZEBIG * sizeof(int));
	for(int iteration = 0; iteration < 15; iteration++)
	{
		if (iteration > 4 && iteration < 11)
			SIZE = 1000000;
		else if (iteration > 10)
			SIZE = 10000000;
		printf("Number of Elements:\nFor Selection, Insertion, Bubble sorts - %d\nFor Merge, Bucket, Quick sorts - %d\n\n", SIZE / 100, SIZE);
		PrintTable();
		for (int i = 0; i < 6; i++) 
		{
			PrintNameSort(i);
			if (i < 3) 
				size = SIZE / 100;
			else 
				size = SIZE;
			SortTests(array, size);
			Benchmark(i, array, test1, size);	
			SelectBadTests(array, size);
			Benchmark(i, array, test2, size);	
			BubbleBadTests(array, size);
			Benchmark(i, array, test3, size);
			InsertBadTests(array, size);
			Benchmark(i, array, test4, size);
			QuickBadTests(array, size);
			Benchmark(i, array, test5, size);
			SwapTests(array, size);
			Benchmark(i, array, test6, size);
			RandTests(array, size);
			Benchmark(i, array, test7, size);
			MiniSortTests(array, size);
			Benchmark(i, array, test8, size);
			RepeatUnrandSortTests(array, size);
			Benchmark(i, array, test9, size);
			RepeatRandSortTests(array, size);
			Benchmark(i, array, test10, size);
			printf("\n");
		}
		printf("\n\n");
	}
	return 0;
}