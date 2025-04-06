// chaining without replacement
#include<iostream>
#include <string.h>
#define max 10
using namespace std;

struct node{
	char name[10];
	long int mn;
	int chain;
	node()
	{
		strcpy(name,"-");
		mn=0;
		chain=-1;
		
	}
};

class hasht{
	node ht[max];
	public:
	int hashfun(long int);
	void insert();
	void display();
	
};

int hasht::hashfun(long int num)
{
	return (num%max);
	
}

void hasht :: insert()
{
	node s;
	int prev=-1;
	cout<<"enter name amd mobile number"<<endl;
	cin>>s.name>>s.mn;
	
	int ind=hashfun(s.mn);
	
	if(ht[ind].mn==0)
	{
		ht[ind]=s;
	}
	
	else
	{
		while(ht[ind].mn!=0)
		{
			if((hashfun(s.mn))==hashfun(ht[ind].mn))
				prev=ind;
				
			ind=(ind+1)%max;
			
		}
		ht[ind]=s;
		ht[prev].chain=ind;
	}
} 

void hasht::display(){
	
	for (int i=0; i<max;i++){
		
		if(ht[i].mn==0){
			cout<<i<<" : "<<ht[i].name<<"  --------> NULL  "<<ht[i].chain<<endl;
		}
		else
		{
			cout<<i<<" : "<<ht[i].name<<" \t "<<ht[i].mn<<" \t "<<ht[i].chain<<endl;
		}
	}
}

int main()
{
	hasht h;
	char ch;
	int choice;
	
do{
	cout<<"                           --------------OPERATIONS------------------"<<endl;
	cout<<"1.insert /n2.display"<<endl;
	cout<<"enter your choice : "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			{
			h.insert();
			break;
			}
			
		case 2 :
			{
				h.display();
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

//chaining with replacement

 #include<iostream>
 #include<string.h>
 #define max 10
 using namespace std;
 
struct node{
	char name[10];
	long int mn;
	int chain;
	node()
	{
		strcpy(name,"-");
		mn=0;
		chain=-1;
		
	}
};

class hasht{
	node ht[max];
	public:
	int hashfun(long int);
	void insert();
	void display();
	void find();
	
};

int hasht::hashfun(long int num)
{
	return (num%max);
	
}

void hasht :: insert(){
	node temp;
	node s;
	int prev;
	
cout<<"Enter name and mobile number : "<<endl;
cin>>s.name>>s.mn;
int ind =hashfun(s.mn);
int ori = hashfun (s.mn);
ind=hashfun(s.mn);

if(ht[ind].mn==0)
{
	ht[ind]=s;
}
else if (hashfun(ht[ind].mn)==ind)
{
	int prev;
	while(ht[ind].mn!=0)
	{
		if(hashfun(ht[ind].mn)==hashfun(s.mn))
			prev=ind;
		ind=(ind+1)%max;
	}
	ht[ind]=s;
	ht[prev].chain=ind;
}
else
{
	node temp;
	temp=ht[ind];
	
	ht[ind]=s;
	
	while (ht[ind].mn!=0)
	{
		ind=(ind+1)%max;
		
	}
	ht[ind]=temp;
	
	int x=hashfun(temp.mn);
	prev=x;
	
	while(ht[x].chain!=-1)
	{
		x=ht[x].chain;
		if(ht[x].chain!=-1)
			prev=x;
			
	}
	ht[prev].chain=ind;
}
}


void hasht::display() 
{
	for(int i=0;i<max; i++)
	{
		cout<<i<<" : "<<ht[i].name <<"\t"<<ht[i].mn<<"\t"<<ht[i].chain<<endl;
	}
	
}

void hasht :: find()
{
	long int num;
	int ind;
	cout<<"which umber you want to search ? "<<endl;
	cin>>num;
	ind=hashfun(num);
	while (ind!=-1)
	{
		if(num==ht[ind].mn)
		{
			cout<<"mobile number is present at the index : "<<endl;
			return;
		}
		ind =ht[ind].chain;
		
	}
	cout<<"mobile number not found "<<endl;
}


int main()
{
	hasht h;
	char ch;
	int choice;
	
do{
	cout<<"                           --------------OPERATIONS------------------"<<endl;
	cout<<"1.insert /n2.display"<<endl;
	cout<<"enter your choice : "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			{
			h.insert();
			break;
			}
			
		case 2 :
			{
				h.display();
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





































