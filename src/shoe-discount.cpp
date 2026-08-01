#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string shoe ;
	float price , num , total ;
	
	cout<<"Calculate price after discount"<<"\n\n";
	cout<<"Type of shoes = A , B , C , D(others)"<<"\n";
	
	cout<<"Please enter type of shoes : ";
	getline(cin,shoe);
	
	cout<<"Enter price of the shoe : ";
	cin>>ws;
	cin>>price;
	
	cout<<"Enter number of shoe : ";
	cin>>ws;
	cin>>num;

	if (shoe == "A" || shoe== "a")
	total=num*price*0.90;  
	
	else if (shoe == "B" || shoe== "b" )
	   {if(num>1)
	    total=num*price*0.80;
	    else
        total=num*price*0.85;} 
        
	else if (shoe == "C" || shoe== "c")
	   { if(num>1)
	       total=num*price*0.75;
	    else
            total=num*price*0.80;}
	
	else
	  total=num*price;

	cout<<"Total Price After Discount is = RM"<<total<<endl;
	
	
	return 0;
}
