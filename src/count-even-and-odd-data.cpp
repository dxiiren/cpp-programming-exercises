#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int n , data , evenNum=0 , oddNum=0 ;
	
	cout<<"Program to count even and odd data"<<endl<<endl;
	for (n=0 ; n<10 ; n++)
	{     
	     cout<<"Please enter data = ";
	     cin>>data;
	     
	     if (data%2==0)
	         evenNum++;
	     else
	         oddNum++;    
   }
   
   cout<<endl;
   cout<<"Total number of even number :"<<evenNum<<endl;
   cout<<"Total number of odd number :"<<oddNum<<endl;
   
   return 0;
   
}
