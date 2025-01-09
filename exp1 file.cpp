#include<iostream>
#include<fstream>
using namespace std;
class student 
{
	public:
		string name;
		int roll;
		char div;
		
		void getdata()
		{
			cout<<"enter the name : "<<endl;
			cin>>name;
			cout<<"enter the roll no: "<<endl;
			cin>>roll;
			cout<<"enter the division: "<<endl;
			cin>>div;
			
		}
		
		void display()
		{
			cout<<"name is :"<<name<<endl;
			cout<<"roll no is :"<<roll<<endl;
			cout<<"division is :"<<div<<endl;
		}
};

int main()
{
	student s[20];
	fstream f;
	int t,n,rn;
	char c;
	
	do
	{
		cout<<"1.write data \n 2.read data \n3. search data \n 4.delete"<<endl;
		cout<<"enter your choice : ";
		cin>>t;
		
		switch(t)
		{
			case 1:
				{
					cout<<"how many students you want to enter : "<<endl;
					cin>>n;
					f.open("input file",ios::out);
					for(int i=0;i<n;i++)
					{
						s[i].getdata();
						
						f.write((char*)&s[i], sizeof(s[i]));
					}
					
					f.close();
					break;
				}
				
				
			case 2:
				{
					cout<<"students details are : "<<endl;
					f.open("input file",ios::in);
					
					for(int i=0; i<n ; i++)
					{
						f.read((char*)&s[i], sizeof(s[i]));
						s[i].display();
					}
					f.close();
					break;
					
					
					
				}
				
			case 3 :
				{
					cout<<"enter the roll number to be searched : "<<endl;
					cin>>rn;
					f.open("file.txt",ios::in);
					bool found=false;
					for(int i=0; i<n; i++)
					{
						f.read((char*)&s[i],sizeof(s[i]));
						if(rn==s[i].roll)
						{
							cout<<"data found "<<endl;
							s[i].display();
							found=true;
							break;
						}
						f.close();
					}
					break;
				}
				
			case 4 :
				{
					student s;
					fstream p;
					
					int delroll;
					int flag=0;
					f.open("file.txt",ios::in);
					p.open("tempfile.txt",ios::out);
					cout<<"enter the roll no to be deleted : "<<endl;
					cin>>delroll;
					
					while(f.read((char*)&s,sizeof(s)))
					{
						if(s.roll==delroll)
						{
							cout<<"record found \n";
							s.display();
							flag=1;
							
						}
						else{
							p.write((char*)&s, sizeof(s));
						}
					}
					f.close();
					p.close();
					
					
					remove("file.txt");
					rename("tempfile.txt","file.txt");
					cout<<"data deleted "<<endl;
					
					if (flag==0)
					{
						cout<<"record not found \n";
					}
					break;
				}
				
		    default:
		    	cout<<"invalid choice"<<endl;
		    	
				
			
		}
		cout<<"do you want to continue y/n : ";
		cin>>c;
		
	}
	
	while(c=='y');
	
	return 0;
	
}

