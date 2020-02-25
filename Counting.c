#include <stdio.h>

int A[100], B[100], C[100];
int n;

/*int MaxElement(int n)
{
	
	return Max;
}

int Sort(int n)
{
	
	
    
}

void Print(int C[], int n)
{
	
}*/
	

	
		
int main ()
{
	
	
	
	printf ("Enter Number of elements: \n");
	scanf ("%d", &n);
	
	printf ("Enter all Elements: \n");
	
	for (int i=1; i<=n; i++)
	{
		scanf ("%d", &A[i]);
	}
	
	
	int Min=0;
	
	for (int i=1; i<=n; i++)
	{
		if (Min > A[i])
		{
			Min = A[i];
			
		}
		
	}
	
	if (Min < 0)
	{
		for (int i=1; i<=n; i++)
        {
            A[i] = A[i]-Min+1;
		}
	}

	
	int Max=0;
	
	for (int i=1; i<=n; i++)
	{
		if (Max < A[i])
		{
			Max = A[i];
			
		}
		
	}
	
	
	
	
	int M = Max;
	
	for (int i=1; i<=M; i++)
	    C[i] = 0;

    for (int j=0; j<=n; j++)
        C[A[j]] = C[A[j]] + 1;
	
	for (int k=2; k<=M; k++)
		C[k] = C[k-1] + C[k];
	
	for (int m=n; m>=1; m--)
	{	
	    B[C[A[m]]] = A[m];
	    C[A[m]] --;
	}
	
	
	printf ("Sorted Array is: \n");
	if (Min < 0)
	{
		for (int i=1; i<=n; i++)
	    {
		    B[i] = B[i]+Min-1;
			printf ("%d \n", B[i]);
					
		}
	}
		
	
	
	
	else
	{
		for (int i=1; i<=n; i++)
	    {
		    printf ("%d \n", B[i]);
	    }
	}
	
	
	
	return 0;
	
}
	
	
	