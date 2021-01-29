#include<stdio.h>

int main()
{
    int n, i, j, k;
    printf ("\nEnter the order of square matrix: ");
    scanf ("%d", &n);
    float a[n][2*n], ratio, temp;

    // Construct identity matrix
    for (i = 1; i <= n; i++)
        for (j = n+1; j <= 2*n; j++)
            if (j == n+i)
                a[i][j] = 1;
            else
                a[i][j] = 0;
    
    // Input the square matrix
    printf("\nEnter the square matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);
    
    // Perform Gauss-Jordan
    for (j = 1; j <= n; j++)
        for (i = 1; i <= n; i ++)
            if (i != j)
            {
                ratio = a[i][j] / a[j][j];
                for (k = 1; k <= 2*n; k++)
                    a[i][k] -= ratio * a[j][k];                
            }

    // Performing Inversing
    for (i = 1; i <= n; i++)
    {
        temp = a[i][i];
        for (j = 1; j <= 2*n; j++)
            a[i][j] /= temp;
    }
    
    
    // Print Inverse Matrix
    printf("\nThe inverse matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = n+1; j <= 2* n; j++)
            printf("%.2f \t", a[i][j]);
        printf("\n");
    }
}
