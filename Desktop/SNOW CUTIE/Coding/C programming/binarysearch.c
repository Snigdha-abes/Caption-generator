#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int arr[],int f,int l,int x){
while (f<=l)
{
int m=f+(l-f)/2;
if(arr[m]==x)
 return m;
   else if(arr[m]<x)
 f=m+1;
 else
  l=m-1;
}
return -1; 
}
int main(){
 int n,i,arr[100],x,f,l;
printf("Enter the number of elements in array : ");
scanf("%d",&n);
 printf("Enter the array elements : ");
for (i=0;i<n;i++)
 scanf("%d",&arr[i]);
f=0;
 l=n-1;
 printf("Enter the element to be searched : ");
 scanf("%d",&x);
 int result=BinarySearch(arr,0,n-1,x);
 if(result>=0)
 printf("%d found at location %d",x,result+1);
 else
 printf("%d is not found",x);
return 0; 
}
