#include <stdio.h>

int Arr[100], N;



void exchangeNumbers(int i, int j)
{
	int t = Arr[i];
	Arr[i] = Arr[j];
	Arr[j] = t;

}

void partition (int l, int u)
	{
		int p = l;
		int q = u;
		
		int pivot = Arr[ l + (u-l)/2];
		
		while (p<=q)
		{
			while (Arr[p] < pivot)
			{
				p++;
			}
			
			while (Arr[q] > pivot)
			{
				q--;
			}
			
			if (p<=q)
			{
				exchangeNumbers(p,q);
				p++;
				q--;
			}
			
			if (l < q)
				partition(l, q);
			if (p < u)
				partition (p, u);
		}
		
		
	}
void sort (int Arr[], int n)
	{
        
		
		if (Arr == NULL || n == 0)
		{
			return;
		}
		

		partition (0, n-1);
	}
	

	
	

int main ()
{
	int n;
	
	printf ("Enter number of elements: \n");
	scanf ("%d", &n);
	
	printf ("Enter all elements: \n");
	
	for (int i=0; i<n; i++)
	{
	    scanf ("%d", &Arr[i]);
	}
	
	sort (Arr, n);
	
	printf("Sorted Array is: \n");
	
	for (int j=0; j<n; j++)
	{
		printf("%d \n", Arr[j]);
	}
	
	return 0;
}

