#include <iostream>
#include <string>
using namespace std;

int main(){
	
	//declare variable
	int i , n ;
	float t1, t2 , total=0 ,sum;
	
	cout<<"Enter the number of terms : ";
	cin>>n;
	
	cout<<"\n"<<"Series of number = ";
	
	for (i=1 ; i<=n ; i++)
	{
		t1=i*2;
		t2=i*3;
		cout<<t1<<"/"<<t2<<" ";
		sum=t1/t2;
		total+=sum;
	}
	cout<<endl<<endl;
    cout<<"The total sum is = "<<total;
	return 0;
}
