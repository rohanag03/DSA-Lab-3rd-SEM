//WAP to reverse the contents of a array of n elements.
#include <stdio.h>
void main (){

int i, j, a, n;
printf("enter number of elements in an array:");
scanf("%d", &n);
int num[n];
printf("Enter the elements:");
for (i = 0; i < n; ++i)
    scanf("%d", &num[i]);
int temp;
for(int i = 0; i<n/2; i++){
temp = num[i];
num[i] = num[n-i-1];
num[n-i-1] = temp;
}
printf("\nReversed array: ");
for(int i = 0; i < n; i++){
    printf("%d  ", num[i]);
}
}
