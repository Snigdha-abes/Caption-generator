#include<iostream>
using namespace std;
void swap(int a ,int b)
{ 
   int temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b;
}
//the actual parameters i.e x and y are not changed rather values of a and b are changed
int main(){
    int x=10,y=20;
    swap(x,y);
    cout<<x<<" "<<y;
}