#include<stdio.h>
#include<math.h>
#include<curses.h>

int main()
{
    int n, i, j, k;
    printf("\nEnter the number of variables: ");
    scanf("%d", &n);
    float a[n][n+1], r;
    printf("\nEnter the coefficients of the augmented matrix: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n+1; j++)
            scanf("%f", &a[i][j]);
    for (j = 1; j <= n; j++)
    {
        if (fabs(a[j][j]) <= 0.0005)
        {
            printf("\nDiagonal element zero\n");
            return 1;
        }
        for (i = 1; i <= n; i++)
            if (i != j)
            {
                r = a[i][j] / a[j][j];
                for (k = 1; k <= n+1; k++)
                    a[i][k] -= r * a[j][k];
            }
    }
    printf("\nThe augmented diagonal matrix is: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n+1; j++)
            printf("%f\t", a[i][j]);
        printf("\n");
    }
    printf("\nThe solutions are:\n");
    for (i = 1; i <= n; i++)
        printf("x_%d = %f\n", i, a[i][n+1] / a[i][i]);
    return 0;
    getch();
}
