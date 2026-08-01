#include <iostream>
using namespace std ;
int main(){
	
	double data , total ;
	
	cout<<"Tax to pay for a peice of land"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	
	cout<<"Enter the land size (acres) = ";
	cin>>data;
	cout<<endl<<endl;
	
	if(data>500)
        total=data*50;//rate=10
	else
	
	    if(data>100)
	       total=data*35;
	    else
	
	        if(data>49)
	           total=data*20;
	        else
               total=data*10;
	
	cout<<"The amount to pay is RM "<<total;
	cout<<endl;
	cout<<"Thank you !";
	cout<<endl;
	
	return 0;
	
	
	
}
