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
	
	cout<<"Project (b/80) = ";
	cin>>project;
	
	cout<<"Test (c/60) = ";
	cin>>test;
	
	//process
	finalexammark= (finalexam/100) * 70;
	projectmark= (project/80) * 20;
	testmark = (test/60) * 10;
	
	totalscore = finalexammark+projectmark+testmark ;
	
	//output
	cout<<endl;
	if (totalscore>=50){
	cout<<"Total mark is :"<<totalscore<<"%"<<endl;
	cout<<"STUDENT PASS"<<endl;
    }
 
    else {
    	
    	cout<<"Total mark is :"<<totalscore<<"%"<<endl;
    	cout<<"STUDENT FAIL"<<endl;
	}
    
    
	
	return 0;
}
