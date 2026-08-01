#include <iostream>
using namespace std;

int main(){
	//declare variable
	int data;
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	//input
	cout<<"Enter number between 1000 to 50,000 = ";
	cin>>data;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<endl<<endl;
	
	
	//process
	int num = data%1000 ; 
	if ( data >= 1000 & data <50000){
	
	//output
	cout<< "The number that you type is ="<<(data-num)/1000<<",";
	if (num<100)cout<<"0"; 
	if (num<10)cout<<"0"; 

    cout<<num<<endl; 
    
	
    }else cout <<"Your number is not valid";
	return 0;
	
}
