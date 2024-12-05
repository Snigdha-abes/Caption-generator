#include<iostream>
using namespace std;

int main() {
    int A[5] = {2, 4, 6, 8, 10};
    int *p = A, *a = &A[4];

    cout << *p << endl;        // Output: 2
    cout << *a << endl;        // Output: 10
    cout << a - p;           // Output: 8

    return 0;
}
