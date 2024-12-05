#include <stdio.h>
int n, x, i;
int arr[10];
int linear_search(int arr[], int n, int x)
{
int i;
for (i = 0; i<n; i++)
{
if (arr[i]==x)
return i;
}
return (-1);
}
int main()
{
printf("Enter number of elements of array : ");
scanf("%d",&n);
printf("Enter array elements: ");
for (i = 0; i<n; i++)
scanf("%d", &arr[i]);
printf ("Enter the number which you want to search : ");
 scanf("%d", &x);
int result = linear_search(arr, n, x);
if (result >= 0)
printf("value found at position %d",result + 1);
else
printf("Not found");
}
