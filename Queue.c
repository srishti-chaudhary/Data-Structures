#include<stdio.h>

int A[100], Top = -1, End= -1, s;



void Enqueue (int a, int s)
{
	if (End == s-1)
	{
		printf ("Queue is Full. \n");
	}
	else 
	{
		
			Top = 0;
			End ++;
			A[End] = a;
			
		
	}
		
	
}

void Dequeue()
{
	if (Top == End +1)
	{
		printf ("Queue is empty. \n");
	}
	else 
	{
		printf ("Deleted Element is %d. \n", A[Top]);
		
		Top ++;
		
		//if (Top == End)
			//Top = End = -1;
	}
}

 void Print ()
{
	int i;
	
	
	
	if ( Top == End +1)
	{
		printf ("Queue is empty.");
	}
	else{
	    printf ("Queue: \n");
		for (int i=Top; i<=End; i++)
	    {
		   printf ("%d \n", A[i]);
	    }
	}
}
		
	

int main()
{
	int n, a;
	
	printf("Enter size of the Queue: \n");
			scanf ("%d", &s);
			
	while (1)
	{
		printf ("Enter choice: \n");
		printf (" 1. To enqueue. \n 2. To dequeue. \n 3. To print all elements \n 4. Exit. \n");
		
		scanf ("%d", &n);
		
		if (n == 1)
		{
			printf ("Enter element you want to enqueue: \n");
			scanf ("%d", &a);
			Enqueue(a, s);
		}
		else if (n == 2)
		{
			Dequeue();
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
			
	