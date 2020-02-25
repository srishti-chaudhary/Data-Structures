#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int n;

struct Node
{
	int Data;
	struct Node *Next;
}typedef Node;

Node *Head[100], *End[100];

void Insert (int i, int j)
{
	Node *temp;
	
	if (Head[i] == NULL)
	{
		Head[i] = malloc(sizeof(Node));
		Head[i]->Data = j;
		Head[i]->Next = NULL;
		End[i] = Head[i];
	}
	
	else
	{
		temp = malloc(sizeof(Node));
		temp->Data = j;
		temp->Next = NULL;
		End[i]->Next = temp;
		End[i] = temp;
	}
}

void Print ()
{
	int i=0;
	
	Node *temp1;
	
	printf ("Linked List: \n");
	while (i != n)
	{
		
		printf ("B[%d]", i+1);
		
		temp1 = Head[i];
		
		while (temp1 != NULL)
		{
			printf (" ->%d", temp1->Data);
			
			temp1 = temp1->Next;
			
		}
		i++;
		printf ("\n"); 
	}
}

int main ()
{
	
	
	for (int i = 0; i<1; i++)
	{
        Head[i] = NULL;
	}

    float x[101], y[101];
 	
	printf ("Enter the size of the Matrix: \n");
	scanf ("%d", &n);
	
	int A[n][n];
	
	for (int i=0; i< n; i++)
	{
		x[i] = (rand()*1.0/RAND_MAX*1.0)*10;
	    y[i] = (rand()*1.0/RAND_MAX*1.0)*10;
		
		printf ("Co-ordinates: \n");
		printf ("(%f,%f) \n", x[i],y[i]);
		
	}

    float z,r;

    for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			
			r = pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
            z = sqrt(r);
			
            if (z <= 1)
			    A[i][j] = 1;

            else 
                A[i][j] = 0;
		}
	}
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (A[i][j] == 1)
				Insert(i, j+1);
		}
	}
	
	printf ("Matrix: \n");
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			printf ("%d", A[i][j]);
		}
		
		printf ("\n");
		
	}
	
	Print();
	
	
	return 0;
	
}
	
	
		
	
	
	
	


	