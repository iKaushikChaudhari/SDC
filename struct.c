#include <stdio.h>
struct employee
{
    char name[20];
    int age[5];
    float sal[5];
}emp;
int main() {
    // Write C code here
    printf("\nEnter Name Of Employee: ");
    scanf("%s",&emp.name);
    printf("\nName Of Employee Is %s",emp.name);
    printf("\nEnter Age Of Employee: ");
    scanf("%s",&emp.age);
    printf("\nAge Of Employee %s Years",emp.age);
    printf("\nEnter Sal Of Employee: ");
    scanf("%s",&emp.sal);
    printf("\nSal Of Employee %s RS",emp.sal);
    

    return 0;
}
