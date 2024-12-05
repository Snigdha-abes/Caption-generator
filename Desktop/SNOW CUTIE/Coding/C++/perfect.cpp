
#include<iostream>
using namespace std;
int main ()
{  
    int i, num, factor , sum=0;
    cout << "Enter the number to be checked : ";
    cin >> num;
    for (i=1; i < num; i++)
    {
        factor = num % i;
        if (factor == 0)
            sum = sum + i;
    }
    if (sum == num)
        cout << "\n" << num <<" is a perfect number.";
    else
        cout << "\n" << num <<" is not a perfect number.";
    return 0;
}
    