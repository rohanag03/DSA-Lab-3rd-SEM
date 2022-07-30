//WAP to search an element in array of n numbers.
#include <stdio.h>
int main() {
   int a, i, r; 
   printf("Enter the length of the array: ");
   scanf("%d", &a);
    int arr[a];
   printf("Enter the array elements: ");
   for (i = 0; i < a; i++) {
      scanf("%d", &arr[i]);
   }
 
   printf("Enter the item to be searched: ");
   scanf("%d", &r);

   i = 0;
   while (i < a && r != arr[i]) {
      i++;
   }
   if (i < a) {
      printf("The element is found in the index position = %d", i);
   } else {
      printf("Element not found!");
   }
   return 0;
}