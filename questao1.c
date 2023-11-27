#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char romano[1000];
    scanf("%s", romano);

    int vroman(char r)
    {
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;
        return -1;
    }

    int RomanOpDecimal(char *num)
    {
        int res = 0;
        int i;

        for (i = 0; i < strlen(num); i++)
        {
            int s1 = vroman(num[i]);

            if (i + 1 < strlen(num))
            {
                int s2 = vroman(num[i + 1]);

                if (s1 >= s2)
                {
                    res = res + s1;
                }
                else
                {
                    res = res + s2 - s1;
                    i++;
                }
            }
            else
            {
                res = res + s1;
                i++;
            }
        }
        return res;
    }

    void saidaBinario(int n)
    {
        if (n > 1)
        {
            saidaBinario(n / 2);
        }
        printf("%d", n % 2);
    }

    void saidaHexadecimal(int n)
    {
        char *hexadecimal = (char *)malloc(sizeof(char) * 100);
        int i = 0;

        while (n != 0)
        {
            int temp = 0;
            temp = n % 16;
            if (temp < 10)
            {
                hexadecimal[i] = temp + 48;
                i++;
            }
            else
            {
                hexadecimal[i] = temp + 87;
                i++;
            }
            n = n / 16;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            printf("%c", hexadecimal[j]);
        }
    }

    int decimal = RomanOpDecimal(romano);

    printf("%s na base 2: ", romano);
    saidaBinario(decimal);
    printf("\n%s na base 10: %d\n", romano, decimal);
    printf("%s na base 16: ", romano);
    saidaHexadecimal(decimal);
    printf("\n");

    return 0;
}
