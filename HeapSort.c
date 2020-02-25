#include <stdio.h>

int A[100], n, HS;

void MAXHeapify (int i)
{
	
	
	int largest;
	int l = 2*i;
	int r = 2*i + 1;
	
	if (l <= HS && A[l] > A[i])
		largest = l;
	else
		largest = i;
	
	if (r <= HS && A[r] >A[largest])
		largest = r;
	
	if (largest != i)
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		
		
		
		MAXHeapify (largest);
		
	}
	/*printf("In MaxHeap");
	for (int i=1; i <= n; i++)
	{
        printf ("%d \n", A[i]);
	}*/

}

void BuiltHeap ()
{
	HS = n;
	for (int i = n/2; i>=1; i--)
		MAXHeapify (i);
}

void HeapSort ()
{
	BuiltHeap ();
	HS = n;
	
	
	for (int i = n-1; i>=1; i--)
	{
		
		
		int temp = A[1];
		A[1] = A[HS];
		A[HS] = temp;
		
		HS--;
		
		
		
		MAXHeapify (1);
	}
}



int main ()
{
	
	
	
	//printf ("Enter Number of elements: \n");
    //scanf ("%d", &n);

    printf ("Enter all elements: \n");
    
    for (int i=1; i <= n; i++)
	{
        A[i] = 0;
		scanf ("%d", &A[i]);
	}

	HeapSort ();
	
	//printf ("Sorted array is: \n");
	
	for (int i=1; i <= n; i++)
	{
        printf ("%d \n", A[i]);
	}
	
	return 0;
}

    	