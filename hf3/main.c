#include <stdio.h>

int Beker(int min, int max);
double valodiBeker(int min, int max);
void feladat2();
void feladat3(int min, int max);

int main()
{
    // Beker(1, 10);
    // feladat2();
    // feladat3(1, 100);
    return 0;
}

int Beker(int min, int max)
{
    int szam = 9999999;
    while (szam < min || szam > max)
    {
        printf("Adjon meg egy egesz szamot %d es %d kozott: ", min, max);
        scanf("%d", &szam);
    }
    return szam;
}

double valodiBeker(int min, int max)
{
    double szam = 9999999;
    while (szam < min || szam > max)
    {
        printf("Adjon meg egy valos szamot %d es %d kozott: ", min, max);
        scanf("%lf", &szam);
    }
    return szam;
}

void feladat2()
{
    double ertekek[7][3];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d. nap, %d. homerseklet\n", i + 1, j + 1);
            ertekek[i][j] = valodiBeker(-40, 50);
        }
    }

    double atlagok[7];
    for (int i = 0; i < 7; i++)
    {
        atlagok[i] = (double)(ertekek[i][0] + ertekek[i][1] + ertekek[i][2]) / 3;
    }

    int min = 99999;
    int max = -99999;
    for (int i = 0; i < 7; i++)
    {
        if (atlagok[i] < min)
        {
            min = i;
        }
        if (atlagok[i] > max)
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
    double atlag = osszeg / 7;
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
        printf("Nyar");
    }
}

void feladat3(int min, int max)
{
    int tipp_db = 0;
    while (min <= max)
    {
        int tipp = min + (max - min) / 2;
        int be = 0;
        tipp_db++;
        printf("\n%d. tipp\nErre a szamra gomdoltal: %d?\n1 - igen\n2 - nem\n", tipp_db, tipp);
        scanf("%d", &be);
        switch (be)
        {
        case (1):
            printf("Ezaz kitaláltam %d lepesbol!\n", tipp_db);
            return;
        case (2):
            printf("Kisebb vagy nagyobb a szam mint %d?\n1 - kisebb\n2 - nagyobb\n", tipp);
            scanf("%d", &be);
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

/*
Adott egy kis bank, mondjuk a PTO Bank. A banknak elég kevés ügyfele van,
mert nem nagyon értenek a bankoláshoz, ezért legfeljebb 20 ügyfél esetén
látják át a dolgokat. Az ügyfeleknek sorszámuk van, amellyel hivatkozni
tudnak magukra és másokra is. A sorszámok 1-el kezdődnek és 20-ig tartanak.
A bank ügyfeleinek egyenlegét egy tömb tárolja. Ahhoz, hogy az ügyfelek
pénzmozgást tudjanak kezdeményezni, be kell menniük a bankfiókba személyesen
és az ügyintéző segítségét kell kérniük. Az elkésztett programot az ügyintéző
használja. Az ügyintézőnek kezdetben fel kell töltenie az egyenlegeket
tartalmazó tömböt értékekkel, amikor az ügyfelek beviszik a pénzüket a bankba,
hogy számlát nyissanak. Minden ügyfél tud befizetni a számlájára, mely nem jár
többletköltséggel. Minden ügyfél képes pénzt felvenni a számlájáról, azonban
ezután már díjat számol fel a bank, méghozzá a felvett összeg 10 %-át levonja
a számlán maradt pénzösszegből. Ha ez nem lehetséges, akkor nem engedélyezi
annyi pénz felvételét a rendszer. Minden ügyfél tud utalni is másik ügyfeleknek.
Ha bankon belül utal, akkor ismernie kell a sorszámát a címzettnek, viszont
ebben az esetben az utalás ingyenes. Ha bankon kívülre szeretne az ügyfél
utalni, akkor annak szinten 10%-os díja van, amelyet a visszamaradó egyenlegből
von le a bank. Ha ez nem lehetséges, akkor nem engedélyezi annyi pénz utalását
a rendszer. Minden egyes személyes ügyintézés díja 5000 Ft.

Készítsen egy programot, amely képes a PTO Bank ügyfeleinek az egyenlegeinek
kezelésére. A program úgy fusson, hogy egymás után bármennyi műveletet el
lehessen végezni, bármelyik ügyféllel (konzolos menürendszer). Fontos, hogy
a futtatás során bármikor ki lehessen listázni az ügyfelek egyenlegeit. Az
egyenlegek kezelésében mindig naprakésznek kell lennie a programnak tehát,
ha valaki pénzt fizet be, vagy vesz fel, akkor az egyenlege azonnal frissüljön.
Bankon belüli átutalásnál mind a feladó, mind a kedvezményezett egyenlege is
frissüljön! A bank nem hitelez, így az egyenlegek nem csökkenhetnek le 0 Ft
alá. Figyeljen oda, hogy a banki díjakat is jól kezelje a rendszer!
*/