#include <stdio.h>
void insertionSort(int arr[], int n)
{
 int i, key, j;
for (j = 1; j < n; j++)
 {
key = arr[j];
 i = j - 1;
while (i >= 0 && arr[i] > key)
 {
 arr[i + 1] = arr[i];
 i = i - 1;
 }
 arr[i + 1] = key;
 }
}
int main() {
 int a[100], n;
 printf("Enter the Size of Array: ");
scanf("%d", &n);
printf("Enter the Array elements: ");
 for (int i = 0; i < n; i++)
 scanf("%d", &a[i]);
 insertionSort(a,n);
 printf("The Sorted array is:\n");
 for (int i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}
