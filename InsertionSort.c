#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[100], n, i, j, k, key;
	
	printf ("Enter no. of elements:\n");
	scanf ("%d", &n);
	
	printf ("Enter all elements: \n");
	
	for (i=0; i<n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for (j=1; j<n; j++)
	{
		key = A[j];
		printf ("%d \n", key);
		
		for (k=j-1; k>=0 && A[k]>key; k--)
		{
			A[k+1] = A[k];
		}
		
		A[k+1] = key;
	}
	
	printf ("Sorted array is: \n");
	
	for (int m=0; m<n; m++)
	{
		printf ("%d \n", A[m]);
	}
	
	return 0;
}
		
	