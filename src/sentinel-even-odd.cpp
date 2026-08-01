#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int n, data , evenNum=0 , oddNum=0 , highest=-99999 , lowest=99999 ;
	
	cout<<"Program to count even and odd data"<<endl<<endl;
	cout<<"Please enter data (Type 0 to stop) = ";
	cin>>n;
	
	while (n!=0)
	{
	     if (n%2==0)
	         evenNum++;
	     else
	         oddNum++; 
	         
	     if (n>highest)
		   highest=n;
		   
		 if (n<lowest)
		   lowest=n;
		   
		cout<<"Please enter data (Type 0 to stop) = ";
	    cin>>n;
   }
   cout<<endl;
   cout<<"Total number of odd number is "<<oddNum<<endl;
   cout<<"Total number of even number is "<<evenNum<<endl;
   cout<<"The highest data is "<<highest<<endl;
   cout<<"The lowest data is "<<lowest<<endl;
   
   return 0 ;
}
   
   
