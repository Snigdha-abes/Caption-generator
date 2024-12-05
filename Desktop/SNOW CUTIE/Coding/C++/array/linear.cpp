#include <iostream>
using namespace std;
int main(){
    int a[10],n=10,i,key;
    cout<<"Enter 10 elements ";
    for (i=0;i<n;i++){
        cin>>a[i];}
cout<<"Enter the number to be searched ";
cin>>key;
for(i=0;i<n;i++){
    if (key==a[i]){
        cout<<"number is found at the position "<<i;
    }
}
   return 0; 
}