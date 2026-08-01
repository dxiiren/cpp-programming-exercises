#include <iostream>
using namespace std;

int main(){
	
	int score[]={78,52,61,49,88,59,80};
	
	int i=0;
	while(i<=6)
	{
		if(score[i]%2 !=0)
		     score[i]=99;
		else if(i%2 != 0)
		     score[i] += 8;
		
		cout<<score[i]<<"\t";
		i++;
		
	}
}
