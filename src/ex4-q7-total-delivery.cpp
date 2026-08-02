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
	     
	else if(toupper(delivery)=='W')
	    return 20;
	else    
	return 0;
}

int main() {

    char area;
    double weight , charge , total , sumall=0 , highest=0 , lowest=99999;
    int n;
    
    for (n=0 ; n<20 ; n++ )
   {    cout<<"Parcel "<<n+1<<endl;
   
        cout<<"Please enter weight : ";
	    cin>>weight;
	    
	    cout<<"N = North \n";
	    cout<<"S = South \n";
	    cout<<"E = East \n";
	    cout<<"W = West \n";
	    
	    cout<<"Please enter delivery zone ( N/S/E/W) : ";
	    cin>>area;
	    
	    //process
	    charge = mass(weight)+zone(area);
	    total=charge + charge * 0.05;
	    
	    if (total>highest)
	         highest=total;
	         
	    
	    if (total<lowest)
	         lowest=total;
	    
    
        cout<<"The total charge is = RM \n\n"<<total;
        sumall+=total;
   }
    cout<<"The total charge of all 20 packages is "<<sumall<<endl;
    cout<<"The lowest cost is Rm"<<lowest<<endl;
    cout<<"The highest cost is Rm"<<highest<<endl;
    
    return 0;
    
}
