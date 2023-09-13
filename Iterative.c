#include <stdio.h>
#include <math.h>

double polyFunc(double x)
{
    return x*x*x - 2*x*x - 4;
}

double diffFunc(double x)
{
    return 3*x*x - 4*x;
}

double xForm(double x)
{
    return ;
}
int steps = 0;
void calIterative(double x)
{
    double y = xForm(x);
    steps++;
    printf("%d  Iteration and the value of x is - %f\n", steps, x);
    if (fabs(y - x) <= 0.0001)
        return;
    calIterative(y);
}

int main()
{

    double x;

    printf("Enter the guessed value - ");
    scanf("%f", &x);

    if (diffFunc(x) < 1)
    {

        printf("Input is satisfying the condition\n");
        calIterative(x);
    }
    else
        printf("Oops invalid input!!!");
    return 0;
}
