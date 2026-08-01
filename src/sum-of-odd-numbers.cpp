#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int n , total ;
	total=0;
	n=101;
	cout<<"Program to count even data"<<endl<<endl;
	while (n<200)
	{
	     cout<<n<<" , ";
	    
	     n=n+2;
	    
	     total+=n;
   }
    cout<<endl<<endl;
	cout<<"The total sum off number is = "<<total<<endl;
	
	return 0 ;
	
}
