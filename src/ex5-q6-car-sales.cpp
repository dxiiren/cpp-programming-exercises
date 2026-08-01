#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	const int size=5;
	long total[size] , overall ;
	double price[size]={90000,47500,60000,73200,51000} ;
	int numcar[size] , highest;
	
	//input data
	for (int n=0 ; n<size ; n++)
	{
	   cout<<"Enter number of cars sold for type "<<n+1<<" = ";
	   cin>>numcar[n];
	   cout<<endl;	
	}
	
	//calculate sales of each type of car = total sale
	for (int i=0 ; i<size ; i++)
	{
		total[i] = numcar[i] * price[i];
		overall+=total[i];
	}
	
	//calculate the most popular car sold
	highest=numcar[0];
	for (int x=1 ; x<size ; x++)
	{
	     if(numcar[x] > highest)	
	         highest=numcar[x];
	}

	//display total sales each car
	cout<<"The total sales for each car is :- \n";
	cout<<"Type A = RM"<<total[0]<<endl;
	cout<<"Type B = RM"<<total[1]<<endl;
	cout<<"Type C = RM"<<total[2]<<endl;
	cout<<"Type D = RM"<<total[3]<<endl;
	cout<<"Type E = RM"<<total[4]<<endl<<endl;
	
	//display overall sale
	cout<<"The overall sell for all type of car is = RM"<<overall<<endl;
	
	//display the most popular car
	cout<<"\nThe most popular car sold is type :- \n";
	for (int y=0 ; y<size ; y++)
	{
	     if(highest==numcar[y])
	        cout<<"Type "<<y+1;
	        cout<<endl;
	}

	
	}
