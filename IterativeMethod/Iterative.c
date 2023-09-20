#include <stdio.h>
#include <math.h>

double fx(double x)
{
    return x*x*x - 2*x*x - 4;
}

double gx(double x)
{
    return cbrt(2*x*x+4);
}

double hx(double x)
{
    return 4*x/(3*cbrt(pow(2*x*x+4,2)));
}
int steps = 0;
void calIterative(double x)
{
    double y = gx(x);
    steps++;
    printf("%d  Iteration and the value of x is - %f\n", steps, x);
    if (fabs(y - x) <= 0.0001)
        return;
    calIterative(y);
}

int main()
{

    double x,y;

    printf("Enter the guessed value - ");
    scanf("%lf %lf", &x,&y);

    if (hx(x) < 1 && hx(y) < 1)
    {

        printf("Roots are Accepted...\n");
        calIterative((x+y)/2);
    }
    else
        printf("Oops invalid input!!!");
    return 0;
}
