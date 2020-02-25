#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}typedef Node;

 struct Node *Head, *End;

void Insert_end (int a)
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
		temp = malloc(sizeof(Node));
		temp->data = a;
		temp->next = NULL;
		End->next = temp;
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
	}
	else 
	{
		Node *temp;
		temp =  malloc(sizeof (Node));
		temp->data = a;
		temp->next = Head;
		Head = temp;
	}
}

void Delete (int a)
{
	Node *temp, *temp1, *temp2;
	temp1 = Head;
	temp2 = Head->next;
	
	if (Head->data == a)
	{
		Node *temp;
		temp = Head->next;
		free (Head);
		Head = temp;
	}
	
	
	else
	{
		while(1)
	    {
		    if ( temp2->data != a)
            {
			    temp1 = temp1->next;
			    temp2 = temp2->next;
		    }
		    if (temp2 == NULL)
		    {
			    printf ("Data not found.");
			    break;
		    }
		    else
			    break;
	    }
		
		
		temp1->next = temp2->next;
		free (temp2);
	}
}

void Search (int a)
{
	Node *temp;
	temp = Head;
	while (1)
	{
		if (temp == NULL)
		{
			printf("Data not FOUND.\n");
			break;
		}
		
		else
		{
			if (temp->data == a)
			{
				printf ("Data Found.\n");
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}

void Find_max()
{
	
    int max = 0;
    
    while((Head->next)!=NULL)
    {
        max = Head->data;
        Head=Head->next;
        if((Head->data) > max)
        {
            max = Head->data;
        }
    }
    printf("The maximum number is %d.",max);  
    printf("\n");
}


void Average ()
{
	
	Node *temp;
    temp = Head;
	int  sum = 0, Av = 0, c = 0;
	
	while(temp != NULL)
    { 
       printf("%d\n",temp->data);
	   sum = sum + temp->data;
	   c++;
	   
       temp = temp->next;
    }
	 printf ("sum = %d\n", sum);
	
	
	printf ("c = %d\n", c);
	Av = sum / c;
	
	
	printf ("Average of all Elements is %d", Av);
	printf("\n");
        
}

void Reverse()
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


	

int main()
{
	Head = NULL;
	int n, a;
	
	while (1)
	{
	printf ("Enter your choice: \n 1.Insert at End. \n 2.Insert at Beginning \n 3.Delete an element. \n 4.Search an Element \n"); 
	printf (" 5.Find maximum of all.\n 6.Find average of all. \n 7.To reverse the List. \n 8.Print all Elements. \n 9.Exit\n");
	scanf ("%d", &n);
	
	
		if (n == 1)
		{
			
			printf ("Enter the Element to be inserted:\n");
			scanf ("%d", &a);
			Insert_end(a);
		}
		
		else if (n == 2)
		{
			
			printf ("Enter elements to be inserted:\n");
			scanf ("%d", &a);
			Insert_begin(a);
		}
		
		else if (n == 3)
		{
			printf ("Enter the Element you want to delete:\n");
			scanf ("%d", &a);
			Delete (a);
		}
		
		else if (n == 4)
		{
			printf ("Enter the Element to be searched:\n");
			scanf ("%d", &a);
			Search (a);
		}
		
		else if (n == 5)
		{
			Find_max();
		}
		
		else if (n == 6)
		{
			Average();
		}
		
		else if (n == 7)
		{
			Reverse();
		}
		
		else if (n == 8)
		Print();
		
		else if (n == 9)
		break;
		
		
	}
	
	return 0;
}