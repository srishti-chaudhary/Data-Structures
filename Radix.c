#include <stdio.h>
#include <math.h>

int A[100], R[100][100];
int n, d, Max;

int Maximum()
{
	int Max=0;
	
	for (int k=1; k<=n; k++)
	{
		if (Max < A[k])
		{
			Max = A[k];
			
		}
		
	}
	
	return Max;
}

void Sort (int i)
{
	
	
	int M = Max;
	int temp,m,x;
	
	for(m=1;m<=n;m++)
	{
		for(x=1; x<=n-m; x++)
		{	if(R[i][x] > R[i][x+1])
		    {   temp=A[x];
				A[x]=A[x+1];
				A[x+1]=temp;
				
				temp=R[i][x];
				R[i][x]=R[i][x+1];
				R[i][x+1]=temp;
		    }
		}
}
	
	
}

int Digit()
{
	
	int M = Maximum();
	
	d=0;
	int remainder;
	
	while (M != 0)
    {
        d ++;
		remainder = M%10;
        M /= 10;
		
	}
	
	return d;
}

void Array(int i)
{
	
	for (int r=1; r<=n; r++)
	{
		int p,div;
		
		p = pow(10,i-1);
		div = (A[r]/p);
		
		R[i][r] = (div)%10;
		
		
		
	}
	
}

void RadixSort()
{
	d = Digit();
	
	
	for (int i=1; i<=d; i++)
	{
		Array(i);
		Sort(i);
	}
	
}

void Print ()
{
	printf ("Sorted Array is: \n");
	
	for (int i=1; i<=n; i++)
	{
		printf ("%d \n", A[i]);
	}
	
}

int main ()
{
	printf ("Enter Number of elements: \n");
	scanf ("%d", &n);
	
	printf ("Enter all Elements: \n");
	
	for (int i=1; i<=n; i++)
	{
		scanf ("%d", &A[i]);
	}
	
	RadixSort();
	Print ();
	
	return 0;
}