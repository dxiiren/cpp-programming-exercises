#include <iostream>
using namespace std;

int main(){
	
    float rain[12] , avg;
    int total=0 , highest=0 , highestindex , lowest=9999 , lowestindex;
    
    for (int n=0; n<12 ; n++)
	{
	    cout<<"Enter total rain in Kuala Terengganu for month"<<n+1<<" = ";
	    cin>>rain[n]; 
    }
    
    for (int x=0; x<12 ; x++)
	{
	    total+=rain[x];   
    }

    cout<<"\nThe total rainfall for a year is "<<total;
     
    for (int y=0; y<12 ; y++)
	{
	    if (rain[y]>highest)
	    
	       {  highest=rain[y];
	           highestindex=y;
		   }	   
    }
    
    for (int z=0; z<12 ; z++)
	{
	    if (rain[z]<lowest)
	    
	       {  lowest=rain[z];
	           lowestindex=z;
		   }	   
    }
    
     cout<<endl;
     cout<<"The month with the lowest rainfall is month "<<lowestindex+1<<" which is "<<lowest<<" time(s)";
     cout<<endl;
     cout<<"The month with the highest rainfall is month "<<highestindex+1<<" which is "<<highest<<" time(s)";
     cout<<endl<<endl;



    avg=total/12;
    cout<<"The month(s) where the rainfall is higher than average is :- \n";
    for (int a=0; a<12 ; a++)
	{
	    if (rain[a]>avg)
	       cout<<"month "<<a+1<<endl;
    }

     
    return 0 ;
}
