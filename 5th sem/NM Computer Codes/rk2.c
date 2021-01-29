#include <stdio.h>
#include <math.h>

double f (double x, double y)
{
    return x*x + y;
}

int main()
{
    double h = 0.01, x0, x1, xf, y0, y1, k;
    printf("\nEnter the start value of x and y: ");
    scanf("%lf %lf", &x0, &y0);
    printf("\nEnter the end value of x: ");
    scanf("%lf", &xf);
    while (x0 < xf)
    {
        y1 = y0 + f(x0, y0) * h;
        x1 = x0 + h;        
        x0 = x1; y0 = y1;        
    }
    printf("\n x = %.2f \t y = %.2f", x1, y1);
    return 0;
}
