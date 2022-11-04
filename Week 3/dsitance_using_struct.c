//WAP to add two distances (in km-meter) by passing structure to a function
#include <stdio.h>
struct Distance
{
    int km;
    int m;
};
void addDistances(struct Distance a, struct Distance b)
{
    struct Distance result;
    result.km = a.km + b.km;
    result.m = a.m + b.m;
    while (result.m >= 1000)
    {
        result.km++;
        result.m -= 1000;
    }
    printf("\nSum of distances = %dkm and %dm", result.km, result.m);
}
int main()
{
    struct Distance d1, d2;
    printf("Enter 1st distance\n");
    printf("Enter km: ");
    scanf("%d", &d1.km);
    printf("Enter meters: ");
    scanf("%d", &d1.m);
    printf("\nEnter 2nd distance\n");
    printf("Enter km: ");
    scanf("%d", &d2.km);
    printf("Enter meters: ");
    scanf("%d", &d2.m);
    addDistances(d1, d2);
    return 0;
}