#include <stdio.h>
#include <math.h>

double f (double x, double y)
{
    return x*x + y;
}

int main()
{
    double h = 0.0001, x0, x1, xf, y0, y1, k, k1, k2, k3, k4;
    printf("\nEnter the start value of x and y: ");
    scanf("%lf %lf", &x0, &y0);
    printf("\nEnter the end value of: ");
    scanf("%lf", &xf);
    while (x0 < xf)
    {
        k1 = h*f(x0, y0);
        k2 = h*f(x0 + h/2, y0 + k1/2);
        k3 = h*f(x0 + h/2, y0 + k2/2);
        k4 = h*f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y1 = y0 + k;
        x1 = x0 + h;
        printf("\n x = %.2f \t y = %.2f \t k = %.4f", x1, y1, h, k, h*k);
        x0 = x1; y0 = y1;        
    }
    return 0;
}