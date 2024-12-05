#include <iostream>
using namespace std;
int main(){
    int a[7],max=0,i;
    cout<<"Enter 7 numbers ";
    for(i=0;i<7;i++){
cin>>a[i];
    }
    max=a[0];
    for(i=0;i<7;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    cout<<"Maximum element is "<<max;
    return 0;

}
