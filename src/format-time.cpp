#include <iostream>
using namespace std;

main(){
	
	int data , data1 , data2;
	
	cout<<"Enter the current time ( Exm: 0934 / 1425 ) "<<endl;
	cout<<"Time = ";
	cin>>data;
	
	if (data>=2400 || data<1200)
	
	
	{
	data1=data/100;
	if(data>11)data1=data1-12;
	if(data1<1)data1=data1+12; 
	cout<<"The time now is "<<data1<<":";
     
     data2=data%100;//data2
     if(data2<10)cout<<"0";//if ini untuk memberi nilai kosong  sekrinya jumlah yang terhasil adalh 0X , supaya komputer boleh baca kosong di hadapan
     
     cout<<data2<<" am."<<endl;  
	}
	
	else{
		
	  
	 if (data<1300)data=data+1200;
     data1=data/100-12;
     
     cout<<"The time now is "<<data1<<":";
     
     data2=data%100;
     if(data2<10)cout<<"0";//if ini untuk memberi nilai kosong  sekrinya jumlah yang terhasil adalh 0X , supaya komputer boleh baca kosong di hadapan
     
     cout<<data2<<" pm."<<endl;
}
	
	return 0 ;
	
	
}


