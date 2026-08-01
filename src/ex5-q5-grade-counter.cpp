#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	double mark;
	int numgrade[4]={0} ,highest=0 , highestindex=0;
	char answer='N' , grade ;
	
	while (toupper(answer)!='Y'){
		
			cout<<"Enter your mark = ";
			cin>>mark;
			
			if (mark>=80)
			   numgrade[0]++;
			
			else if (mark>=65 && mark<=79)
			   numgrade[1]++;
			   
			else if (mark>=50 && mark<=64)
			   numgrade[2]++;
			
			else 
			   numgrade[3]++;
			
		cout<<"Do you want to stop (y/n) : "  ;
		cin>>answer;
		cout<<endl;
		
	}

	cout<<" Number of students who get grade 'A' is : " <<numgrade[0]<<endl;
	cout<<" Number of students who get grade 'B' is : " <<numgrade[1]<<endl;
	cout<<" Number of students who get grade 'C' is : " <<numgrade[2]<<endl;
	cout<<" Number of students who get grade 'D' is : " <<numgrade[3]<<endl;
	
	for (int y=0; y<4 ; y++)
	{
	    if (numgrade[y]>numgrade[highest])
	    
	       { 
	           highest=y;
	           highestindex=y;
		   }	   
    }
    
    if (highestindex==0)
       grade='A';
       
    else if (highestindex==1)
       grade='B';
    
    else if (highestindex==2)
       grade='C';
       
    else 
       grade='D';
 
       
    cout<<"The popular grade is grade "<<grade<<" , Which have "<<numgrade[highest]<<" students";
    
    return 0 ;

}
