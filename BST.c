#include <stdio.h>
#include <stdlib.h>

struct BST
 {
	int Data;
	struct BST *Left, *Right;
}typedef BST;

BST *Root = NULL;

int N,i=0,j=20,ctr = 10, Arr[40][40];

void Insert (int Key)
{
	int i=0,j=10;
	
	BST *temp, *temp1;
	
	temp = malloc (sizeof (BST));
	temp->Data = Key;
	temp->Left = NULL;
	temp->Right = NULL;
	
	if (Root == NULL)
	{
		Root = temp;
		
		Arr[i][j] = Key;
    	i++;
	}
	
	
	else
	{
		i++ ;
		temp1 = Root;
		
		while(1)
		{
			if (Key <= temp1->Data)
			{
				j -= 3;
				
				if (temp1->Left == NULL)
				{
					Arr[i][j] = Key;
					temp1->Left = temp;
				    break;
				}
					
				else
				{
					temp1 = temp1->Left;
					i++;
				}
				
			}
			
			else
			{
				j += 7;
				
				if (temp1->Right == NULL)
				{
					Arr [i][j] = Key;
					temp1->Right = temp;
				    break;
				}
					
				else
				{
					temp1 = temp1->Right;
					i ++;
				}
				
			}
			
		}
	}
}

void Search (int i)
{
	
	BST *temp;
	temp = Root;
	int f = 0;
	
	while (temp != NULL)
	{
		if (temp->Data == i)
		{
			printf ("Data Found! \n");
			f = 1;
			return;
		}
		
		else if (i < temp->Data)
			temp = temp->Left;
		
		else
			temp = temp->Right;
		
	}
	
	if (f == 0)
		printf ("Data Not Found! \n");
	
}

void Print_TREE ()
{
	
	printf ("TREE: \n");
	
	for(int i=0; i<40; i++)
	{
		for(int j=0; j<40; j++)
		{
			if(Arr[i][j]==0)
				printf(" ");
			
			else
				printf("%d",Arr[i][j]);
		}
		
		printf("\n");
	}
}


void Print_IN (BST *temp)
{
	if (temp == NULL)
		return;
	
	else
	{
		
		Print_IN(temp->Left);
		printf ("%d \n", temp->Data);
		Print_IN(temp->Right);
	}
}

void Print_POST (BST *temp)
{
	if (temp == NULL)
		return;
	
	else
	{
		
		Print_POST(temp->Left);
		Print_POST(temp->Right);
		printf ("%d \n", temp->Data);
		
	}
}

void Print_PRE (BST *temp)
{
	if (temp == NULL)
		return;
	
	else
	{
		
		printf ("%d \n", temp->Data);
		Print_PRE(temp->Left);
		Print_PRE(temp->Right);
	}
}

BST *Min_Node (BST *temp)
{
	while (temp->Left != NULL)
		temp = temp->Left;
	
	return temp;
}

BST *Delete (BST *temp, int Key)
{
	
	if (temp == NULL)
	{
		return temp;
	}
	
	if (Key < temp->Data)
		temp->Left = Delete(temp->Left, Key);
 
    else if (Key > temp->Data)
        temp->Right = Delete(temp->Right, Key);
	
	else 
	{
		if (temp->Left == NULL)
		{
			BST *temp1 = temp->Right;
			free (temp);
			return temp1;
		}
		
		else if (temp->Right == NULL)
		{
			BST *temp1 = temp->Left;
			free (temp);
			return temp1;
		}
		
		BST* temp1 = Min_Node(temp->Right);
        temp->Data = temp1->Data;
 
        temp->Right = Delete(temp->Right, temp1->Data);
	}
	
	return temp;
		
}

void printTree (BST *temp, int space)
{
	if (temp == NULL)
		return;
	
	space = space + ctr;
	
	printTree (temp->Right, space);
	printf ("\n");
	
	for (int i=ctr; i<space; i++)
		printf (" ");
	
	printf ("%d \n", temp->Data);
	printTree (temp->Left, space);
}
			

int main()
{
	int Key,n,o,s,D;
	
	

    while (1)
	{
       
       printf ("Enter Choice: \n");
       printf (" 1.To insert Elements. \n 2.To search an Element. \n 3.To delete a Node. \n 4.To print the Tree. \n 5.Exit. \n");
	   scanf ("%d", &o);

       if (o == 1)
	   {
            printf ("Enter number of Nodes: \n");
			scanf ("%d", &n);
            
            
			printf ("Enter all Elements: \n");
			for (int i=0; i<n; i++)
			{
                scanf ("%d", &Key);
				
				Insert (Key);
			}
	   }
	   
	   else if (o == 2)
	   {
		   printf ("Enter Element: \n");
		   scanf ("%d", &s);
		   
		   Search (s);
		   
	   }
	   
	   else if (o == 3)
	   {
		   printf ("Enter a node you want to Delete: \n");
		   scanf ("%d", &D);
		   
		   Delete (Root, D);
		   
	   }
		   
		   
		   
	   
	   else if (o == 4)
	   {
		   printf ("Binary Tree is: \n");
		   
		   printf ("Binary Tree is: \n");
		   printTree (Root, 0);
		   
		   printf ("INORDER TREE: \n");
		   Print_IN (Root);
		   
		   printf ("POSTORDER TREE: \n");
		   Print_POST (Root);
		   
		   printf ("PREORDER TREE: \n");
		   Print_PRE (Root);
		   
		   
				
		   //Print_TREE();
		
		}
	   
	   else
		   break;
	   
	}
	
	return 0;
}
                				
	
	


