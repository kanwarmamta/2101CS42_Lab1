#include <stdio.h>

int main()
{
    float num1, num2;
    char operation;
    // Taking input numbers and letting user choose desired operation
    printf("Enters the two numbers:\n");
    scanf("%f %f", &num1, &num2);
    printf("Enter the operation you want to proceed with from ' +,-,*,/'\n");
    scanf(" %c", &operation);
    // switch case for choosing between different operations
    switch (operation)
    {
    case '+':
        printf("%f+%f=%f", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%f-%f=%f", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%f*%f=%f", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%f/%f=%f", num1, num2, num1 / num2);
        break;
    }
    return 0;
}