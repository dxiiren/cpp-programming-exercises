#include <iostream>
#include <string>
#include <cctype>
using namespace std;


void nextWeek(int & day , int & month , int & year)
{	
	//month that ends with 31 day
	if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10) 
	   {
		 if (day>=25 && day<=31)
	   	    {   
	   	        day=(day+7)-31;
	   	        month=month+1;
	   	    }
	   	 else
	        day=day+7;
        } 
		  
	//february     
	else if (month==2)  
	{
		if (year%4==0 ) //leap year
		{    
		    if (day==22)
				   day=29;
				 	 
	        else if (day>=23 && day<=29)
		   	    {
				 day=(day+7)-29;
				 month=3;
	     		}   
	   	    else
	   	        day=day+7;   
	    }
	   else //normal year in feb
	   {    
	       if (day>=22 && day<=29)
		   	    {
				 day=(day+7)-28;
				 month=3;
	     		}   
	   	    else
	   	        day=day+7;   
       }  
   }
   
	//december   
    else if (month==12)
	   {
		 if (day>=25 && day<=31)
	   	    {   
	   	        day=(day+7)-31;
	   	        month=1;
	   	        year=year+1;
	   	    }
	   	 else
	        day=day+7;
        }   
	
	//other month that ends with 30 days
	else if (month==4 || month==6 || month==9 || month==11)
	{
		 if (day>=24 && day<=30)
	   	    {   
	   	        day=(day+7)-30;
	   	        month=month+1;
	   	    }
	   	 else
	        day=day+7; 
	}
	
	//other normal other  
	else 
	    day=day+7;		 		
}

int main(){
	
	int day , month , year , n;
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
		
		nextWeek (day , month , year);
		cout<<"\nThe next week is : "<<day<<" / "<<month<<" / "<<year<<endl<<endl;
		
		cout<<"Do you want to stop ? (Y/N) = ";
		cin>>answer;
		
		cout<<endl<<endl;
   }
	return 0;
}
