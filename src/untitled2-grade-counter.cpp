#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	
	double mark;
	int numgrade[4]={0} , highest=0 , highestindex=0;
	char answer='N' , grade;
	
	while(toupper(answer)!='Y')
	{
		cout<<"Enter your mark = ";
		cin>>mark;
		
		if(mark>=80)
		   numgrade[0]++;
		   
		else if(mark>=65 && mark<=79)
		   numgrade[1]++;
		   
		else if(mark>=50 && mark<=64)
		   numgrade[2]++;
		
	    else 
		   numgrade[3]++;
		   
		cout<<"Do you want to stop (y/n) ? : ";
		cin>>answer;
		
		cout<<endl;	   	   
	}
	
	//display grade
	cout<<"The number of students who's get grade 'A' is = "<<numgrade[0]<<endl;
	cout<<"The number of students who's get grade 'B' is = "<<numgrade[1]<<endl;
	cout<<"The number of students who's get grade 'C' is = "<<numgrade[2]<<endl;
	cout<<"The number of students who's get grade 'D' is = "<<numgrade[3]<<endl<<endl;
	
	//count highest
	highest=numgrade[0];
	for (int x=1 ; x<4 ; x++)
	{
		if (numgrade[x]>highest)
		    highest=numgrade[x];
	}
	//display highest
	cout<<"The most popular grade is :- \n";
	for (int y=0 ; y<4 ; y++)
	{
		if (highest==numgrade[y])
            {
              highestindex=y;
				
			  if(highestindex==0)
			     grade='A';
			     
			  else if (highestindex==1)
			     grade='B';
			     
			  else if (highestindex==2)
			     grade='C';
			     
			   else
			     grade='D';
            	
               cout<<"Grade "<<grade<<" , ";
			}
	  	
	}
	

	
}

