#include <iostream>
using namespace std;

int main(){
	
	int capital , worker ;
	
	cout<<"Determine A High-Technology Company "<<endl<<endl;
	
	cout<<"Enter total capital of company : RM";
	cin>>capital;
	
	cout<<"Enter total IT workers = ";
	cin>>worker;
	
	bool condition1= capital>=50000 && capital<100000 && worker>=5;
	bool condition2= capital>=100000 && worker>=10;
	
	cout<<endl<<endl; 
	
	if (condition1||condition2)
	   cout<<"You are A High-Tech company";
	   
	else
	   cout<<"Sorry you are NOT A High-Tech company";
	   
 
 return 0 ;
	
	
}
