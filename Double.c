#include <stdio.h>
#include <stdlib.h>

struct Node

{
	int data;
	struct Node *next;
	struct Node *prev;
}typedef Node;

struct Node *Head,*End;

void Insert_end (int a)
{
	
	if (Head == NULL)
	{
		Head = malloc(sizeof(Node));
		Head->data = a;
		Head->next = NULL;
		Head->prev = NULL;
		End = Head;
	}
	
	else
	{
		Node *temp;
		temp = malloc(sizeof (Node));
		temp->data = a;
		temp->next = NULL;
		End->next = temp;
		temp->prev = End;
		End = temp;
	}
	
}

void Insert_begin (int a)
{
	if (Head == NULL)
	{
		Head = malloc(sizeof(Node));
		Head->data = a;
		Head->next = NULL;
		Head->prev = NULL; 
	}
	else 
	{
		Node *temp;
		temp = malloc(sizeof (Node));
		temp->data = a;
		temp->prev = NULL;
		temp->next = Head;
		Head->prev = temp;
		Head = temp;
	}
}

void Insert_middle (int a)
{
	
	if (Head == NULL)
	{
		Head = malloc(sizeof(Node));
		Head->data = a;
		Head->next = NULL;
		Head->prev = NULL; 
	}
	
	else
	{
		Node *temp, *temp1, *temp2;
		temp = malloc (sizeof (Node));
		temp->data = a;
		temp->next = temp2;
		temp->prev = temp1;
		temp1->next = temp;
		temp2->prev = temp;
	}
}

void Delete (int a)
{
	Node *Key;
	Key = Head;
	
	while(Key != NULL)
	{
		
			if (Key->data == a)
			{
			    Node *temp, *temp1, *temp2;
			
			    temp = Key;
				temp1 = temp->prev;
				temp2 = temp->next;
				
			    temp1->next = temp2;
			    temp2->prev = temp1;
			    free (temp);
			    printf("Data deleted.");
			    break;
			}
			else
			{
				Key = Key->next;
			}
		
		
	
	}
}

int Search (int a)
{
	Node *temp;
	temp = Head;
	while (1)
	{
		if (temp == NULL)
		{
			printf ("DATA NOT FOUND!\n");
			break;
		}
		
		else
		{
			if (temp->data == a)
			{
				printf ("DATA FOUND!\n");
				break;
			}
			else
			{
				temp = temp->next;
			}
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
	Head = NULL;
	
	
	int n, a, p;
	
	while (1)
	{
	printf ("Enter Choice:\n 1.Insert at End. \n 2.Insert at Beginning. \n 3.Insert in Middle. \n 4.Delete Data. \n 5.Search an element. \n 6.Print all Elements \n 7.Exit. \n");
	scanf ("%d", &n);
	
	
		if (n == 1)
		{
			printf ("Enter element to be inserted: \n");
			scanf ("%d", &a);
			Insert_end(a);
		}
		
		else if (n == 2)
		{
			printf ("Enter element to be inserted: \n");
			scanf ("%d", &a);
			Insert_begin(a);
		}
		else if (n == 3)
		{
			printf ("Enter element to be inserted: \n");
			scanf ("%d", &a);
			printf ("Enter position:");
			scanf ("%d", &p);
			Insert_middle(a);
		}
		else if (n == 4)
		{
			printf ("Enter Data you want to delete: \n");
			scanf ("%d", &a);
			Delete (a);
		}
		else if (n == 5)
		{
			printf ("Enter the element you want to search: \n");
			scanf ("%d", &a);
			Search(a);
		}
		else if (n == 6)
		{
			Print();
		}
		
		else if (n == 7)
			break;
		
	}
	
	return 0;
}
	
	