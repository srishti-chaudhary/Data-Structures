n#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *next;
	}typedef node;
node *head,*end;
void sort(int d)

{
int f=0;
if(head==NULL)
	{
		head=malloc(sizeof(node));
		head->data=d;
		head->next=NULL;
		end=head;
		return;
		f=1;
	}
node*temp,*temp1,*temp2;
temp=malloc(sizeof(node));
temp1=head;
while(1)
{
        if(temp1->next==NULL)
        {f=2;
        break;
        }
        
	if(temp1->data<d&&temp1->next->data>d)
	{f=1;
	break;
	}
	temp1=temp1->next;
}
if(f==1)
{
	temp2=temp1->next;
	temp1->next=temp;
	temp->next=temp2;
	temp->data=d;
	return;
}
if(f==0)
{
	        node*temp3;
		temp3=malloc(sizeof(node));
		temp3->data=d;
		temp3->next=NULL;
		end->next=temp3;
		end=temp3;
		return;
}
	
if(f==2)
{if(temp1->data<d)
{
temp2=temp1->next;
	temp1->next=temp;
	temp->next=temp2;
	temp->data=d;
	return;
}
else

	{	node*temp5;
		temp5=malloc(sizeof(node));
		temp5->data=d;
		temp5->next=head;
		head=temp5;
	
	}	
}


}

void print()
{
	node *temp4;
	temp4=head;
	printf ("Sorted Array is: \n");
	while(temp4!=NULL)
	{
		printf(" %d\n ",temp4->data);
		temp4=temp4->next;
	}
}

int main()
{
head=NULL;
end=NULL;
int ch,d1;
while(1)
{
printf("Enter Choice. \n1.Enter Data. \n2.To Sort. \n");
scanf("%d",&ch);

switch(ch)
	{ 	
		case 1:
			
			scanf("%d",&d1);
			sort(d1);
			
			break;
		case 2:
			
			print();
 			exit(0);
 			

	}
}
return 0;
}
