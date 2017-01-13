// MERGE SORT...
// TIME COMPLEXITY: O(n logn)   SPACE COMPLEXITY: O(1), because, two temporary arrays L[] & R[] are created...
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
	int i,j,k;
	int n1 = mid-start+1; // AS IN MID, IT GETS TRUNCATED BY DIVIDING START+END/2...SO +1...
	int n2 = end-mid;
	
	int L[n1], R[n2];
	
	for(i=0; i<n1; i++)
	{
		L[i] = arr[start+i];
	}
	for(j=0; j<n2; j++)
	{
		R[j] = arr[mid+1+j]; // AS "mid+1" is 2nd part of array's starting point so, mid+1+j...
	}
	
	i=0;
	j=0;
	k=start;  // this is ALWAYS START NOT 0...Think why...
	
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while(j<n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int start, int end)
{
	if(start < end)
	{
		int mid = start + (end-start)/2; // FOR STOPPING OVERFLOW...
	//	int mid = (start + end)/2;
		
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
	int arr[] = {2, 5, 1, 6, 5, 9, 7, 10, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	mergesort(arr, 0, n-1);
	int i;
	
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
