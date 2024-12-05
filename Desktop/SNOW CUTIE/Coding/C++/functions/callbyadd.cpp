#include <iostream>
using namespace std;
void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
cout<<*a<<" "<<*b;
}

int main(){
    int x=20, y=90;
    swap(&x,&y);
    return 0;
    cout<<x<<" "<<y;

}