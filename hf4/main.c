#include <stdio.h>
#include <string.h>

void feladat1();
void feladat2();

int main()
{

    // feladat1();
    feladat2();

    return 0;
}

void feladat1()
{

    int hossz;

    printf("Hany karakteres a jelszava? ");
    scanf("%d", &hossz);

    char jelszo[hossz + 1];

    printf("Adja meg a jelszavat: ");
    scanf("%s", jelszo);

    // Kisbetűk ABC sorrendben (26 elem)
    char kisbetuk[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Nagybetűk ABC sorrendben (26 elem)
    char nagybetuk[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Speciális karakterek (30 elem)
    char specialis[] = {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\',
        ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/'};

    // Számok (10 elem)
    char szamok[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int valodi_hossz = strlen(jelszo);
    int eleg_hosszu = (valodi_hossz >= 8);
    int van_kis = 0, van_nagy = 0, van_szam = 0, van_spec = 0;

    for (int i = 0; i < valodi_hossz; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (jelszo[i] == kisbetuk[j])
                van_kis = 1;
            if (jelszo[i] == nagybetuk[j])
                van_nagy = 1;
        }
        for (int j = 0; j < 10; j++)
        {
            if (jelszo[i] == szamok[j])
                van_szam = 1;
        }
        for (int j = 0; j < 30; j++)
        {
            if (jelszo[i] == specialis[j])
                van_spec = 1;
        }
    }

    if (eleg_hosszu && van_kis && van_nagy && van_spec && van_szam)
    {
        printf("A jelszo megfelel!\n");
    }
    else
    {
        printf("A jelszo nem felel meg!\n");
        if (!eleg_hosszu)
            printf("- Nem elegge hosszu (minimum 8 karakter szukseges)!\n");
        if (!van_kis)
            printf("- Nincsen benne kisbetu!\n");
        if (!van_nagy)
            printf("- Nincsen benne nagybetu!\n");
        if (!van_szam)
            printf("- Nincsen benne szam!\n");
        if (!van_spec)
            printf("- Nincsen benne specialis karakter!\n");
    }
}

void feladat2()
{
    int hossz;
    printf("Hany karakteres a szoveg? ");
    scanf("%d", &hossz);
    getchar();

    char szoveg[hossz + 2];
    printf("Adja meg a szoveget:\n");
    fgets(szoveg, sizeof(szoveg), stdin);
    szoveg[strcspn(szoveg, "\n")] = '\0';

    char karakterek[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    int elofordulas[63] = {0};
    int kisbetuk = 0, nagybetuk = 0, szamjegyek = 0, szokozok = 0;
    int tenyleges_hossz = strlen(szoveg);

    for (int i = 0; i < tenyleges_hossz; i++)
    {
        char *talalat = strchr(karakterek, szoveg[i]);
        if (talalat != NULL)
        {
            int index = talalat - karakterek;
            elofordulas[index]++;

            if (index < 26)
                kisbetuk++;
            else if (index < 52)
                nagybetuk++;
            else if (index < 62)
                szamjegyek++;
            else
                szokozok++;
        }
    }

    int max_db = 0;
    char max_karakter = '\0';
    for (int i = 0; i < 63; i++)
    {
        if (elofordulas[i] > max_db)
        {
            max_db = elofordulas[i];
            max_karakter = karakterek[i];
        }
    }

    printf("Kisbetuk szama: %d\n", kisbetuk);
    printf("Nagybetuk szama: %d\n", nagybetuk);
    printf("Szamjegyek szama: %d\n", szamjegyek);
    printf("Szokozok szama: %d\n", szokozok);

    if (max_db > 0)
    {
        if (max_karakter == ' ')
            printf("Legtobbszor elofordulo karakter: ' ' (szokoz) (%d alkalommal)\n", max_db);
        else
            printf("Legtobbszor elofordulo karakter: '%c' (%d alkalommal)\n", max_karakter, max_db);
    }
}
