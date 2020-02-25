#include <stdio.h>
#include <stdlib.h>

int A[100], Top = -1, Size;

void Push (int a, int Size)
{
	if (Top >= Size-1)
	{
		printf ("Stack is Full. \n");
	}
	
	else
	{
		
		Top++;
		A[Top] = a;
		
	}
	
}

void Pop ()
{
	if (Top <= -1)
	{
		printf ("Stack is empty. \n");
	}
	else
	{
		printf ("Pushed element is %d. \n", A[Top]);
		Top--;
	}
	
}

void Print ()
{
	int i;
	
	
	
	if ( Top == -1)
	{
		printf ("Stack is empty. \n");
	}
	else
	{
	    printf ("Stack: \n");
		
		for (i=0; i <= Top; i++)
	    {
		   printf ("%d \n", A[i]);
	    }
	}
}

int main()
{
	int n, a, Size;
	
	printf ("Enter the MAX size of the stack:");
	scanf ("%d", &Size);
	
	while (1)
	{
		printf ("Enter Choice: \n");
		printf (" 1.To push. \n 2.To pop. \n 3.To print all elements. \n 4.Exit. \n");
		
		scanf ("%d", &n);
		
		if (n == 1)
		{
			printf ("Enter element you want to insert:");
			scanf ("%d", &a);
			Push(a, Size);
		}
		
		else if (n == 2)
		{
			Pop();
		}
		
		else if (n == 3)
		{
			Print();
		}
		
		else if (n == 4)
		break;
	}
	
	return 0;
	
}
	
	
		