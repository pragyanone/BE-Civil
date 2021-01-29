#include <stdio.h>
//#include <conio.h>
#include <math.h>
float fun(float x)
{
    //return (x * sin(x) + cos(x));
    return (x * x * x - 4 * x - 11);
}
float der(float x)
{
    //return (x * cos(x));
    return (3 * x * x - 4);
}
int main()
{
    float x, x1;
    int itr = 0;
    printf("Enter initial guess\n");
    scanf("%f",&x);
    do
    {
        if (fabs(der(x)) <= pow(10,-10))
        {
            printf("zero derivative");
            return 1;
        }
        x1 = x - fun(x) / der(x);
        x = x1;
        if (itr > 50)
        {
            printf("did not converge");
            return 1;
        }
        itr++;
    } while (fabs(fun(x)) >= 0.00001);
    printf("root = %.5f", x);
    printf("\niterations = %d\n", itr);
    return 0;
}
