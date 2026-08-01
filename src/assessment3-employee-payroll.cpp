#include <iostream>
#include <cctype>
using namespace std;


double grosspay (int);
int main(){

     //declare variable
     int employee=0 , underpaid=0 , highest=0 ,hour ;
     double gross , deduction , net ;
     string name,highestname , id ;
     char answer='n';
     
     cout<<"MNC COMPANY\n";
	 cout<<"______________\n";
	 
	 
	 while(toupper(answer)!='Y')
	 {
	 
		 cout<<"\nEnter employee id : ";
		 cin>>id;
		 cin.get();
		 
		 cout<<"Enter employee name : ";
		 getline(cin,name);
		 
		 cout<<"Enter total hours of work (weekly) : ";
		 cin>>hour;
		 
		 //process
		 gross=grosspay(hour);
		 deduction= (0.08*gross) + (0.11*gross) + 10 ;
		 net=gross-deduction;
		 
		 if(gross>highest)
		     { highestname=name;
		       highest=gross;
		     }
		     
		if (gross<1200)
		   underpaid++;
		     
		 cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		 cout<<"Employee id= "<<id<<endl;
		 cout<<"Employee name= "<<name<<endl;
		 cout<<"Total gross pay = RM"<<gross<<endl;
		 cout<<"Total deduction = RM"<<deduction<<endl;
		 cout<<"Total net pay = RM"<<net<<endl;
		 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		 
		 employee++;
		 cout<<"\nDo you want to stop ? (y/n) : ";
		 cin>>answer;
		 cout<<endl;
    }  
    cout<<"______________________________________________________________\n";
    cout<<"The total number of employee is : "<<employee<<endl;
    cout<<"The highest paid is : "<<highestname<<" , RM"<<highest<<endl;
    cout<<"Total underpaid employee is : "<<underpaid<<endl;
    cout<<"______________________________________________________________\n";
    
}

double grosspay (int hour )
{
	 //declare variable
	 double salary;
	 
	 if(hour<=40)
	     salary=hour*8;
	 else if (hour>40 && hour<=50)
	     salary= 40*8 + ( (hour-40)*12 );
	 else
	     salary= 40*8 + 10*12 + ( (hour-50)*16 );
	     
	return salary;
	
}


