#include <iostream>
using namespace std;

main(){
	
	double base , height , area ;
	
	cout<<"~ Calculate the area of Triangle ~ "<<endl;
	cout<<"____________________________________";
	cout<<endl<<endl;
	
	//input
	cout<<"Enter base = ";
	cin>>base;
	
	cout<<"Enter height = ";
	cin>>height;
	
	//process
	area = (0.5)*base*height ;
	cout<<endl;
	
	//output
	cout<<"The area of triangle is = "<<area<<endl;
	cout<<endl<<endl<<endl;
	
	return 0;
	
	
	
}
