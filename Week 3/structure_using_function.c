/*Create a structure named student that has name, roll and mark as members.
Assume appropriate types and size of member. Write a program using structure
to read and display the data entered by the user by passing structure to a function.*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll, totalMarks;
};
void input( struct Student *A ){
    printf("Enter name: ");
    scanf("%[^\n]s", A->name);

    printf("Enter roll: ");
    scanf("%d", &A->roll);

    printf("Enter marks: ");
    scanf("%d", &A->totalMarks);
}
void display( struct Student A ){
    printf("Student details are: ");
    printf("\nName: %s\nRoll: %d\nTotal marks: %d\n", A.name, A.roll, A.totalMarks);
}
int main(){
    struct Student A;
    input(&A);
    display(A);
    return 0;
}
