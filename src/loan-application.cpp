#include <iostream>
using namespace std;

int main(){
	
	double loan,yearlyincome,rates,years,totalpayment;
	
	cout<<"Programs to determine loan applicaton"<<endl;
	cout<<"_____________________________________"<<endl;
	
	cout<<"Enter amount of loan to be apply :RM";
	cin>>loan;
	
	cout<<"Enter total income for a year = RM";
	cin>>yearlyincome;
	
	cout<<"Enter total year of taking a loan (years):";
	cin>>years;
	
	cout<<"--------------------------------------";
	cout<<endl<<endl<<endl;
	//process
	
		
	    if( (loan<3*yearlyincome &&years<5) || (loan<5*yearlyincome && years>=5))
		{  rates=0.04*loan;
		   totalpayment = loan/years/12 + rates;
	        cout<<"Congratulation you are applicable to apply a loan"<<endl;
	        cout<<"Your total payment of "<<loan<<" MYR loan"<<"  is = RM "<<totalpayment<<" per month"<<endl;
	    }
	    else
	    {   cout<<"Sorry your not applicable to apply that amount of loan"<<endl;//3
	        cout<<"You could try another amount "<<endl;}//3
	
	cout<<"Thank you";
	
	return 0;

}
