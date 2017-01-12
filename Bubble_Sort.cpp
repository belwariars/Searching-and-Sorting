// BUBBLE SORT...
// IT BUBBLES OUT THE MAXIMUM OF THE UNSORTED ARRAY TO LAST AND CONTINUE LOOP TILL LAST-1 ELEMENT...
// TIME COMPLEXITY: O(n^2)   SPACE COMPLEXITY: O(1)
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n)
{
	int i,j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main()
{
	int arr[] = {4, 2, 6, 2, 8, 5, 1, 10, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr, n);
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
