#include <iostream>
using namespace std;

int typeofnumber (int & num )
{
	if (num%2 !=0)
	    num = 1;
	else
	    num = 0;
	
}

int main()
{
	
	int num;
	
	cout<<"Enter a number ";
	cin>>num;
	
	typeofnumber(num);
	
	if (num != 0)
	   cout<<"The number is odd";
	else 
	   cout<<"The number is even";
	   

	return 0;
}
