#include <iostream>
#include<queue>
using namespace std;
#define max 10

class OBST
{
	int w[max][max],r[max][max],c[max][max],a[max],p[max],q[max+1];
	int m,n,i,j,k;
	public:
		void accept()
		{
			cout<<"Enter the total no keys : ";
			cin>>n;
			
			for(i =0;i<n; i++)
			{
				cout<<"\n Enter the keys :"<<endl;
				cin>>a[i];
			}
			
			cout<<"ENetr the probabilities of successful search : ";
			for(i=1;i<=n ;i++)
			{
				cout<<"enter the probability :";
				cin>>p[i];
				
			}
			
			cout<<"Enter the probability of unsuccessful search  : ";
			for (i=0 ; i<=n; i++)
			{
				cout<<"\n Enter probability : ";
				cin>>q[i];
				
			}
		}
		
		int find(int i, int j)
		{
			int m,k;
			int min =32000;
			for (k=i+1 ;k<=j ; k++)
			{
				if((c[i][k-1]+c[k][j])<min)
				{
					min=c[i][k-1]+c[k][j];
					m=k;
				}
			}
			return m;
		}
		
		void build_obst()
		{
			
			for (i=0;i<=n;i++)
			{
				w[i][i]=q[i];
				c[i][i]=r[i][i]=0;
			}
			
			for(m=1;m<=n;m++)
			{
				for (i=0;i<=n-m;i++)
				{
					j=i+m;
					w[i][j]=w[i][j-1]+p[j]+q[j];
					k=find(i,j);
					c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
					r[i][j]=k;
					
				}
			}
		}
		
		void display()
		{
			queue<int>queue;
			int i,j,k;
			cout<<" the optimal binary search tree for given nodes is ... \n "<<endl;
			cout<<"\n The root of this OBST is : "<<r[0][n]<<endl; 
			cout<<"\n The cost of this OBST id : "<<c[0][n]<<endl;
			cout<<"\n\n \t NODE \t LEFT CHILD \t RIGHT CHILD";
			cout<<"\n -------------------------------------------------------------------"<<endl;
			queue.push(0);
			queue.push(n);
			
			while (!queue.empty())
			{
				i=queue.front() ;
				queue.pop();
				
				j=queue.front() ;
				queue.pop();
				
				k=r[i][j];
				cout<<"\n         "<<k;
				if (r[i][k-1]!=0)
				{
					cout<<"                 "<<r[i][k-1];
					queue.push(i);
					queue.push(k-1);
				}
				
				else 
					cout<<"               -";
				
				if(r[k][j]!=0)
				{
					cout<<"                "<<r[k][j];
					queue.push(k);
					queue.push(j);	
				}
				else
					cout<<"                   -";
			}
			cout<<"\n";
		}
};

int main()
{
	OBST o;
	o.accept();
	o.build_obst();
	o.display();
	
	return 0;
}
