#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void nextDay(int & day , int & month , int & year)
{	
	//month that have 31 day
    if ( (day==31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10) )
	    {
	   	     day=1;
	   	     month=month+1;
	    } 
	
	//endofdec   
    else if (day==31 && month==12)
    {   
         day=1;
         month=1;
         year=year+1;
	}
 
    //end of feb
    else if ( (day==28 || day==29) && (month==2) )
    {
    	day=1;
    	month=3;
	}
	//end of the month that have 30 days
	else if( (day==30) && ( month==4 || month==6 || month==9 || month==11 || month==2) )
	{
		day=1;
		month=month+1;
	}
	//other day
	else 
	{
		day=day+1;
	}
	
}

int main(){
	
	int day , month , year;
	char answer='N';
	
	cout<<"Program to count next day dd//mm/yy \n\n";
	
	while (toupper(answer)!='Y')
    {
		cout<<"Enter day (number) = ";
		cin>>day;
		
		cout<<"Enter month (number) = ";
		cin>>month;
		
		cout<<"Enter year (number) = ";
		cin>>year;
		
		cout<<"The date given is : "<<day<<" / "<<month<<" / "<<year;
		//process
		nextDay (day , month , year);
		cout<<"\nThe next day is : "<<day<<" / "<<month<<" / "<<year<<endl<<endl;
		
		cout<<"Do you want to stop ? (Y/N) = ";
		cin>>answer;
		
		cout<<endl<<endl;
   }
	return 0;
}
