#include <iostream>
#include <cctype>
using namespace std;

double mass (double weight) {
	
	double charge;
	
	if (weight<10)
         charge=weight*5;
    else 
         charge= weight*3.5;
         
    return charge;
}

int zone ( char delivery ) {
	
	if(toupper(delivery)=='N')
	     return 35;
	     
	else if(toupper(delivery)=='S')
	     return 40;
	     
	else if(toupper(delivery)=='E')
	     return 15;
	     
	else if(toupper(delivery)=='E')
	    return 20;
	else    
	return 0;
}

int main() {

    char area;
    double weight , charge , total;
    
    cout<<"Please enter weight : ";
    cin>>weight;
    
    cout<<"N = North \n";
    cout<<"S = South \n";
    cout<<"E = East \n";
    cout<<"W = West \n";
    
    cout<<"Please enter delivery zone ( N/S/E/W) : ";
    cin>>area;
    
    charge = mass(weight)+zone(area);
    total=charge + charge * 0.05;
    
    cout<<"The total charge is = RM "<<total;
    
    return 0;
}
