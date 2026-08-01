#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int student , i, activity , qualified=0;
	double point , totalpoint , highest=0.0 , lowest=9999.99 ;
	string name , highestname , lowestname;
	
	cout<<"Enter number of students = ";
	cin>>student;
	cin.get(); 
	cout<<endl;
	
	for (int n=0 ; n<student ; n++)
	{
		cout<<"Student"<<n+1<<endl;
		
		cout<<"Enter your name : ";
		getline(cin,name);
	
		cout<<"Enter number of activity : ";
		cin>>activity;
		
		totalpoint=0;
		//repeat taken point of each activity
		for (i=0 ; i < activity ; i++)
		{   
		    cout<<"Enter point for activity "<<i+1<<" = ";
		    cin>>point;
		    
		    totalpoint+=point;	
		}
		
		cout<<"\nYour total point is = "<<totalpoint<<endl<<endl;
		
		//count up the student who qualified 
		if (totalpoint>100)
		    qualified++;
		  
		 // highest point  
		if (totalpoint>highest)
		{
			highestname=name;
			highest=totalpoint;
		}
		
		//lowestpoint
		if (totalpoint<lowest)
		{
			lowestname=name;
			lowest=totalpoint;
		}
		
		cin.get();
	}
	cout<<endl<<endl;
	cout<<"The number of student who qualify for the college is : "<<qualified<<endl;
	cout<<"The highest point recorded is = "<<highestname<<" , "<<highest<<endl;
	cout<<"The lowest point recorded is = "<<lowestname<<" , "<<lowest<<endl;
	
}
	
