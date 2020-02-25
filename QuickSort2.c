#include <stdio.h>

int A[100], n;

int Partition (int P, int R)
{
	int x, i;
	
	x = A[R];
	i = P-1;
	
	for (int j=P; j<=R-1; j++)
	{
		if (A[j] <= x)
		{	i++;
		
		    int temp;
		    temp = A[i];
		    A[i] = A[j];
		    A[j] = temp;
		}
		
	}
	
	int temp1;
	temp1 = A[i+1];
	A[i+1] = A[R];
	A[R] = temp1;
	
	return i+1;
	
}

void QuickSort (int P, int R)
{
	int Q;
	
	if (P<R)
	{
		Q = Partition (P,R);
		QuickSort (P,Q-1);
		QuickSort (Q+1,R);
	}
}

int main()
{
	int i, j;
	
	printf ("Enter Number of Elements: \n");
	scanf ("%d", &n);
	
	printf ("Enter all Elements: \n");
	
	for (i=1; i<=n; i++)
	{
		scanf ("%d", &A[i]);
	}
	
	QuickSort(1, n);
	
	printf ("Sorted Array is: \n");
	
	for (j=1; j<=n; j++)
	{
		printf("%d \n", A[j]);
	}
	
	return 0;
	
}