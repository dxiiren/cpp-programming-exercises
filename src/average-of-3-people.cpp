#include <iostream>
using namespace std;

main(){
	
	//declarevariable
	double A,B,C,sum,average;
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Calculate the average of 3 people"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	
	//input
	cout<<"Enter The Age for 3 People (A , B , C);"<<endl<<endl;
	cout<<"------>Press Enter to continue<------"<<endl<<endl;

	cout<<"A = ";
	cin>> A;
	
	cout<<"B = ";
	cin>> B;
	
	cout<<"C = ";
	cin>> C;
	
	//process
	sum = A+B+C ;
	average = sum/3 ;
	
	//output
	cout<<endl;
	cout<<"The average of 3 people is = "<<average<<endl;
	
	return 0;
}
	
	
	
	
	
	
