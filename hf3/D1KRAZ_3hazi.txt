/*⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~
File nev: main.c
Programozo: Holczer Mátyás
E-mail: holczermatyi@gmail.com
Datum: 2026. 10. 29.
Neptun kod: D1KRAZ

Az harmadik programozás házifeladat.
⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~*/

#include <stdio.h>

int Beker(int min, int max);
double ValodiBeker(int min, int max);
void Feladat2();
void Feladat3(int min, int max);
void Feladat4();
void Egyenlegek(int egyenlegek[20]);

int main()
{
    Beker(1, 10);
    Feladat2();
    Feladat3(1, 100);
    Feladat4();
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

double ValodiBeker(int min, int max)
{
    double szam;
    do
    {
        printf("Adjon meg egy valos szamot %d es %d kozott: ", min, max);
        scanf("%lf", &szam);
    } while (szam < min || szam > max);
    return szam;
}

void Feladat2()
{
    double ertekek[7][3];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d. nap, %d. homerseklet\n", i + 1, j + 1);
            ertekek[i][j] = ValodiBeker(-40, 50);
        }
    }

    double atlagok[7];
    for (int i = 0; i < 7; i++)
    {
        atlagok[i] = (double)(ertekek[i][0] + ertekek[i][1] + ertekek[i][2]) / 3;
    }

    int min = 0;
    int max = 0;
    for (int i = 0; i < 7; i++)
    {
        if (atlagok[i] < atlagok[min])
        {
            min = i;
        }
        if (atlagok[i] > atlagok[max])
        {
            max = i;
        }
    }

    printf("A legmagasabb homerseklet a %d. napon volt, %lf C˚.\n", max + 1, atlagok[max]);
    printf("A legalacsonyabb homerseklet a %d. napon volt, %lf C˚.\n", min + 1, atlagok[min]);

    double osszeg = 0;
    for (int i = 0; i < 7; i++)
    {
        osszeg += atlagok[i];
    }
    double atlag = osszeg / 7.0;
    if (atlag <= 5)
    {
        printf("Tel\n");
    }
    else if (atlag <= 20)
    {
        printf("Osz vagy tavasz\n");
    }
    else
    {
        printf("Nyar\n");
    }
}

void Feladat3(int min, int max)
{
    int tipp_db = 0;
    while (min <= max)
    {
        int tipp = min + (max - min) / 2;
        int be = 0;
        tipp_db++;
        printf("\n%d. tipp\nErre a szamra gondoltal: %d?\n1 - igen\n2 - nem\n", tipp_db, tipp);
        be = Beker(1, 2);
        switch (be)
        {
        case (1):
            printf("Ezaz kitalaltam %d lepesbol!\n", tipp_db);
            return;
        case (2):
            printf("Kisebb vagy nagyobb a szam mint %d?\n1 - kisebb\n2 - nagyobb\n", tipp);
            be = Beker(1, 2);
            switch (be)
            {
            case (1):
                max = tipp - 1;
                break;
            case (2):
                min = tipp + 1;
                break;
            }
        }
    }
    printf("Hiba: Ellentmondasos valaszokat adtal meg!\n");
}

void Feladat4()
{
    int egyenlegek[20];
    int be = 0;
    int osszeg = 0;
    int teljes = 0;
    int honnan = 0;
    int hova = 0;

    printf("Toltse fel az egyenlegeket a szamlakra!\n");
    for (int i = 0; i < 20; i++)
    {
        printf("Azonosito: %d\nEgyenleg: ", i + 1);
        egyenlegek[i] = Beker(0, 2147483647);
    }

    while (1)
    {
        printf("\nMit szeretne?\n0 - kilepes\n1 - egyenlegek\n2 - befizetes\n3 - felvetel\n4 - utalas bankon belul\n5 - utalas bankon kivul\n");
        be = Beker(0, 5);
        switch (be)
        {
        case (0):
            printf("Viszlat\n");
            return;

        case (1):
            Egyenlegek(egyenlegek);
            break;

        case (2):
            printf("Melyik szamlara szeretne befizetni? ");
            be = Beker(1, 20);
            printf("Mennyi penzt szeretne befizetni? ");
            osszeg = Beker(0, 2147483647);

            if (egyenlegek[be - 1] + osszeg >= 5000)
            {
                egyenlegek[be - 1] += osszeg;
                egyenlegek[be - 1] -= 5000;
                printf("Sikeres befizetes! Uj egyenleg: %d Ft\n", egyenlegek[be - 1]);
            }
            else
            {
                printf("A befizetett osszeg nem fedezi az 5000 Ft-os ugyintezesi dijat!\n");
            }
            break;

        case (3):
            printf("Melyik szamlarol szeretne felvenni? ");
            be = Beker(1, 20);
            printf("Mennyi penzt szeretne felvenni? ");
            osszeg = Beker(0, 2147483647);

            teljes = 5000 + osszeg + (int)(osszeg * 0.10);
            if (egyenlegek[be - 1] >= teljes)
            {
                egyenlegek[be - 1] -= teljes;
                printf("Sikeres felvetel! Uj egyenleg: %d Ft\n", egyenlegek[be - 1]);
            }
            else
            {
                printf("Nincs elegendo fedezet! (Szukseges: %d Ft, Meglevo: %d Ft)\n", teljes, egyenlegek[be - 1]);
            }
            break;

        case (4):
            printf("Melyik szamlarol szeretne utalni? ");
            honnan = Beker(1, 20);
            printf("Melyik szamlara szeretne utalni? ");
            hova = Beker(1, 20);
            printf("Mennyi penzt szeretne utalni? ");
            osszeg = Beker(0, 2147483647);

            if (egyenlegek[honnan - 1] >= osszeg + 5000)
            {
                egyenlegek[honnan - 1] -= osszeg + 5000;
                egyenlegek[hova - 1] += osszeg;
                printf("Sikeres utalas!\n");
            }
            else
            {
                printf("Nincs elegendo fedezet az utalashoz es az ugyintezesi dijhoz!\n");
            }
            break;

        case (5):
            printf("Melyik szamlarol szeretne utalni? ");
            honnan = Beker(1, 20);
            printf("Mennyi penzt szeretne utalni? ");
            osszeg = Beker(0, 2147483647);

            teljes = 5000 + osszeg + (int)(osszeg * 0.10);
            if (egyenlegek[honnan - 1] >= teljes)
            {
                egyenlegek[honnan - 1] -= teljes;
                printf("Sikeres utalas!\n");
            }
            else
            {
                printf("Nincs elegendo fedezet! (Szukseges: %d Ft, Meglevo: %d Ft)\n", teljes, egyenlegek[honnan - 1]);
            }
            break;
        }
    }
}

void Egyenlegek(int egyenlegek[20])
{
    printf("\n==========\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d: %d\n", i + 1, egyenlegek[i]);
    }
    printf("==========\n");
}