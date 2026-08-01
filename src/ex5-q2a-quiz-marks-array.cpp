#include <iostream>
using namespace std;

int main(){
	
	double total=0 , avg=0;
	
	double mark[4];
	
	for (int n=0; n<4 ; n++)
	{
	    cout<<"Enter marks for the quiz = ";
	    cin>>mark[n]; 
		
	}
	
	for (int x=0 ; x<4 ; x++)
	{	
		total+=mark[x];
	}
	
    cout<<"The total is "<<total;
    avg=total/4.0;
    cout <<endl;
    
    cout<<"The average is "<<avg;
    cout<<endl<<endl;
    
	cout<<"\nThe mark that higher than average is :- \n";
	for (int x=0 ; x<4 ; x++)
	{	
		if (mark[x]>avg)
		   cout<<mark[x]<<endl;
	}
    
}
