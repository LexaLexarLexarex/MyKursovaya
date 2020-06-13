#include <stdlib.h>
#include <stdio.h>
#include "tests.h"


void SortTests(int* array, int size)
{
	int now = 0;
	for (int i = 0; i < size; i++)
	{
		array[i] = now + rand() % (size / 10) + 1;
		now = array[i];
	}
}


//InsertionSort
void InsertBadTests(int* array, int size)
{
	int k;
	SortTests(array, size);
	for (int i = 0; i < size / 2; i++)
		array[size - i] = array[i];
}

//Selectionsort
void SelectBadTests(int* array, int size)
{
	int k;
	SortTests(array, size);
	k = array[0];
	for (int i = 0; i < size - 1; i++) 
		array[i] = array[i + 1];
	array[size] = k;
}

//Bubblesort
void BubbleBadTests(int* array, int size)
{
	int now = 0;
	for(int i = size-1; i>=0; i--)
	{
		array[i] = now + rand() % (size / 10) + 1;
		now = array[i];
	}
}

//Quicksort
void QuickBadTests(int* array, int size)
{
	SortTests(array, size);
	int even = 0;
	int* a;
	a = (int*)malloc((size) * sizeof(int));
	int odd = size - 1;
	for (int i = 0; i < size; i++)
		a[i] = array[i];
	for (int i = 0; i <= size - 1; i++)
	{
		if ((i % 2) == 1)
		{
			array[even] = a[i];
			even++;
		}
		else
		{
			array[odd] = a[i];
			odd--;
		}
	}
}

//SwapTests
void SwapTests(int* array, int size)
{
	int now = 0, k;
	int NW = rand() % 100 + 2;
	for (int i = 0; i < size; i++)
	{
		if (NW == 0)
		{
			k = array[i - 1];
			array[i - 1] = array[i - 2];
			array[i - 2] = array[i - 1];
			NW = rand() % 100;
		}
		else NW--;
		array[i] = now + rand() % (size / 10) + 1;
		now = array[i];
	}
}

//RandTests
void RandTests(int* array, int size)
{
	for (int i = 0; i < size; i++) array[i] = rand() % size;
}

//MiniSort
void MiniSortTests(int* array, int size)
{
	int k = 0, value = 0;
	for (int i = 0; i < size;)
	{
		k = rand() % (size / 1000) + 2;
		if (i + k > size)
			k = size - i;
		i = i + k;
		for (int j = 0; j < k; j++)
		{
			value = value + rand() % size;
			array[i - k + j] = value;
		}
		k = 0;
		value = 0;
	}
}

//RepeatUnrand
void RepeatUnrandSortTests(int* array, int size)
{
	int NW = rand() % (size / 1000), repeat;
	array[0] = rand() % (size / 100);
	int j;
	for (int i = 0; i < size; i++)
	{
		if (NW == 0)
		{
			repeat = rand() % 100 + 1;
			for (j = 0; j < repeat; j++) {
				array[i] = array[i - 1];
			}
			i = i + j;
			NW = rand() % (size / 1000);
			continue;
		}
		NW--;
		array[i] = array[i - 1] + rand() % (size / 100);
	}
}

//repeatSort
void RepeatRandSortTests(int* array, int size)
{
	int NW = rand() % (size / 1000), repeat;
	array[0] = rand() % (size / 100);
	int j;
	for (int i = 0; i < size; i++)
	{
		if (NW == 0)
		{
			repeat = rand() % 100 + 1;
			for (j = 0; j < repeat; j++) {
				array[i] = array[i - 1];
			}
			i = i + j;
			NW = rand() % (size / 1000);
			continue;
		}
		NW--;
		array[i] =rand() % size;
	}
}
