#include <iostream>
using namespace std;

int main(){
double a , b , answer ;

cout<<"Enter two numbers: ";
cin>>a>>b;

if(b==0)
{   cout<<"Cannot divide by zero"<<endl;
	cout<<"Sorry"<<endl;
}
else
{   answer=a/b;
    cout<<"The answer is "<<answer<<endl;
}	
return 0 ;
}
