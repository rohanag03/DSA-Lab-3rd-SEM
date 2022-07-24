//WAP to find out the sum of the numbers stored in an array of integers.
#include <stdio.h>
#include <stdio.h>  
void  main()  
{  
int arr[50]; 
int i, n, sum=0;
printf("Enter the number of elements you want to enter:");
scanf("%d", &n);
  
printf("Input elements in the array :\n");  
    for(i=0; i<n; i++)  
    {  
	    printf("element - %d : ",i);
        scanf("%d", &arr[i]);  
    }  
  
for(i = 0; i < n; i++)
          sum = sum + arr[i];
    
    printf("Sum of the array = %d\n",sum);
    
    return 0;
}
