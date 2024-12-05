#include <iostream>
using namespace std;
int main(){
    int a[10],mid,i,n=10,key,l=0,h=9;
    cout<<"ENter the numbers ";
    for(i=0;i<n;i++){
cin>>a[i];
    }
    cout<<"Enter key ";
    cin>>key;
    while(l<=h){
    mid=(l+h)/2;
    if(key==a[mid]){
        cout<<"Key is found at "<<mid;
        return 0;
    }
    else if(key<a[mid]){
        h=mid-1;
        }
        else
        l=mid+1;
}
}