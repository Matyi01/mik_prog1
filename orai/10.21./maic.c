#include <stdio.h>

void szamologep();
int beker(int min, int max);

int main()
{
    szamologep();

    return 0;
}

int beker(int min, int max)
{
    float szam = -1;
    while (szam < min || szam > max)
    {
        printf("Adjon meg egy szamot %d es %d kozott: ", min, max);
        scanf("%f", &szam);
    }
    return szam;
}

void szamologep()
{
    float szam1 = 0, szam2 = 0, eredmeny = 0;

    szam1 = beker(0, 100);
    szam2 = beker(0, 100);

    int valasztas = 0;
    while (valasztas != 5)
    {
        printf("Valasszon egy muveletet:\n");
        printf("1. Osszeadas\n");
        printf("2. Kivonas\n");
        printf("3. Szorzas\n");
        printf("4. Osztas\n");
        printf("5. Kilepes\n");

        scanf("%d", &valasztas);
        switch (valasztas)
        {
        case 1:
            eredmeny = szam1 + szam2;
            printf("Eredmeny: %.2f\n", eredmeny);
            break;
        case 2:
            eredmeny = szam1 - szam2;
            printf("Eredmeny: %.2f\n", eredmeny);
            break;
        case 3:
            eredmeny = szam1 * szam2;
            printf("Eredmeny: %.2f\n", eredmeny);
            break;
        case 4:
            if (szam2 == 0)
            {
                printf("Hiba: nullaval nem lehet osztani.\n");
            }
            else
            {
                eredmeny = szam1 / szam2;
                printf("Eredmeny: %.2f\n", eredmeny);
            }
            break;
        case 5:
            printf("Kilepes a programbol.\n");
            break;
        default:
            printf("Hibas valasztas.\n");
            break;
        }
    }
}
