#include <stdio.h>

int A[100],M[100], N[100], n;

void Merge (int P, int Q, int R)
{
	int m1, m2, i, j, k;
	
	m1 = Q-P+1;
	m2 = R-Q;
	
	for ( int i=1; i<=m1; i++)
		M[i] = A[P+i-1];
	
	for ( int j=1; j<=m2; j++)
		N[j] = A[Q+j];
	
	k = P;
	i = 1;
	j = 1;
	
	while (i<=m1 && j<=m2)
	{
		if (M[i] < N[j])
		{
			A[k] = M[i];
			k++;
			i++;
		}
		
		else 
		{
			A[k] = N[j];
			k++;
			j++;
		}
	}
	
	while (i <= m1)
	{
		A[k] = M[i];
		k++;
		i++;
	}
	
	while (j <= m2)
	{
		A[k] = N[j];
		k++;
		j++;
	}
}


void MergeSort (int P, int R)
{
	int Q;
	
	if (P<R)
	{
		Q = (P+R)/2;
		
		MergeSort (P,Q);
		MergeSort (Q+1, R);
		Merge (P,Q,R);
	}
}



int main()
{
	printf ("Enter number of elements: \n");
	scanf ("%d", &n);
	
	printf ("Enter all elements: \n");
	
	
	for (int i=1; i<=n; i++)
	{
		scanf ("%d", &A[i]);
	}
	
	MergeSort (1, n);
	
	printf ("Sorted Array is: \n");
	
	for (int j=1; j<=n; j++)
	{
		printf ("%d \n",A[j]);
	}

	return 0;
	
}