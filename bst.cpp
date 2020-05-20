#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*t,*c,*root,m;
void bst(node* t,int x)
{
	int a=1;
	while(a==1)
	{
		if(x>=(t->data))
		{
		if(t->right==NULL)
		{
			t->right=new node();
			(t->right)->data=x;
			(t->right)->right=NULL;
			(t->right)->left=NULL;
			break;
		}
		else
		{
			t=t->right;
		}
		}
		else if(x<(t->data))
		{
		if(t->left==NULL)
		{
			t->left=new node();
			(t->left)->data=x;
			(t->left)->right=NULL;
			(t->left)->left=NULL;
			break;
		}
		else
		{
			t=t->left;
		}
		}
		}	
}
void inorder(node* m)
{
	if(m==NULL)
	{
		return;
	}
	inorder(m->left);
	cout<<m->data<<" ";
	inorder(m->right);
}
int main()
{
	int n,a;
	cin>>n;
	cin>>a;
	c=new node;
	c->data=a;
	c->left=NULL;
	c->right=NULL;
	root=c;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		bst(root,a);
	}
	inorder(root);
	return 0;
}
