#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	for( int line=1 ; line<=4 ; line++ )
	{
		for (int n=4 ; n>=line ; n--)
		     cout<<"?";
		     
		cout<<endl;	
	}
	
	for( int line=2 ; line<=4 ; line++ )
	{
		for (int n=1 ; n<=line ; n++)
		     cout<<"?";
		     
		cout<<endl;	
	}
	
}
