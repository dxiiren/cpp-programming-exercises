#include <iostream>
using namespace std;

main(){
	
	//declarevariable
    double finalexam,project,test,finalexammark,projectmark,testmark,totalscore;
	
	//headline
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Calculate The Final Total Score of A Student"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	
	//input
	cout<<"------>Press Enter to continue<------"<<endl;
	cout<<"Enter mark of Final Exam , Project , Test ;"<<endl<<endl;
	
	cout<<"Final Exam (a/100) = ";
	cin>>finalexam;
	
	cout<<"Project (b/50) = ";
	cin>>project;
	
	cout<<"Test (c/60) = ";
	cin>>test;
	
	//process
	finalexammark= (finalexam/100) * 70;
	projectmark= (project/50) * 20;
	testmark = (test/60) * 10;
	
	totalscore = finalexammark+projectmark+testmark ;
	
	//output
	cout<<endl;
	cout<<"Final score is = "<<totalscore<<"%";
	
	return 0;
}
	
