#include <iostream>
using namespace std;

int main(){
	
	//declarevariable
    double a,b,largernumber ;
	
	//headline
	
	cout<<"_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+"<<endl;
	cout<<"Determine Larger Number"<<endl;
	cout<<"_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+"<<endl<<endl;
	
	//input
	cout<<"-Enter 2 digits of number-"<<endl<<endl;
	
	cout<<"Enter the first number :";
	cin>>a;
	
	cout<<"Enter the second number :";
	cin>>b;
    
    //process
    largernumber= a;
    cout<<endl<<endl;
    
    //output
    if (b>a)
        largernumber=b;
        
    cout<<largernumber<<" is the larger number"<<endl;
    
    
	
	return 0;
}
