#include <stdio.h>
#include <math.h>

typedef double (*operatorFunction)(double, double);

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

operatorFunction getOperatorFunction(char *operator) {
    if (strcmp(operator, "+") == 0) {
        return add;
    } else if (strcmp(operator, "-") == 0) {
        return subtract;
    } else if (strcmp(operator, "*") == 0) {
        return multiply;
    } else if (strcmp(operator, "/") == 0) {
        return divide;
    } else if (strcmp(operator, "^") == 0) {
        return power;
    } else {
        printf("Error: Invalid operator.\n");
        exit(1);
    }
}

int main() {
    double num1, num2;
    char operator[50];

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%s", operator);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    operatorFunction func = getOperatorFunction(operator);
    double result = func(num1, num2);

    printf("Result: %.2lf\n", result);

    return 0;