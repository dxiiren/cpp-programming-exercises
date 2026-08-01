#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int i , n , t1=1 , t2=1 , nextTerm=0;
	
	cout<<"Enter the number of terms : ";
	cin>>n;
	
	cout<<"Fibonacci Series: ";
	
	cout<<t1<<" "<<t2<<" ";
	
	for (i=2 ; i<n ; i++)
	{
		nextTerm=t1+t2;
		cout<<nextTerm<<" ";
		t1=t2;
		t2=nextTerm;
	}
	return 0;
}
