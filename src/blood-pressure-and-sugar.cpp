#include <iostream>
#include <string>
using namespace std;

int main(){
	
	double bloodpressure , diabetes , numseriousproblem , numbp , numdiabetes;
	int n;
	
	n=0;
	numseriousproblem=0;
	numbp=0;
	numdiabetes=0;
	
	cout<<"Program to count bp and diabetes"<<endl;
	while (n<5){
         
		 cout<<endl<<"Patient"<<n+1<<endl;	
	     cout<<"Please enter number of blood pressure= ";
	     cin>>bloodpressure;
	     
	     cout<<"Please enter number of sugar level= ";
		 cin>>diabetes;
		 
		    if (bloodpressure>130 && diabetes>=10)
               numseriousproblem++;
       
            if ( bloodpressure>130)
               numbp++;
     
            if (diabetes>=10)
               numdiabetes++;
		 
		 n++;
   }
    cout<<endl<<endl;
    cout<<"Number people who have high blood pressure is : "<<numbp<<endl;
    cout<<endl;
    cout<<"Number people who have diabetes is : "<<numdiabetes<<endl;
    cout<<endl;
    cout<<"Number of people who have serious health problem ( diabetes and high blood pressure ) is : "<<numseriousproblem;
    cout<<endl;
    
    return 0;
    
}
     
