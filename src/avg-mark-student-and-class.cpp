#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int n,numstudent;
	double test1,test2,sumofmark,avgstudent,totalmark,avgclass;
	
	
	cout<<"System to count average mark " <<endl<<endl;
	cout<<"Enter number of students : ";
	cin>>numstudent;
	
	n=0;
	totalmark=0;
	while(n<numstudent){
	
	cout<<"\n"<<"Student"<<n+1<<endl;
    cout<<"Enter mark for test 1 : ";
    cin>>test1;
    
    cout<<"Enter mark for test 2 : ";
    cin>>test2;
    
    avgstudent=(test1+test2)/2.0;
    cout<<"Average mark of a student is = "<<avgstudent<<endl;
    
    sumofmark= test1*0.4 + test2*0.6;
    cout<<"Final score for student is : "<<sumofmark<<endl;
    
    totalmark+=sumofmark;
    n++;
	}
	
	cout<<"\n\n";
	avgclass=totalmark/numstudent;
	cout<<"The average mark for final score of the class is = "<<avgclass;
	
	return 0;
	
} 
