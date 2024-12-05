#include<iostream>
using namespace std;
int main(){
    int arr[1000];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){//taking elements of an array as input
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){//printing the elements 
        cout<<arr[i]<<" ṇ";
    }
    return 0;
}