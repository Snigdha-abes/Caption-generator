#include<iostream>
using namespace std;
int max(int a, int b, int c=0){
    return a>b && a>c?a:(b>c?b:c);
}

int main(){
    cout<<max(10,12)<<endl;
    cout<<max(10,13,35);


}