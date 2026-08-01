//Program to add 2 numbers given by a user
#include <iostream> // cin/cout-> input/output
using namespace std;

int main()
{
	// variable declaration
	int data1,data2,answer;
	//input
	cout<<"Adding two numbers "<<endl;
	cout<<"............................."<<endl<<endl<<endl;

	cout<<" Enter first number . ";
	cin>>data1;
	
	cout<<" Enter second number . " ;
	cin>>data2;
	
	cout<<endl<<endl<<endl;
	
	//process
	answer=data1+data2;
	
	//output
	cout<<"The answer is = "<<answer<<endl;
	
	return 0;
	
	
}

