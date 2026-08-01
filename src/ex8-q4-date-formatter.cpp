#include <iostream>
#include <string>
using namespace std;

void date (int & day , int & month , int & year , string & month2 )
{
	if (month==1)
	    month2="January";
	    
	else if (month==2)
	    month2="February";

	else if (month==3)
	    month2="March";

	else if (month==4)
	    month2="April";
	    
	else if (month==5)
	    month2="May";
	    
	else if (month==6)
	    month2="June";
	    
	else if (month==7)
	    month2="July";	    

	else if (month==8)
	    month2="August";

	else if (month==9)
	    month2="September";
	    
	else if (month==10)
	    month2="October";
	    
	else if (month==11)
	    month2="November";
	    
	else
	    month2="December";
	    
	//display
	cout<<day<<" "<<month2<<" "<<year;
}

int main()
{
	int day=1, month=1 , year;
	string month2 ;
	
	while (day>0 && month>0)
    {		
		cout<<"Enter day (number) = ";
		cin>>day;
		
		cout<<"Enter month (number) = ";
		cin>>month;
		
		cout<<"Enter year (number) = ";
		cin>>year;
		
		if (day != 0 && month != 0)
		{
			date(day , month , year , month2);
			cout<<endl<<endl;
	    }
    }
  
	cout<<"\nWrong Data !";
	
	return 0;
	
	
}
