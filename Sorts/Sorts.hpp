#ifndef SORTS_HPP
#define SORTS_HPP
#include <iostream>
#include <algorithm>
using namespace std;
class Sorts
{
public:
	void bubble(int*, int);
	void insertion(int*, int);
	void quick(int*, int);
	void quick(int* &, int , int);
	int partitions(int*, int, int, int);
	int findPivot(int*, int, int, int);

private:

};

void Sorts::bubble(int* head, int quant)
{
	int j = 0;
	while (j <= quant)
	{
		for (int i = 0; i < (quant - 1); i++)
		{
			int temp = 0;

			if (head[i] > head[i + 1])
				swap(head[i], head[i + 1]);
		}
		j++;
	}

}

void Sorts::insertion(int* head, int quant)
{
	int pivot = 0, pos = 0;

	for (int i = 1; i < quant; i++) 
	{
		pivot = head[i];
		pos = i;

		while (pos > 0 && head[pos - 1] > pivot) 
		{
			head[pos] = head[pos - 1];
			pos--;
		}

		head[pos] = pivot;   
	}
}


void Sorts::quick(int* head, int quant)
{
	quick(head, 0, quant);
}

void Sorts::quick(int* &head, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		int pivot = findPivot(head, left, mid, right);
		int part = partitions(head, left, right, pivot);

		quick(head, left, part - 1);
		quick(head, part + 1, right);
	}
}

int Sorts::partitions(int* head, int left, int right, int pivot)
{
	int temp = (left - 1); 

	for (int j = left; j <= right - 1; j++)
	{
		if (head[j] < pivot)
		{
			temp++; 
			swap(head[temp], head[j]);
		}
	}

	swap(head[temp + 1], head[right]);
	return (temp + 1);
}

int Sorts::findPivot(int * head, int low, int mid, int high)
{
	int pivot;

	if (head[low] >= head[mid])
	{
		if (head[low] <= head[high])
		{
			pivot = head[low];
			swap(head[high], head[low]);
		}
		else
		{
			if (head[mid] > head[high])
			{
				pivot = head[mid];
				swap(head[high], head[mid]);
			}
			else
				pivot = head[high];
		}
	}
	else
	{
		if (head[mid] < head[high])
		{
			pivot = head[mid];
			swap(head[high], head[mid]);
		}
		else
		{
			if (head[low] > head[high])
			{
				pivot = head[low];
				swap(head[high], head[low]);
			}
			else
				pivot = head[high];
		}
	}

	return pivot;
}
#endif
