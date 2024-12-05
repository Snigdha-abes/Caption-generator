#include<iostream>
using namespace std;
int main(){
    int a[5],i,x,sum=0;
    cout<<"Enter 5 elements: ";
for (i=0;i<5;i++){
    cin>>a[i];
}
for (i=0;i<5;i++){
sum=sum+a[i];
}
cout<<"Sum is "<<sum;
return 0;
}
