#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	
	//declare variable
	int n=0 , max=0 , min=999999 ;
	double salary , comission , loan , totalincome=0 , avgincome ;
	char answer='N';
	string name , maxName , minName;
	cout<<"Press enter to start"<<endl;
	while (toupper(answer)!='Y')
	{
		
		cin.get();
		cout<<"\nSalesman"<<n+1<<endl;
		cout<<"Enter name: ";
		getline(cin,name);
		
		cout<<"Enter monthly salary: ";
		cin>>salary;
		
		cout<<"Enter total price of car had been sold: ";
		cin>>comission;
		
		cout<<"Enter payment value of loan: ";
		cin>>loan;
		
		salary=salary+ 0.03*comission - loan;
		cout<<"The total salary is =Rm"<<salary;
		
		if (salary>max)
		   { max=salary;
		     maxName=name;
		   }
		   
		if (salary<min)
		   { min=salary;
		     minName=name;
		   }
		   
		totalincome+=salary;
		n++;
		
		cout<<"\nDo you want to stop (y/n) ? ";
		cin>>answer;
   }
   
   avgincome=totalincome/n;
   
   cout<<"The highest net income is "<<maxName<<" :RM"<<max<<endl;
   cout<<"The lowest net income is "<<minName<<" :RM"<<min<<endl<<endl;
   cout<<"The average net income of salesman is RM"<<avgincome<<endl;
   
   return 0;
}
