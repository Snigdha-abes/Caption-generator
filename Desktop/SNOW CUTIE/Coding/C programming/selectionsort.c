
#include<stdio.h>
void swap(int *x, int *y){
 int temp = *x;
 *x = *y;
*y = temp;
}
void selectionSort(int arr[], int n)
{
     int minindex,i,j=0;
 while(j<n-1){
 minindex=j;
 for(i=j+1;i<n;i++)
 {
 if(arr[minindex]>arr[i])
 minindex=i;
 }
swap(&arr[minindex],&arr[j]);
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
 selectionSort(a,n);
 printf("The Sorted array is:\n");
 for (int i = 0; i < n; i++)
 printf("%d ", a[i]);
return 0;
}
