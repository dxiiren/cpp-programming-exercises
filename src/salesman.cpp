#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	double income,commission,salary,highest=0,lowest=99999,totalsalary=0;
	int n;
	string name,maxname,minname;
	
	cout<<"Chendering Luxury Cars Sdn Bhd"<<endl;
	cout<<"Press enter to start"<<endl;
	
	for (n=0 ; n<5 ; n++) {
	    cin.get();
		cout<<"\nSalesman "<<n+1<<endl;
		
		cout<<"Please enter name : ";
		getline(cin,name); 
		
		cout<<"Please enter monthly salary: ";
		cin>>salary;
		
		cout<<"Please enter total price of car that had been sold: ";
		cin>>commission;
		
		income=salary + 0.03*commission;
		
		if (income>highest)
		{
		    highest=income;
		    maxname=name;
	    }
		if (income<lowest)
		{
		    lowest=income;
		    minname=name;
		}
		cout<<"The total income is rm = "<<income<<endl;
		totalsalary+=income;
	}
	
    cout<<endl;
	cout<<"The highest salary is "<<maxname<<" = RM"<<highest<<endl;
	cout<<"The lowest salary is "<<minname<<" = RM"<<lowest<<endl;
	cout<<"The total salary of all salesman is RM :"<<totalsalary<<endl;
	     
	return 0 ;     
	}
