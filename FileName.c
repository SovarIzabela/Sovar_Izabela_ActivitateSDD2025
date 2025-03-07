#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <string.h>
#include<stdlib.h>

struct Student {
	int id;
	int varsta;
	char* nume;
	float medie;
	char initialaTata;
};

struct Student initializare(int id, int varsta,const char* nume, float medie, char initialaTata)
{
	struct Student s;
	s.id = id;
	s.varsta = varsta;
	s.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy_s(s.nume, strlen(nume) + 1, nume);
	s.medie = medie;
	s.initialaTata = initialaTata;
	
	return s;

}

void afisare(struct Student s)
{
	printf("Studentul cu id-ul %d si nume %s are varsta %d ani, media %5.2f si initiala tatalui %c\n\n",
		s.id, s.nume, s.varsta, s.medie, s.initialaTata);
}

void modificaMedia(struct Student* s, float nouaMedie)
{
	if (nouaMedie > 0)
	{
		(*s).medie = nouaMedie;
	}
}



int main()
{

	struct Student s;
	s = initializare(1, 20, "Ionescu", 7.5, 'N');

	afisare(s);

	modificaMedia(&s, 5.5);
	afisare(s);
	return 0;
}