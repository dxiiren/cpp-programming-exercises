#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	//declare variable
	char type , answer='n',most2;
	double price , percent, total=0 , comission ;
	int item,a=0 ,b=0 ,c=0 ,d=0, most;
	
	cout<<"Type of items ;"<<endl;
	cout<<"(A) = Microwave oven "<<endl;
	cout<<"(B) = TV "<<endl;
	cout<<"(C) = Stereo "<<endl;
	cout<<"(D) = Refrigerator "<<endl;
	
	while(toupper(answer)!='Y')
	{
	     cout<<"\n"<<"Enter type of item =";
	     cin>>type;
	     
	     cout<<"Enter the price =";
	     cin>>price; 
	     
	     cout<<"Enter quantity of item =" ;
	     cin>>item;
	     
	     if ((toupper(type)=='A')|| (toupper(type)=='B') || (toupper(type)=='C') || (toupper(type)=='D') )
	     
		    { if (toupper(type)=='A')
		        { percent=0.08;
		          a+=item;
		        }
		     else if (toupper(type)=='B')
		                 { percent=0.10;
		                   b+=item;
		                 }
		     else if (toupper(type)=='C')
		                 { percent=0.12;
		                   c+=item;
		                 }
		     else
		                { percent=0.09;
		                  d+=item;
	                    }
		                        
			 comission=price*item*percent;
			 total+=comission;
		   }
		else
		    cout<<"\n"<<"The type of item you enter does not exist"<<endl;
			 
		cout<<"\n"<<"Do you want to stop (y/n) ? :";
		cin>>answer;  
	          
   } 
   most=0;
   if(a>most)
    {
	  most=a;
      most2='A';
    }
   
   if(b>most)
    {
	  most=b;
      most2='B';
    }
   if(c>most)
    {
       most=c;
	   most2='C';	
	}
   if(d>most)
    {
	   most=d;
	   most2='D';
     
	}
   cout<<"\n"<<"Total Comission to be paid is RM "<<total<<endl;
   cout<<"The most item that have been sold is type "<<most2<<" = "<<most<<" item"<<endl;
   
   return 0 ;
   
}
	
	
	
	
	
