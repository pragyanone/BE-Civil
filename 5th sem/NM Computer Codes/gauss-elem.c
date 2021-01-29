#include <stdio.h>
#include<math.h>

int main()
{
    int n, i, j, k;
    printf("\nEnter the number of variables: ");
    scanf("%d", &n);
    float a[n][n+1], x[n], sum, r;
    
    // Input Augmented Matrix
    printf("\nEnter the coefficients of the augmented matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n+1; j++)
            scanf("%f", &a[i][j]);
    
    // Applying Gauss Elimination
    for (j = 1; j <= n-1; j++)
    {
        if (fabs(a[j][j]) <= 0.0005)
        {
            printf("\nDiagonal element zero\n");
            return 1;
        }
        for (i = j+1; i <= n; i++)
        {
            r = a[i][j] / a[j][j];
            for (k = 1; k <= n+1; k++)
                a[i][k] -= r * a[j][k];            
        }
    }

    // Backward Substitution
    x[n] = a[n][n+1]/a[n][n];
    for (i = n-1; i >= 1; i--)
    {
        sum = 0;
        for (j = i+1; j <= n; j++)
            sum += a[i][j] * x[j];
        x[i] = (a[i][n+1] - sum) / a[i][i];
    }

    /*x[n] = a[n][n+1] / a[n][n];
    for (i = n-1; i >= 1; i--)
    {
        x[i] = a[i][n+1];
        for (j = i+1; j <= n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }*/

    // Print solution
    for (i = 1; i <= n; i++)
        printf("\nx_%d = %f", i, x[i]);

    return 0;    
}