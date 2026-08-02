#include <iostream>
#include <string>
using namespace std;

void nextDay(int & day , int & month , int & year)
{	
	//first day of the month
	if (day==1)
	{
		//month that have 31 day previous
		if ( month==4 || month==6 || month==9 || month==11 || month==2)
		{
			day=31;
			month= month-1;
		}
		
		// check for the leap year
		else if ( month==3)
		{
			if (year%4==0)
			    day=29;
			else
			     day=28;
			     
			month=2;
		}
		
		//first oh jan
		else if (month==1)
		{
			day=31;
			month=12;
			year=year-1;
		}
		
		//other month
		else 
		{
			day=30;
			month=month-1;
		}
		
	}
	else
	     day=day-1;	
	
}

int main(){
	
	int day , month , year;
	
	cout<<"Enter day (number) = ";
	cin>>day;
	
	cout<<"Enter month (number) = ";
	cin>>month;
	
	cout<<"Enter year (number) = ";
	cin>>year;
	
	cout<<day<<" / "<<month<<" / "<<year;
	
	//process
	nextDay (day , month , year);
	cout<<"\nThe previous day is : "<<day<<" / "<<month<<" / "<<year;
	
	return 0;
}
