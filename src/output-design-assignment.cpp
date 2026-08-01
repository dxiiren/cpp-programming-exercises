#include <iostream> // cin/cout-> input/output
using namespace std;

int main()
{
	// variable declaration
	int data1,data2,answer;
	string name;
	
	cout<<"~ Student Information ~ "<<endl;
	cout<<endl<<endl<<endl;
	
	//input
	cout<<" Enter the students name : ";
	getline(cin,name);
	
	cout<<" Enter the student's ID  number : ";
	cin>>data1;
	
	cout<<" Enter the student's age : ";
	cin>>data2;
	cout<<endl<<endl<<endl;
	
	//output
	cout<<" Name = "<<name<<endl;
	
	cout<<" ID number = "<<data1<<endl;
	
	cout<<" Age = "<<data2<<endl;
	
	return 0;
}

