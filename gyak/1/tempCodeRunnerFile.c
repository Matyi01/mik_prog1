#include <stdio.h>

int Beker(int min, int max);

int kikolcsonozve[15];
int orak[15];
int bevetel[15];

int Main()
{
    Beker(1, 10);
    return 1;
}

int Beker(int min, int max)
{
    int szam;
    do
    {
        printf("Adjon meg egy egesz szamot %d es %d kozott", min, max);
        scanf("%d", &szam);
    } while (szam < min || szam > max);
    return szam;
}
