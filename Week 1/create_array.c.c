//WAP to create an array that can store max. 50 integers and display the contents of the array.
#include <stdio.h>  
void  main()  
{  
int arr[50]; 
int i, n;
printf("Enter the number of elements you want to enter:");
scanf("%d", &n);
  
printf("Input elements in the array :\n");  
    for(i=0; i<n; i++)  
    {  
	    printf("element - %d : ",i);
        scanf("%d", &arr[i]);  
    }  
  
    printf("\nElements in array are: ");  
    for(i=0; i<n; i++)  
    {  
        printf("%d  ", arr[i]);  
    } 
printf("\n");
}