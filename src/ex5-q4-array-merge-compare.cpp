#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	const int SIZE=5;
	double a[SIZE] , b[SIZE] , c[SIZE] , d[SIZE] ;
	
	//input data
	for (int n=0 ; n<SIZE ; n++)
	{
		cout<<"Enter data 1 : ";
		cin>>a[n];
		
		cout<<"Enter data 2 : ";
		cin>>b[n];
		
		cout<<endl;
	}
	cout<<endl;
	
	//add data of array a and b into array c
	for (int i=0 ; i<SIZE ; i++)
		c[i]=a[i]+b[i];
	
	//display array c
	cout<<"The list of number in array c is :- \n";
	for (int j=0 ; j<SIZE ; j++)
	   	cout<<c[j]<<endl;
	
	//compare data which in larger between array a and b , then store in array d
	for (int x=0 ; x<SIZE ; x++)
	{
		if( a[x] > b[x] )
		      d[x]=a[x];
		
		else
		      d[x]=b[x];
	}
	
	//display array d
	cout<<"\nThe list of number in array D is :- \n";
	for (int y=0 ; y<SIZE ; y++)
	   	cout<<d[y]<<endl;
	}
