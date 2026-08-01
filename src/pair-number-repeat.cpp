#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int n=0, no1,no2,sum=0 , largest=-99999 , larger500=0 , largex , largey ;
	cout<<"Type 2 number : ";
	cin>>no1>>no2;
	
	while(no1!=no2)
	{
	  sum=no1+no2;
	  cout<<"Sum of pair "<<n+1<<" is= "<<sum<<endl;
	  n++;
	  
	  if (sum>largest)
	   {
		 largest=sum;
	     largex=no1;
	     largey=no2;
       }
	  if (sum>500)  
		   larger500++;
	  
	  cout<<"\n"<<"Type 2 number : ";
	  cin>>no1>>no2;
	}
	
	if(sum!=0)
	{
	     cout<<"\n"<<"The number of pair that larger than 500 is "<<larger500<<endl;
		 cout<<"The largest sum is = "<<largest<<" "<<largex<<" , "<<largey<<endl;
    }
	else
	     cout<<"No data given "<<endl;
	return 0;
	
}
	
