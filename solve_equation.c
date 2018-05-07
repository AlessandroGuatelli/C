///Alessandro Guatelli 13/04/2018 22:58
///Rewrited in english in 07/05/2018 21:45
///Project for school
#include <stdio.h>
#include <math.h>

void computes(float a, float b, float c, float *x1, float *x2)
{
    ///delta = b2 - 4ac && if delta == 0 x1 = x2 && delta < 0  The equation is impossible
    /// x1 = -b + sqrt(delta) / 2a
    /// x2 = -b - sqrt(delta) / 2a
    float delta;
    delta = (b * b) - ( 4 * a * c);
    if (delta > 0)
    {
    *x1 = ((0 - b) + sqrt(delta)) / (2 * a);
    *x2 = ((0 - b) - sqrt(delta)) / (2 * a);
    }
    else
    {
        printf("The equation is impossible!!\n");
    }
}
int main()
{
    float a;
    float b;
    float c;
    float x1;
    float x2;
    printf("Enter the value of a in the equation: ");
    scanf("%f", &a);
    printf("Enter the value of b in the equation: ");
    scanf("%f", &b);
    printf("Enter the value of c in the equation: ");
    scanf("%f", &c);
    printf("The equation is: ");
    if(a>0 && a!=1)
    {
        printf("%1.fx^2",a);
    }
    if(a==1)
    {
        printf("x^2");
    }
    if(a<0)
    {
        printf("-%1.fx^2",a);
    }
    if(b>=0 && b!=1)
    {
        printf("+%1.fx",b);
    }
    if(b==1)
    {
        printf("+x");
    }
    if(b<0)
    {
        printf("%1.fx",b);
    }
    if(c<0)
    {
        printf("%1.f",c);
    }
    if(c>=0 && c!=1)
    {
        printf("+%1.f",c);
    }
    computes( a, b, c, &x1, &x2);
    printf("\nThe values of x of the equation are: x1=%1.f and x2=%1.f\n", x1, x2);
    system("pause");
    return 0;
}
