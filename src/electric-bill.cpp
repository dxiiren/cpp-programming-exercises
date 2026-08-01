#include <iostream>
using namespace std;
int main(){
	
	double data,priceA,priceB,priceC,priceD,price,totalprice;
	cout<<"Calculate electric bill "<<endl;
	cout<<"------------------------"<<endl;
	
	cout<<"Enter number of units = ";
	cin>>data;
	cout<<endl<<endl;
	
	//process
	priceA=100*0.1;
	priceB=500*0.3;
	priceC=500*0.5;
	priceD=(data-1100)*0.7;
	
	if(data<=100)
	{price=data*0.1;
	cout<<"Total amount to pay is =RM"<<price;}
	else
		if(data<=600)
		{data=data-100;
		price=data*0.3;
		totalprice=priceA+price;
		cout<<"Total amount to pay is = RM"<<totalprice;}
	else
		if(data<=1100)
		{data=data-600;
		price=data*0.5;
		totalprice=priceA+priceB+price;
		cout<<"Total amount to pay is =RM"<<totalprice;}
	else
	{totalprice=priceA+priceB+priceC+priceD;
	cout<<"Total amount to pay is =RM"<<totalprice;}
	
	return 0;
	
	
}
