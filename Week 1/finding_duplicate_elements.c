/*WAP to store numbers into an array of n integers, where the array must contain some
duplicates. Find out the most repeating element in the array.*/
#include <stdio.h>

int main()
{
    int arr[] = {23, 42, 54, 28, 22, 78, 23, 87, 54};

    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Duplicate elements in given array: \n");
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d\n", arr[j]);
            }
        }
    }
    return 0;
}