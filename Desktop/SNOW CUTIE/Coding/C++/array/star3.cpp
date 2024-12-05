#include <iostream>
using namespace std;
int main(){
int a[10],i,j,n;
cout<<"Enter th value of n";
cin>>n;

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i+j>=n-1){
            cout<<"*";
        }
        else {
        cout<<" ";
        }
    }
    cout<<endl;
}
}
