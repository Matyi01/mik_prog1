#include <stdio.h>

void formaz();
void feladat1();

int main() {

    

    feladat1();

    return 0;
}

void formaz(double szam, char *buffer, size_t meret) {
    snprintf(buffer, meret, "%12.2f", szam);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ') {
            buffer[i] = '-';
        }
    }
}

void feladat1(){
    double szam1 = 0, szam2 = 0;
    char formazott1[32], formazott2[32], osszeg[32];

    printf("Adjon meg egy valos szamot: ");
    scanf("%lf", &szam1);

    printf("Adjon meg egy valos szamot: ");
    scanf("%lf", &szam2);

    //printf("%012.2f + %012.2f = %012.2f\n", szam1, szam2, szam1 + szam2);

    formaz(szam1, formazott1, sizeof formazott1);
    formaz(szam2, formazott2, sizeof formazott2);
    formaz(szam1 + szam2, osszeg, sizeof osszeg);

    printf("%s + %s = %s\n", formazott1, formazott2, osszeg);
}