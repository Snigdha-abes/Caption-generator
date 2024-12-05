#include<iostream>
using namespace std;
int main()
{
int sum=0,i,n;
cout<<"Enter a number";
cin>>n;
for(i=1;i<+n;i++){
    sum=sum+i;
}
cout<<"The sum of first "<<n<<"natural numbers is " <<sum;
return 0; 
}