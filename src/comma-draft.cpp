#include <iostream>
using namespace std;

int main(){
	
	int data, data1 , data2;
	
	cout<<"Type a number greater than 1000 = ";
	cin>>data;
	
	if (data<=1000)
	cout<<"Your number is not valid ! ";
	
	else{
		
	data1=data/1000;
	cout<<"The number that you typed is: "<<data1<<",";//data2 akan ada disini
		
	data2=data%1000; // semua jumlah data 2 akan dibawa ke cout yang atas
	if(data2<100)cout<<"0";
	if(data2<10)cout<<"0";
	
	cout<<data2<<endl; //dia akan jadi gabungan (00 data2) dan isi cout yg adaa data 1
    }
	
	return 0 ;
	
}
