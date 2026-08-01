#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	
    for (int line=1 ; line<=6 ; line++ )
    {    
        for (int n=1 ; n<=line ; n++)
            cout<<"*";
         
        cout<<endl;
	}
	
    for (int line=0 ; line<3 ; line++)
	    { cout<<"******";
	      cout<<endl;
        }
        
}
