#include<stdio.h>

int main()
{
    int a,b;
    char op;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter an operator (+, -, *, /,^): ");
    scanf(" %c",&op);
    printf("Enter second number: ");
    scanf("%d",&b);
    switch(op)
    {
        case '+':
            printf("%d + %d = %d\n",a,b,a+b);
            break;
        case '-':
            printf("%d - %d = %d\n",a,b,a-b);
            break;
        case '*':
            printf("%d * %d = %d\n",a,b,a*b);
            break;
        case '/':
            if(b != 0)
                printf("%d / %d = %.2f\n",a,b,(float)a/b);
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        case '^': {
            int result = 1;
            if(b < 0) {
                printf("Error: Negative exponent not supported for integer calculations.\n");
                break;
            }
            for(int i = 0; i < b; i++) {
                result *= a;
            }
            printf("%d ^ %d = %d\n", a, b, result);
            break;
        }
        default:
            printf("Error: Invalid operator.\n");
    }
    return 0;
}