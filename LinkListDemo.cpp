#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void add(struct node **root,int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(*root==NULL)
	{
		*root=newnode;
		return;
	}
	else
	{
		struct node *temp=*root;
	    while(temp->next!=NULL)
	         temp=temp->next;
	    temp->next=newnode;
	}
}
void display(struct node *root)
{
	struct node *t=root;
	while(t!=NULL)
	{
		cout<<t->data;
		t=t->next;
	}
	cout<<endl;
}
void reverse(struct node **root)
{
	struct node *temp=*root,*top=NULL;
	while(temp!=NULL)
	{
		if(top==NULL)
	    {
	    	top=temp;
   		    temp=temp->next;
   		    top->next=NULL;
	    }
	    else
	    {
	    	struct node *save=temp->next;
	    	temp->next=top;
	    	top=temp;
	    	temp=save;
		}
	}
	*root=top;
}
void addone(struct node **root)
{
	reverse(root);
	display(*root);
	int carry=1;
	struct node *t=*root;
	while(t!=NULL)
	{
		if((t->data+carry)/10>0)
		{
			
			int frdcarry=(t->data+carry)/10;
			t->data=(t->data+carry)%10;
			carry=frdcarry;
		}
		else
		{
			t->data=t->data+carry;
			return ;
		}
		t=t->next;
	}
	if(carry)
	    cout<<"need new node";
	
}
int main()
{
    int i,n=10;
    struct node *root=NULL;
	//for(i=0;i<n;i++)
	//	add(&root,i);
	add(&root,9);
	add(&root,9);
	add(&root,9);
	add(&root,9);
	display(root);
	//reverse(&root);
	//display(root);
	addone(&root);
	display(root);
	reverse(&root);
	display(root);
}
