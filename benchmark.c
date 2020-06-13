#include <stdio.h>
#include <time.h>
#include "benchmark.h"
#include "sorting.h"

TIMER clockk;

enum SORT_NAME {
	select = 0, insert, bubble, merge, bucket, quick
};

void PrintTable() {
	printf("\t\t\t\t\t\t\x1B[30;1mTIME ON\n");
	printf("SORT NAME");
	printf("\t\tTest 1");
	printf("\tTest 2");
	printf("\tTest 3");
	printf("\tTest 4");
	printf("\tTest 5");
	printf("\tTest 6");
	printf("\tTest 7");
	printf("\tTest 8");
	printf("\tTest 9");
	printf("\tTest 10");
	printf("\n---------------------------------------------------------");
	printf("---------------------------------------------------\n\033[0m");
}

void PrintNameSort(int sort_name) {
	char* name_sort[6] = { "Selection sort", "Insertion sort", "Bubble sort   ", "Merge sort    ", "Bucket sort ", "Quick sort    " };
	printf("\x1B[32;1m%s\033[0m\t\t", name_sort[sort_name]);
}

void PrintTimeData(const TIMER* t, int sort, int data) {
	double time = t->finish - t->start;
	time = (time / CLOCKS_PER_SEC) * 1000;
	if (data == 1) printf("\x1B[33m%.0f ", time);
	if (data == 2) printf("\x1B[35m%.0f ", time);
	if (data == 3) printf("\x1B[34m%.0f ", time);
	if (data == 4) printf("\x1B[31m%.0f ", time);
	if (data == 5) printf("\x1B[36m%.0f ", time);
	if (data == 6) printf("\x1B[33m%.0f ", time);
	if (data == 7) printf("\x1B[35m%.0f ", time);
	if (data == 8) printf("\x1B[34m%.0f ", time);
	if (data == 9) printf("\x1B[31m%.0f ", time);
	if (data == 10) printf("\x1B[36m%.0f ", time);
	printf("ms\033[0m");
	if (time < 10000) printf("\t");
	else printf("");
}

void Benchmark(int sort_name, int* array, int data, int size) {
	switch (sort_name) {
	case select:
		clockk.start = clock();
		SelectionSort(size, array);
		clockk.finish = clock();
		break;

	case insert:
		clockk.start = clock();
		InsertionSort(size, array);
		clockk.finish = clock();
		break;

	case bubble:
		clockk.start = clock();
		BubbleSort(size, array);
		clockk.finish = clock();
		break;

	case merge:
		clockk.start = clock();
		MergeSort(array, 0, size - 1);
		clockk.finish = clock();
		break;

	case bucket:
		clockk.start = clock();
		BucketSort(array, size);
		clockk.finish = clock();
		break;

	case quick:
		clockk.start = clock();
		QuickSort(array, 0, size - 1);
		clockk.finish = clock();
		break;

	default:
		break;
	}
	PrintTimeData(&clockk, sort_name, data);
}