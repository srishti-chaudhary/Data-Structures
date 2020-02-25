#include <stdio.h>
#include <stdlib.h>


struct AVL
{
	int Key, Height;
	struct AVL *Left, *Right;
}typedef ET;

int Max (int a, int b)
{
	return (a > b)? a : b
}

int Height (AVL *Node)
{
	if (Node == NULL)
		return 0;
	
	return Node->Height;
}

AVL *New (int Key)
{
	AVL *Node = malloc (sizeof (AVL));
	
	Node->Key = Key;
	Node->Left = NULL;
	Node->Right = NULL;
	Node->Height = 1
	return (Node);
}

AVL *RightRotate (AVL *y)
{
	AVL *x = y->Left;
	AVL *z = x->Right;
	
	x->Right = y;
	y->Left = z;
	
	x->Heigth = max (Height(y->Left), Height(y->Right)) + 1;
	y->Heigth = max (Height(y->Left), Height(y->Right)) + 1;
	
	return x;
	
}

AVL *LeftRotate (AVL *x)
{
	AVL *y = x->Right;
	AVL *z = y->Left;
	
	y->Left = x;
	x->Right = z;
	
	x->Heigth = max (Height(y->Left), Height(y->Right)) + 1;
	y->Heigth = max (Height(y->Left), Height(y->Right)) + 1;
	
	return y;
	
}

int Balance (AVL *Node)
{
	if (Node == NULL)
		return 0;
	
	return Height(Node->Left) - Height(Node->Right);
}

AVL *Insert (AVL *Node, int Key)
{
	if (Node == NULL)
		return (New (Key));
	
	if (Key < Node->Key)
		Node->Left = Insert (Node->Left, Key);
	
	else if (Key > Node->Key)
		Node->Right = Insert (Node->Right, Key);
	
	else
		return Node;
	
	Node->Height = 1 + max(Height(Node->Left), Height(Node->Right));
	
	int B = Balance(Node);
	
	
	if (B > 1 && Key < Node->Left->Key)
		return RightRotate (Node);
	
	if (B < -1 && 