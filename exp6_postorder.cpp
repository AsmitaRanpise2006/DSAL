#include<iostream>
#include<string.h>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
};

class stack{
	node*s[20];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		
		void push(node *);
		node*pop();
		int isEmpty();
};

int stack::isEmpty() {
	if(top==-1)
	return 1;
	else
	return 0;
}

void stack::push (node *n)
	{
	top++;
	s[top]=n;
	}
	
node* stack:: pop(){
	return (s[top--]);
}



class Tree {
	stack s;
	char prefix[20];
	
	public:
		node *top;
		void expression(char[]);
		void postorder(node*);
		void display(node*);
		void del(node*);
		
};

void Tree :: expression(char prefix[])
{
	int len;
	node *t1, *t2;
	len=strlen(prefix);
	
	for(int i=len-1;i>=0;i--)
	{
		top=new node;
		top->left=NULL;
		top->right=NULL;
		if(isalpha(prefix[i])){
			top->data=prefix[i];
			s.push(top);
		}
		
		else if (prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*'||prefix[i]=='/')
		{
			t1=s.pop();
			t2=s.pop();
			top->data=prefix[i];
			top->left=t1;
			top->right=t2;
			s.push(top);
		}
}

top=s.pop();
}

void Tree :: postorder(node*top)
{
	stack s1,s2;
	node *t,*t1;
	t=top;
	s1.push(t);
	
	while(s1.isEmpty())
	{
		t1=s1.pop();
		s2.push(t1);
		
		if(t1->left!=NULL)
		{
			s1.push(t1->left);
		}
		
		if(t1->right!=NULL)
		{
			s1.push(t1->right);
		}
	}
	
	node*x;
	while(!s2.isEmpty())
	{
		x=s2.pop();
		cout<<x->data;
	}
	cout<<endl;
}


void Tree :: display(node*top)
	{
	if (top==NULL)
	{
		return;
	}
	
	display(top->left);
	cout<<top->data;
	display(top->right);
}

void Tree ::del(node*n)
{
	node*temp=n;
	if(temp==NULL)
		return;
	del(temp->left);
	del(temp->right);
	cout<<"deleting a node : "<<temp->data<<endl;
	delete(temp);
}

int main()
{
	Tree T;
	char ch;
	int choice;
	char arr[20];
	
	cout<<"enter the expression : "<<endl;
	cin>>arr;
	
	do{
		cout<<" 1.Expression \n 2.postorder \n 3. display \n 4.del \n Enter your choice : "<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					T.expression(arr);
					break;
				}
				
			case 2:
				{
					T.postorder(T.top);
					break;
				}
			
			case 3:
				{
					T.display(T.top);
					break;
				}
			case 4:
				{
					T.del(T.top);
					break;
				}
			default:
				cout<<"Invalid choice : "<<endl;
				break;
		}
		cout<<"\n do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}
	while(ch=='y');
	return 0;
	
}
