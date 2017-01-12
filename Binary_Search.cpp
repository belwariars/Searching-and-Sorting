// BINARY SEARCH...
// IT WILL USE RECCURSION TO SEARCH THE POSITION OF THE ELEMENT...
// TIME COMPLEXITY: O(log n)  SPACE COMPLEXITY :  NOT O(1) as it is recursion so, the stack used for recursion
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int start, int end)
{
	if(start > end)
	{
		int mid = (start+end)/2;
	
	if(key == arr[mid])
		return mid;
	else if(key < arr[mid])
	{
		return binarySearch(arr, key, start, mid-1);  // don't forget.. here also we're returning as when we'll get the result(key -- arr[mid]), then we've to return the mid element to the function...not to the recursion...in any program where we are traversing using recursion and we've to result the value in some condition, we'll use this only
	}
	else
	{
		return binarySearch(arr, key, mid+1, end);
	}
	}
	
	return -1;
}

int main()
{
	int arr[] = {1,3, 5, 6, 8, 9, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int pos = binarySearch(arr, 19, 0, n-1);
	printf("Position of searched element = %d", pos);
	return 0;
}
