#include <iostream>
using namespace std;

int main(){
	
	int finalscore , carrymark ;
	bool status;
	
	finalscore = 50;
	carrymark=70;
	
	status = (finalscore<40 || carrymark<60);
	
	cout<<"\nYour status is: "<<status<<endl;
}
