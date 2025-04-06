#include<iostream>
using namespace std;

struct node{
	char label[50];
	int chcount;
	node*child [50];
	
};

class booktree{
	node*root;
	public:
		booktree(){
			root=NULL;
			
		}
		void create();
		void display();
		
};

void booktree :: create()
{
	root= new node();
	cout<<"enter the book name : "<<endl;
	cin>>root->label;
	cout<<"how many chapters"<<endl;
	cin>>root->chcount;
	
	int i,j,k;
	
	for(i=0 ; i<root->chcount; i++)
	{
		root->child [i]=new node();
		cout<<"enter the name of chapter : "<<i+1<<endl;
		cin>>root->child[i]->label;
		cout<<"how many sections for chapter : "<<i+1;
		cin>>root->child[i]->chcount;
		
		for(j=0;j<root->child[i]->chcount;j++)
		{
			root->child [i]->child[j]=new node();
			cout<<"enter the name of section : "<<j+1<<endl;
		    cin>>root->child[i]->child[j]->label;
		    cout<<"how many subsections for sections  : "<<j+1;
		    cin>>root->child[i]->child[j]->chcount;
		    
		    for(k=0;k<root->child[i]->child[j]->chcount ; k++)
		    {
		    	root->child[i]->child[j]->child[k]=new node();
		    	cout<<"enter name of subsections : "<<k+1<<"name : "<<endl;
		    	cin>>root->child[i]->child[j]->child[k]->label;
		    	
			}
			
		}
	}
}

void booktree :: display()
{
	node*temp =root;
	cout<<temp->label<<endl;
	
	int i, j ,k ;
	
	for (i=0;i<root->chcount;i++)
	{
		cout<<"\t"<<i+1<<"."<<root->child[i]->label<<endl;
		for(j=0;j<root->chcount ;j++)
		{
			cout<<"\t\t"<<j+1<<"."<<root->child[i]->child[j]->label<<endl;
			for(k=0;k<root->chcount ;k++)
			{
			cout<<"\t\t\t"<<k+1<<"."<<root->child[i]->child[j]->child[k]->label<<endl;
			}
		}
	}
}

int main()
{
	booktree b ;
	char ch;
	int choice;
	
do{
	cout<<"                           --------------OPERATIONS------------------"<<endl;
	cout<<"\n 1.create \n 2.display"<<endl;
	cout<<"enter your choice : "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			{
			b.create();
			break;
			}
			
		case 2 :
			{
				b.display();
				break;
			}
		default:
			{
				cout<<"invalid choice "<<endl;
			}
			
			
	}
	cout<<"do you want to continue?(y/n)"<<endl;
	cin>>ch;
}

while(ch=='y');
return 0;
}

