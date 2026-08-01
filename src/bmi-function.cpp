#include <iostream>
using namespace std;

double BMI (double weight , double height)
{
     double bmi;
     bmi = weight/(height*height);
     return bmi;
     
}

int main ()
{
    double bmi , height , weight ;
    string person;
    
    cout<<"Please enter your height (m) :";
    cin>>height;
    
    cout<<"Please enter your weight (kg) :";
    cin>>weight;
    
    bmi=BMI(height,weight);
    
    if (bmi<20)
         person="unhealthy";
    
    else if (bmi>20 && bmi<25)
         person="healthy";
    
    else
         person = "underweight";
         
         
    cout<<"\nYour status is = "<<person;
    
    return 0;
    
}
