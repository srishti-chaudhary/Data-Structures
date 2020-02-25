#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

 
struct ET
{
	char Data;
	struct ET *Left, *Right;
}typedef ET;

int Top = -1;
ET *Stack[20];
ET *Node;

//int N,i=0,j=20,Arr[40][40];

void Push (ET *Node)
{
	Stack[++Top] = Node;
}

ET *Pop()
{
	return (Stack[Top--]);
}

int Check (char ch)
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return 2;
	
	else 
		return 1;
	
}


int Calculate(ET *Node)
{
	
	int ch;
	ch = Check (Node->Data);
	
	if (ch == 1)
		return Node->Data-48;
	
	else if ( ch == 2)
	{
		if (Node->Data == '+')
			return Calculate(Node->Left)+Calculate(Node->Right);
		
		if (Node->Data == '-')
			return Calculate(Node->Left)-Calculate(Node->Right);
		
		if (Node->Data == '*')
			return Calculate(Node->Left)*Calculate(Node->Right);
		
		if (Node->Data == '/')
			return Calculate(Node->Left)/Calculate(Node->Right);
	}
}
	

void Inorder (ET *Node)
{
	if (Node == NULL)
		return;
	
	else
	{
		Inorder (Node->Left);
		printf ("%c", Node->Data);
		Inorder (Node->Right);
	}
}

void Postorder (ET *Node)
{
	if (Node == NULL)
		return;
	
	else
	{
		Postorder (Node->Left);
		Postorder (Node->Right);
		printf ("%c", Node->Data);
	}
}

void Preorder (ET *Node)
{
	if (Node == NULL)
		return;
	
	else
	{
		printf ("%c", Node->Data);
		Preorder (Node->Left);
		Preorder (Node->Right);
	}
}


void Operand (char b)
{
	Node = malloc (sizeof (ET));
	Node->Data = b;
	Node->Left = NULL;
	Node->Right = NULL;
	Push(Node);
}


void Operators (char a)
{
	Node = malloc (sizeof (ET));
	Node->Data = a;
	Node->Right = Pop();
	Node->Left = Pop();
	Push(Node);
	
}

void main ()
{   
	int P,K,Ans ;
	char S[20];
	
	
	printf (" \nEnter the Postfix Expression: \n ");
	
	fflush(stdin);
	gets(S);
	K = strlen(S);
	
	for (int i=0; S[i] != '\0'; i++)
	{
		P = Check (S[i]);
		
		if (P == 1)
			Operand (S[i]);
		
		else if (P == 2)
			Operators (S[i]);
	}
	
	//Ans = Calculate(Stack[Top]);
	
	//printf ("\nThe value of the postfix Expression is: %d \n", Ans);
	printf ("\n \n");
	printf ("The Inorder Transversal of the tree is: \n");
	
	Inorder (Stack[Top]);
	
	printf ("\n \n");
	
	printf ("The Postorder Transversal of the tree is: \n");
	Postorder (Stack[Top]);
	
	printf ("\n \n");
	printf ("The Preorder Transversal of the tree is: \n");
	Preorder (Stack[Top]);
	
	getch();
}




	