#include <iostream>
using namespace std;

main(){
	
	//declarevariable
	double senior,adult,children,kid,seniorprice,adultprice,childrenprice,kidprice,total,price ;
	
	//headline
	
	cout<<"---------------------"<<endl;
	cout<<"Calculate The Total Price of Tickets "<<endl;
	cout<<"---------------------"<<endl<<endl;
	//
	cout<<"---->Press Enter to continue<----"<<endl<<endl;
	
	cout<<"1)Enter the price of the ticket =RM ";
	cin>>price;
	cout<<endl;
	
	cout<<"2)Enter the number of people according to their category ;"<<endl;
	
	//information
	cout<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    
	cout<<" Senior Citizen = ( 60 YEARS OLD & ABOVE )"<<endl;
	cout<<" Adult          = ( 13 ~> 59 YEARS OLD )"<<endl;
	cout<<" Children       = ( 4 ~> 12 YEARS OLD )"<<endl;
	cout<<" Kid            = ( 3 YEARS OLD & BELOW )"<<endl;
	
	cout<<"-------------------------------------------------------"<<endl<<endl;
	
	//input
	cout<<"Senior Citizen = ";
	cin>>senior;
	
	cout<<"Adult = ";
	cin>>adult;
	
	cout<<"Children = ";
	cin>>children;
	
	cout<<"Kid = ";
	cin>>kid;
	
	//process	
	seniorprice = senior*(price-(price*0.4));
	adultprice = adult*price;
	childrenprice = children*(price-(price*0.5));
	kidprice = kid*(price-price);
	
	total=seniorprice+adultprice+childrenprice+kidprice;
	
	//output
	cout<<endl;
	cout<<"~ The total price of the ticket is =RM "<<total<<" ~"<<endl;
	cout<<" Thank You ";
	
	return 0;
	
}
	
	
