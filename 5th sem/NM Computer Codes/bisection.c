#include <stdio.h>
#include <conio.h>
#include <math.h>

float f (float x)
{
    //return pow(x,3)-4*x-9;
    return sin(x) - 3 * x + 4;
}

int main()
{
    float  a, b, c, tol, nmax;
    int N=0;
    printf("Bisection Method\nf(x) = x^3 - 4x - 9\n");
    // printf("Bisection Method\nf(x) = x^3 - 4x - 9\n");
    printf("\ntolerance: ");
    scanf("%f", &tol);
    printf("\nmaximum iterations: ");
    scanf("%f", &nmax);
    do
    {
        printf("\nInitial guesses such that f(a).f(b)<0\na:\nb:\n");
        scanf("%f\n%f", &a, &b);
        fflush(stdin);
    } while (f(a) * f(b) > 0);
    while (N<nmax)
    {
        c = (a+b)/2;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        if (f(c) == 0 || fabs((a-b))/2 < tol)
            break;
        N++;
    }
	if (N == nmax)
	{
		printf("\nroot not found\n");
		return 0;
	}
    printf("\nThe root is %5f",c);
    getch();
    return 0;
}