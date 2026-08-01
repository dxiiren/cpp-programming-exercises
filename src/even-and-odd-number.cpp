#include <iostream>
using namespace std;

int main(){
	
	int number;
	
	cout<<"Enter a number : ";
	cin>>number;
	
	cout<<endl<<endl;
	
	if(number%2==0)
	cout<<number<<" is an even number"<<endl;
	
	else
	{
	number++;
	cout<<number<<" is new number"<<endl;
	}
	
}
