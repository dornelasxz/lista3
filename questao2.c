#include <stdio.h>
#include <math.h>

int main()
{
    int Meses;
    double aporteMensal, vTaxa, Montante;

    scanf("%d %lf %lf", &Meses, &aporteMensal, &vTaxa);

    for (int i = 1; i <= Meses; i++)
    {
        Montante = (aporteMensal * (1 + vTaxa)) * ((pow(1 + vTaxa, i) - 1) / vTaxa);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, Montante);
    }

    return 0;
}
