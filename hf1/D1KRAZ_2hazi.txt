/*⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~
File nev: main.c
Programozo: Holczer Mátyás
E-mail: holczermatyi@gmail.com
Datum: 2026. 10. 07.
Neptun kod: D1KRAZ

Az második programozás házifeladat.
⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~⌒^~*/

#include <stdio.h>
#include <math.h>

void formaz(double szam, char *buffer, size_t meret);
void feladat1();
void feladat2();
void feladat3();
void feladat4();

int main()
{

	feladat1();
	feladat2();
	feladat3();
	feladat4();

	return 0;
}

// 1. feladat - formazott kiiratas
void formaz(double szam, char *buffer, size_t meret)
{
	snprintf(buffer, meret, "%12.2f", szam);
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == ' ')
		{
			buffer[i] = '-';
		}
	}
}

void feladat1()
{
	double szam1 = 0, szam2 = 0;
	char formazott1[32], formazott2[32], osszeg[32];

	printf("Adjon meg egy valos szamot: ");
	scanf("%lf", &szam1);

	printf("Adjon meg egy valos szamot: ");
	scanf("%lf", &szam2);

	// printf("%012.2f + %012.2f = %012.2f\n", szam1, szam2, szam1 + szam2);

	formaz(szam1, formazott1, sizeof formazott1);
	formaz(szam2, formazott2, sizeof formazott2);
	formaz(szam1 + szam2, osszeg, sizeof osszeg);

	printf("%s + %s = %s\n", formazott1, formazott2, osszeg);
}

// 2. feladat - szamologep
void feladat2()
{

	int muvelet = 0;

	printf("Osszeadas - 1\nKivonas - 2\nSzorzas - 3\nOsztas - 4\nValasszon muveletet: ");
	scanf("%d", &muvelet);

	if (1 > muvelet || muvelet > 4)
	{
		printf("Hiba: ervenytelen muvelet.\n");
		return;
	}

	double x = 0, y = 0;

	printf("Adjon meg egy valos szamot: ");
	scanf("%lf", &x);

	printf("Adjon meg egy valos szamot: ");
	scanf("%lf", &y);

	double eredmeny = 0;

	switch (muvelet)
	{
	case (1):
		// osszeadas

		eredmeny = x + y;

		break;
	case (2):
		// kivonas

		eredmeny = x - y;

		break;
	case (3):
		// szorzas

		eredmeny = x * y;

		break;
	case (4):
		// osztas

		if (y == 0)
		{
			printf("Hiba: nullaval nem lehet osztani.\n");
			return;
		}

		eredmeny = x / y;

		break;
	}

	printf("A muvelet eredmenye: %.2f\n", eredmeny);
}

// 3.feladat
void feladat3()
{

	double tav = 0;
	printf("Uticel tavolsaga (km): ");
	scanf("%lf", &tav);

	if (tav < 0)
	{
		printf("Hiba: ervenytelen tavolsag.\n");
		return;
	}

	int napszak = 0;
	printf("Reggel - 1\nDelutan - 2\nEste - 3\nMilyen napszakban utazik: ");
	scanf("%d", &napszak);

	if (1 > napszak || napszak > 3)
	{
		printf("Hiba: ervenytelen napszak.\n");
		return;
	}

	double sebesseg = 0;

	switch (napszak)
	{
	case (1):
		// reggel - 55 km/h

		sebesseg = 55;

		break;
	case (2):
		// delutan - 68 km/h

		sebesseg = 68;

		break;
	case (3):
		// este - 65km/h

		sebesseg = 65;

		break;
	}

	double ora = tav / sebesseg;
	double perc = ora * 60;

	printf("Az utazashoz elore lathatoan %.2f ora, vagyis %.2f perc szukseges\n", ora, perc);
}

// 4. feladat
void feladat4()
{

	double a = 0, b = 0, c = 0;

	printf("y = a*x^2 + b*x + c\na = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	if (a == 0)
	{
		printf("Hiba: a nem lehet nulla, mert nem masodfoku az egyenlet.\n");
		return;
	}

	double x1 = 0, x2 = 0;

	double d = b * b - 4 * a * c;

	if (d < 0)
	{
		printf("Az egyenletnek nincs valos gyoke.\n");
		return;
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
	}

	if (d == 0)
	{
		printf("Az egyenlet gyoke: %.2f\n", x1);
	}
	else
	{
		if (x1 > x2)
		{
			double temp = x1;
			x1 = x2;
			x2 = temp;
		}

		printf("Az egyenlet ket gyoke: %.2f, %.2f\n", x1, x2);
	}
}
