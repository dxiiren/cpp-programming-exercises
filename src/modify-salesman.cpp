#include <iostream>
#include <cctype>
using namespace std;

int main(){
	
	//declare variable
	char type , answer='n',answer2='y', most2;
	double price , percent, total=0 , comission , sumofcomission=0, avg;
	int item,a=0 ,b=0 ,c=0 ,d=0, i=0 , n,most;
	
	cout<<"Type of items ;"<<endl;
	cout<<"(A) = Microwave oven "<<endl;
	cout<<"(B) = TV "<<endl;
	cout<<"(C) = Stereo "<<endl;
	cout<<"(D) = Refrigerator "<<endl;
	
	 //cout<<"Do you wish to continue ?";
	 //cin<<answer2;
	 
	 while((toupper(answer2)!='N'))
	 
	    { cout<<"\n"<<"Salesman"<<i+1;
	       total=0;
	
	       {for (n=0 ; n>=0 ;)
		 
			    {cout<<"\n"<<"Enter type of item =";
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
				     else  if (toupper(type)=='D')
				                { percent=0.09;
				                  d+=item;
			                    }
				     else 
					     cout<<endl;
						  
					 comission=price*item*percent;
					 total+=comission;
				   }
				else
				cout<<"\n"<<"The type of item you enter does not exist"<<endl;
					 
				cout<<"Do you want to stop (Enter any positive number to continue or Enter any negative number to stop) ? :";
				cin>>n;  
			    }
		   }
		    cout<<"\n"<<"~>TOTAL COMISSION TO BE PAID FOR SALESMAN "<<i+1<<" IS RM "<<total<<endl;
		    sumofcomission+=total;
		    
		    i++;
		
		    cout<<"Next Salesman (y/n) ? :";
	        cin>>answer2;
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
   
    cout<<"\nThe most item that have been sold is type "<<most2<<" = "<<most<<" item"<<endl;	
	avg=sumofcomission/i;
    cout<<"\n\n"<<"~~ TOTAL COMISSION OF ALL SALESMAN IS = RM"<<sumofcomission<<" ~~"<<endl;
    cout<<"~~ AVERAGE TOTAL COMISSION OF ALL SALESMAN = RM"<<avg<<" ~~"<<endl;
   
   
   
   return 0 ;
   
}
	
	
	
	
	
