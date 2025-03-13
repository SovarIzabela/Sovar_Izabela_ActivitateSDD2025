#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>

struct Farmacie {

	int id;
	char* nume;
	unsigned char numarMedicamente;
	float* preturiMedicamente;

};

struct Farmacie initializare(int id, const char* nume, unsigned char numarMedicamente, float* preturiMedicamente) {
	struct Farmacie f;
	f.id = id;
	f.nume = (char*)malloc(sizeof(char)*(strlen(nume)+1));
	strcpy_s(f.nume, strlen(nume) + 1, nume);
	f.numarMedicamente = numarMedicamente;
	f.preturiMedicamente = (float*)malloc(sizeof(float) * numarMedicamente);

	if(f.preturiMedicamente!=NULL)
	{
		for (int i = 0; i < numarMedicamente; i++) {
			f.preturiMedicamente[i] = preturiMedicamente[i];
		}
	}


	return f;
	
}

void afisare(struct Farmacie f) {
	printf("Farmacia cu id-ul %d, si numele %s, are un numar de medicamente de %d, cu preturile: \n\n",
		f.id,  f.nume,f.numarMedicamente);
	for (int i = 0; i < f.numarMedicamente; i++){
		printf(" %5.2f, ", f.preturiMedicamente[i]);
	}

	printf("\n\n");
}

void modifica_Preturi(struct Farmacie* f, int NrNouPreturi, float* PreturiNoi) {
	if (NrNouPreturi != 0){
		f->numarMedicamente = NrNouPreturi;
		f->preturiMedicamente = (float*)malloc(sizeof(float) * NrNouPreturi);
		if(f->preturiMedicamente!=NULL)
		{
			for (int i = 0; i < NrNouPreturi; i++) {
				f->preturiMedicamente[i] = PreturiNoi[i];

			}
		}


	}
	
}

void dezalocare(struct Farmacie* f) {
	if (f->nume != NULL)
	{
		free(f->nume);
		f->nume = NULL;
	}

	if(f->preturiMedicamente != NULL)
	{
		free(f->preturiMedicamente);
		f->preturiMedicamente = NULL;
	}
}

void afisareVector() {
	//afisarea elementelor din vector apeland functia afisare
}

struct Farmacie* copiazaPrimeleNElemente() {
	/*copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate*/
	struct Farmacie*vectorNou=NULL;

	return vectorNou;
}

void dezalocareV() {
	//dezalocam elementele din vector si vectorul
}

void copiazaAnumiteElemente() {
	/*parametrul prag poate fi modificat in functie de 
	 tipul atributului ales pentru a indeplini o conditie
	este creat un nou vector cu elementele care indeplinesc acea conditie*/
}

struct Farmacie getPrimulElementConditionat() {
	/*trebuie cautat elementul care indeplineste o conditie
	dupa atributul de tip char*. Acesta este returnat.*/
	

	
}
	





void main(){

	struct Farmacie farmacie;
	unsigned char numarMedicamente = 5;
	float preturi[] = {2.5, 3.5, 4.5, 55.5, 18.25};
	farmacie = initializare(1, "Catena", 5, preturi);

	afisare(farmacie);
	float pret[] = { 10.5, 7.5,12.5, 100.5, 55, 75 };
	modifica_Preturi(&farmacie, 6, pret);
	printf("\n ......Functia Modifica_Preturi.....\n\n");
	afisare(farmacie);

	dezalocare(&farmacie);
	return 0;
}