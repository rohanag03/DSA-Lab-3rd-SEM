//WAP to implement insertion sort.
#include<stdio.h>
void insertionSort(int array[], int n)
{
    int i, element, j; 
    for (i = 1; i < n; i++) 
    { 
        element = array[i]; 
        j = i - 1; 
        while (j >= 0 && array[j] > element) 
        { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = element; 
    } 
    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d  ", array[i]);
}
int main()
{
    int array[100], n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d Numbers: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);
    insertionSort(array,n);
    return 0;
}