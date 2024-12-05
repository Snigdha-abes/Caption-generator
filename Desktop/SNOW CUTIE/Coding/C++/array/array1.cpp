   
#include <iostream>
using namespace std;

int main() {

  int a[5];

  cout << "Enter 5 numbers: " << endl;

  //  store input from user to array
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
  }

  cout << "The numbers are: ";

  //  print array elements
  for ( int x:a) {
    cout << x << "  ";
  }

  return 0;
}