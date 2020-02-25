#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}typedef Node;

struct Node *Head, *End;

void Create (int a)
{
	if (Head == NULL)
	{
		Head = malloc(sizeof(Node));
		Head->data = a;
		Head->next = NULL;
		End = Head;
	}
	
	else
	{
		Node *temp;
		temp = malloc(sizeof (Node));
		temp->data = a;
		temp->next = NULL;
		End->next = temp;
		End = temp;
		
	}
}

void Reverse ()
{
	Node *temp1, *temp2, *temp3;
	temp1 = NULL;
	temp2 = Head;
	temp3 = temp2->next;
	
	while (1)
	{

	
  	    if (temp3!= NULL)
		{
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp2->next;
		}
		
		else
		{
			temp2->next = temp1;
			Head = temp2;
			break;
		}
		
		
	}
	
	
}

void Print()
{
     Node *temp;
     temp = Head;
     printf (" Linked List:\n");
	 
	 while(temp != NULL)
     { 
       printf("%d\n",temp->data);
	   
	   
       temp = temp->next;
     }
	 
}			

int main ()
{
	int a, n;
	
	while (1)
	{
		printf("Enter choice.\n");
	    printf (" 1.To enter an element. \n 2.To reverse. \n 3.To print. \n 4.Exit. \n");
		
		scanf ("%d", &n);
		
		if (n == 1)
		{
			printf ("Enter the element to be inserted: \n");
			scanf ("%d", &a);
			Create (a);
		}
		
		else if (n == 2)
		{
			Reverse();
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

   		
	
	