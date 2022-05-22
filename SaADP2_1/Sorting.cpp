#include <iostream>
#include "Sorting.h"
#include "Interface.h"

using namespace std;

int randomNumber() { return MinNumber + rand() % (MaxNumber - MinNumber + 1); }

void fillArray(int* currentArray, int size)
{ 
	for (int cell = 0; cell < size; cell++) { currentArray[cell] = randomNumber(); }
}

void duplicateArray(int* mainArray, int* auxArray, int size)
{
	for (int cell = 0; cell < size; cell++) { auxArray[cell] = mainArray[cell]; }
}

void bubbleSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int temporary;
	for (int i = 1; i < size; i++)
	{
		for (int j = size - 1; j >= i; j--)
		{
			if (auxArray[j - 1] > auxArray[j])
			{
				temporary = auxArray[j - 1];
				auxArray[j - 1] = auxArray[j];
				auxArray[j] = temporary;
				countExchanges++;
			}
			countCompares++;
		}
	}
}

void selectionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int min = 0;
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			min = i;
			countCompares++;
			if (auxArray[j] < auxArray[min])
			{
				min = j;
			}
			if (i != min)
			{
				temp = auxArray[i];
				auxArray[i] = auxArray[min];
				auxArray[min] = temp;
				countExchanges++;
			}
		}
	}
}

void insertionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		while ((++countCompares) && j >= 0 && auxArray[i] < auxArray[j])
		{
			j = j - 1;

		}
		if (j + 1 != i)
		{
			int temporary = auxArray[i]; int l = i - 1;
			while (l >= j + 1)
			{
				auxArray[l + 1] = auxArray[l]; l--;
			}
			auxArray[j + 1] = temporary;
			countExchanges++;
		}
	}
}

void show(int* currentArray, int size)
{
	for (int cell = 0; cell < size; cell++) 
	{
		if (cell % 30 == 0) { cout << "\n"; }
		cout << currentArray[cell] << " "; 
	}
}

void clearMemory(int* currentArray)
{
	delete[] currentArray;
	currentArray = nullptr;
}
