#include <iostream>
using namespace std;

main(){
	
	//declarevariable
    double price,discount,priceafterdiscount ;
	
	//headline
	cout<<"~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_"<<endl;
	cout<<"Total Price After Discount"<<endl;
	cout<<"~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_"<<endl<<endl;
	cout<<"Enter The Price of an item & discount"<<endl<<endl;
	
	//input
	cout<<"Price of an item = ";
	cin>>price;
	
	cout<<"Discount rates % :  ";
	cin>>discount;
	
	//process
	priceafterdiscount=price-(price*(discount/100.00));
	
    //output
    cout<<endl;
    cout<<"---------------"<<endl;
    cout<<"The Result :"<<endl;
    cout<<"---------------"<<endl;
    
    cout<<"Price before disount = RM "<<price<<endl;
    cout<<"Price after discount : RM "<<priceafterdiscount<<endl;
    
    return 0 ;
    
}
	
