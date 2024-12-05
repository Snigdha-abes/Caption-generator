#include<stdio.h>
void swap(int *x, int *y){
 int temp = *x;
 *x = *y;
 *y = temp;
}
void bubblesort(int arr[], int n){
 int i, j = 0;
while (j<n-1)
{
for (i=0;i<n-1-j;i++){
 if (arr[i] > arr[i + 1])
swap(&arr[i],&arr[i+1]);
 }
  j++;
 }
}
int main() {
 int a[100], n;
printf("Enter the Size of Array: ");
scanf("%d", &n);
printf("Enter the Array elements: ");
 for (int i = 0; i < n; i++)
 scanf("%d", &a[i]);
 bubblesort(a,n);
 printf("The Sorted array is:\n");
 for (int i = 0; i < n; i++)
printf("%d ", a[i]);
return 0;
}
