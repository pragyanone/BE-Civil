#include <stdio.h>

float g (float x, float y, float z)
{
    return (x*y*z);
}

int main()
{
    float h = 0.1, x0, y0, z0, xf;
    float k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    printf("\nEnter the values of x0, y0, z0\n");
    scanf("%f %f %f", &x0, &y0, &z0);
    printf("\nFind y at x: ");
    scanf("%f", &xf);
    while (xf > x0)
    {
        k1 = h * z0;
        l1 = h * g(x0, y0, z0);

        k2 = h * (z0 + l1/2);
        l2 = h* g(x0 + h/2, y0 + k1/2, z0 + l1/2);

        k3 = h * (z0 + l2/2);
        l3 = h * g(x0 + h/2, y0 + k2/2, z0 + l2/2);

        k4 = h * (z0 + l3);
        l4 = h * g(x0 + h, y0 + k3, z0 + l3);

        k = (k1 + k2 + k2 + k3 + k3 + k4)/6;
        l = (l1 + 2 * l2 + 2 * l3 + l4)/6;
        
        x0 += h; y0 += k; z0 += l;
    }
    printf("\n%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f", k1, k2, k3, k4, k, l1, l2, l3, l4, l);
    printf("\nSolution:\nx = %.2f\ty = %.2f\n", xf, y0);
    return 0;
}        
