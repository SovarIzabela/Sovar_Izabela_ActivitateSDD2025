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

//void dezalocare(struct Student* s) {
//	if (s->nume != NULL)
//	{
//		free(s->nume);
//		s->nume = NULL;
//	}
//}

	void afisareVector(struct Student* vector, int nrElemente){

		for (int i = 0; i < nrElemente; i++) {
			afisare(vector[i]);
		}
	}

	struct Student*copiazaPrimeleNelemente(struct Student* vector, int nrElemente, int elementeCopiate)
	{

		struct Student* vectorNou = NULL;
		vectorNou = (struct Student*)malloc(sizeof(struct Student) * elementeCopiate);
		for (int i = 0; i < elementeCopiate; i++){
			vectorNou[i] = vector[i];
			vectorNou[i].nume = (char*)malloc(strlen(vectorNou[i].nume) + 1);
			strcpy_s(vectorNou[i].nume, strlen(vector[i].nume) + 1, vector[i].nume);
		}



			return vectorNou;
	}


	void dezalocare(struct Student** vector, int* nrElemente) {

		for (int i = 0; i <(*nrElemente); i++)
		{
			if((*vector)[i].nume!=NULL)
			{
				free((*vector)[i].nume);
			}
		}
		free(*vector);
		*vector = NULL;
		*nrElemente = 0;

	}

	void copiazaStudentiCuMedieMare(struct Student* vector, char nrElemente, float pragMedie, struct Student** vectorNou, int* dimeniune) {

		*dimeniune = 0;
		for (int i = 0; i < nrElemente; i++)
		{
			if (vector[i].medie >= pragMedie)
			{
				(*dimeniune)++;
			}
		}

		if ((*vectorNou) != NULL) {
			free(*vectorNou);
		}

		(*vectorNou) = (struct Student*)malloc(sizeof(struct Student) * (*dimeniune));		
		int k = 0;
		for (int i = 0; i < nrElemente; i++)
		{
			if (vector[i].medie >= pragMedie) {
				(*vectorNou)[k] = vector[i];
				(*vectorNou)[k].nume = (char*)malloc(strlen(vector[i].nume) + 1);
				strcpy_s((*vectorNou)[k].nume, strlen(vector[i].nume) + 1, vector[i].nume);
				k++;
			}

		}
		



	}
		
	

int main()
{

	struct Student s;
	/*s = initializare(1, 20, "Ionescu", 7.5, 'N');*/

	//afisare(s);

	//modificaMedia(&s, 5.5);
	//afisare(s);

	/*dezalocare(&s);*/

	struct Student* vectorStudent = NULL;
	int nrStudenti = 4;
	vectorStudent = (struct Student*)malloc(sizeof(struct Student) * nrStudenti);
	vectorStudent[0]= initializare(1, 20, "Ionescu", 7.5, 'N');
	vectorStudent[1] = initializare(2, 21, "Popescu", 8.5, 'I');
	vectorStudent[2] = initializare(3, 22, "Matei", 7.0, 'S');
	vectorStudent[3] = initializare(4, 19, "Gorgescu", 9.5, 'T');

	afisareVector(vectorStudent, nrStudenti);


	struct Student* primiiStudenti = NULL;
	int nrPrimiiStudenti = 2;

	primiiStudenti = copiazaPrimeleNelemente(vectorStudent, nrStudenti, nrPrimiiStudenti);


	printf("\n\n........ Afisare primii studenti............\n");
	afisareVector(primiiStudenti, nrPrimiiStudenti);

	dezalocare(&primiiStudenti, &nrPrimiiStudenti);
	
	afisareVector(primiiStudenti, nrPrimiiStudenti);

	struct Student* studentiMedieMare = NULL;
	int nrStudentiMedieMare = 0;
	copiazaStudentiCuMedieMare(vectorStudent, 4, 8, &studentiMedieMare, &nrStudentiMedieMare);
	printf("\n\n........ Afisare studenti medie mare............\n");
	afisareVector(studentiMedieMare, nrStudentiMedieMare);
	dezalocare(&studentiMedieMare, &nrStudentiMedieMare);


	return 0;
}