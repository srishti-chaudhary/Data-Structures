#include <stdio.h>
#include <stdlib.h>

int A[100], B[100], Top1 = -1, Top2 = -1, Size, Element;

void Enqueue (int a, int Size)
{
	if (Top1 >= Size-1)
		printf ("Queue is Full.\n ");
	
	else
	{
		Top1 ++;
		A[Top1] = a;
	}
	
	for (int i = 0; i <= Top1; i++)
			printf (" %d \n" , A[i]);
	
}

int Dequeue ()
{
	if (Top1 <= -1 && Top2 <= -1)
		printf ("Queue is Empty. \n");
	
	else
	{
		while (Top1 != -1)
		{
			Top2 ++;
			B[Top2] = A[Top1];
			Top1 --;
		}
		
		
		printf ("Dequeued Element is %d. \n" , B[Top2]);	
		Top2 --;
			
		
		while (Top2 != -1)
		{
			Top1 ++;
			A[Top1] = B[Top2];
			Top2 -- ;
		}	
		
	}
}

void Print ()
{
	
	printf ("Queue: \n");
			
	for (int i = 0; i <= Top1; i++)
		printf (" %d \n" , A[i]);
		
	
}
		

int main ()
{
	int a, n;
	
	printf ("Enter max. size of the queue: \n");
	scanf ("%d", &Size);
	
	while (1)
	{
		printf ("Enter choice: \n");
		printf (" 1.To Enqueue. \n 2.To Dequeue. \n 3.To print all elements. \n 4.Exit. \n");
		
		scanf ("%d", &n);
		
		if ( n == 1)
		{
			printf ("Enter an elements you want to insert: \n");
			scanf ("%d", &a);
			Enqueue (a, Size);
		}
		
		else if ( n == 2)
		{
            Dequeue ();
		}

        else if	(n == 3)
		{
            Print ();
		}

        else
            break ;
	}

    return 0;
}	
				
			
		
		
	
	
			