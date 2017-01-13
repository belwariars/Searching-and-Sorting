//QUICK SORT...
// CHOOSE A PIVOT (HERE THE LAST ELEMENT OF THE ARRAY) AND COMPAE IT WITH ALL THE VALUES FROM START...IF LESS OF EQUAL, SWAP IT...
// TIME COMPLEXITY: O(n logn) in avg.  BUT O(n^2) in worst case...which is when tree is skewed.  Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int start, int end)
{
	int i = start-1;
	int pivot = arr[end];
	int j;
	
	for(j=start; j<end; j++)
	{
		if(arr[j] <= pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	
	swap(&arr[i+1], &arr[end]);
	i++;
	return i;
}

void quicksort(int arr[], int start, int end)
{
	if(start < end)
	{
		int p = partition(arr, start, end);
		
		quicksort(arr, start, p-1);
		quicksort(arr, p+1, end);
	}
}

int main()
{
	int arr[] = {4, 2, 7, 1, 2, 9, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	quicksort(arr, 0, n-1);
	int i;
	
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
