#include <stdio.h>

int Beker(int min, int max);
void Kolcsonzo();
void Listazas();

// 0 - nincs kikolcsonozve
// 1 - ki van kolcsonozve
int kikolcsonozve[15];
// kikolcsonzott orak szama
int orak[15];
// mennyi bevetetlt hozott az adott bicikli
int bevetel[15];

int main()
{
    Kolcsonzo();
    return 0;
}

int Beker(int min, int max)
{
    int szam;
    do
    {
        printf("Adjon meg egy egesz szamot %d es %d kozott: ", min, max);
        scanf("%d", &szam);
    } while (szam < min || szam > max);
    return szam;
}

void Kolcsonzo()
{
    int be;
    int melyik;
    int ora;
    while (1)
    {
        printf("Mit szeretne?\n0 - Kilepes\n1 - Kolcsonzes\n2 - Visszahozas\n3 - Csere\n4 - Listazas\n5 - Statisztika\n");
        be = Beker(0, 5);
        switch (be)
        {
        case 0:
            printf("Viszlat!\n");
            return;

        case 1:
            printf("Melyiket szeretne kikolcsonozni?\n");
            melyik = Beker(1, 15);
            if (kikolcsonozve[melyik - 1] == 0)
            {
                kikolcsonozve[melyik - 1] = 1;
                bevetel[melyik - 1] += 500;
            }
            else
            {
                printf("Ez a bicikli mar ki van kolcsonozve!\n");
            }
            break;

        case 2:
            printf("Melyik biciklit hoztak vissza?\n");
            melyik = Beker(1, 15);
            printf("Hany orara volt kikolcsonozve?\n");
            ora = Beker(0, 100);
            if (kikolcsonozve[melyik - 1] == 1)
            {
                kikolcsonozve[melyik - 1] = 0;
                orak[melyik - 1] += ora;
                if (ora <= 5)
                {
                    bevetel[melyik - 1] += 800 * ora;
                }
                else
                {
                    if (ora > 12)
                    {
                        bevetel[melyik - 1] += 2000;
                    }
                    bevetel[melyik - 1] += 800 * 5;
                    bevetel[melyik - 1] += 500 * (ora - 5);
                }
            }
            else
            {
                printf("Ez a bicikli nincs kikolcsonozve!\n");
            }
            break;

        case 3:
            printf("Nincs csere!\n");
            break;

        case 4:
            Listazas();
            break;
        }
    }
}

void Listazas()
{
    printf("allapot\torak\tbevetel\n");
    for (int i = 0; i < 15; i++)
    {
        if (kikolcsonozve[i])
        {
            printf("foglalt\t");
        }
        else
        {
            printf("szabad\t");
        }
        printf("%d\t%d\n", orak[i], bevetel[i]);
    }
}
