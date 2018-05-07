///Alessandro Guatelli 13/04/2018 22:58
///Proggeto per scuola
#include <stdio.h>
#include <math.h>

void calcola(float a, float b, float c, float *x1, float *x2)
{
    ///delta = b2 - 4ac && if delta == 0 x1 = x2 && delta < 0  L'equazione è impossibile
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
        printf("L'equazione e' impossibile!!\n");
    }
}
int main()
{
    float a;
    float b;
    float c;
    float x1;
    float x2;
    printf("Inserisci il valore di a nell equazione: ");
    scanf("%f", &a);
    printf("Inserisci il valore di b nell equazione: ");
    scanf("%f", &b);
    printf("Inserisci il valore di c nell equazione: ");
    scanf("%f", &c);
    printf("L'equazione e': ");
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
    calcola( a, b, c, &x1, &x2);
    printf("\nIl valore delle x dell equazione e': x1=%1.f e x2=%1.f\n", x1, x2);
    system("pause");
    return 0;
}
