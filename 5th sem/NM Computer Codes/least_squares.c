#include <stdio.h>
#include <curses.h>
#include <math.h>
int main()
{
    int n, i;
    printf("enter the number of pairs of data: ");
    scanf("%d", &n);
    float x[n], y[n], sumx = 0, sumy = 0, sumxx = 0, sumxy = 0, a, b;
    for (i = 1; i <= n; i++)
    {
        printf("\nx: ");
        scanf("%f", &x[i]);
        printf("\ny: ");
        scanf("%f", &y[i]);
        sumx += x[i];
        //sumy += y[i];
        sumy += log(y[i]);
        sumxx += x[i] * x[i];
        //sumxy += x[i] * y[i];
        sumxy += x[i] * log(y[i]);
    }
    a = (sumxx*sumy - sumx*sumxy) / (n*sumxx - sumx*sumx);
    a = exp(a);
    b = (n*sumxy - sumx*sumy) / (n*sumxx - sumx*sumx);
    //printf("\ny = %f + %f x", a, b);
    printf("\ny = %f e ^ (%f x)", a, b);
    return 0;
}
