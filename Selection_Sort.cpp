// SELECTION SORT...
// Here, in every loop it is going to find the minimum element and is going to swap the minimum element with the unsorted partof the array..and then again loop will start from unsorted part of array
// TIME COMPLEXITY: O(n^2)   SPACE COMPLEXITY: O(1)

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n)
{
	int i,j, min, minIndex;
	
	for(i=0; i<n-1; i++)
	{
		min = arr[i];
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}
		
		swap(&arr[i], &arr[minIndex]);
	}
}

int main()
{
	int arr[] = {4, 5,1, 3, 2, 8, 7, 6, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr, n);
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
