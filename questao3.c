#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char placa[20];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);

    int placavald = 0;
    int diavald = 0;
    int pdCirc = 1;

    int comprimento = strlen(placa);

    if ((comprimento == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) ||
        (comprimento == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
         isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])))
    {
        placavald = 1;
    }

    char diasValidos[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(dia, diasValidos[i]) == 0)
        {
            diavald = 1;
            break;
        }
    }

    int term = placa[strlen(placa) - 1] - '0';
    for (int i = 0; dia[i]; i++)
    {
        dia[i] = tolower(dia[i]);
    }

    if (strcmp(dia, "segunda-feira") == 0 && (term == 0 || term == 1))
    {
        pdCirc = 0;
    }
    else if (strcmp(dia, "terca-feira") == 0 && (term == 2 || term == 3))
    {
        pdCirc = 0;
    }
    else if (strcmp(dia, "quarta-feira") == 0 && (term == 4 || term == 5))
    {
        pdCirc = 0;
    }
    else if (strcmp(dia, "quinta-feira") == 0 && (term == 6 || term == 7))
    {
        pdCirc = 0;
    }
    else if (strcmp(dia, "sexta-feira") == 0 && (term == 8 || term == 9))
    {
        pdCirc = 0;
    }
    else if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0)
    {
        pdCirc = 1;
    }

    if (!placavald || !diavald)
    {
        if (!placavald)
        {
            printf("Placa invalida\n");
        }

        if (!diavald)
        {
            printf("Dia da semana invalido\n");
        }
    }
    else
    {
        if (pdCirc && (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0))
        {
            printf("Nao ha proibicao no fim de semana\n");
        }
        else if (pdCirc)
        {
            printf("%s pode circular %s\n", placa, dia);
        }
        else
        {
            printf("%s nao pode circular %s\n", placa, dia);
        }
    }

    return 0;
}
