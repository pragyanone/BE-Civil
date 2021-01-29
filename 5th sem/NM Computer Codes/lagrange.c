#include<stdio.h>

int main()
{
    int n, i, j;
    printf("\nNumber of pairs of data: ");
    scanf("%d", &n);

    // Input Data
    float x[n], y[n], xa, ya = 0, product;
    printf("\nEnter the values of x and y\n");
    for (i = 0; i < n; i++)
        scanf("%f %f", &x[i], &y[i]);
    
    printf("\nWhere do you like to interpolate? x-value: ");
    scanf("%f", &xa);

    // Interpolation loop
    for ( i = 0; i < n; i ++)
    {
        product = 1;
        for (j = 0; j < n; j++)
            if (i != j)
                product *= (xa - x[j]) / (x[i] - x[j]);
        ya += y[i] * product;
    }

    // Print Solution
    printf("\nThe solution is: \nx = %.2f\ty = %.2f\n", xa, ya);
    return 0;
}
