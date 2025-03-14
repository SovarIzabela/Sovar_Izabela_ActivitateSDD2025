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

void afisareVector(struct Farmacie* vectorFarmacie, int nrElemente) {
	
	for (int i = 0; i < nrElemente; i++) {
		afisare(vectorFarmacie[i]);
	}


}

struct Farmacie* copiazaPrimeleNElemente(struct Farmacie* vectorF, int nrElemente, int nrElementeCopiate) {
	
	struct Farmacie*vectorNou=NULL;
	vectorNou = (struct Farmacie*)malloc((sizeof(struct Farmacie) * nrElementeCopiate));
	for (int i = 0; i < nrElementeCopiate; i++) {
		 vectorNou[i]= vectorF[i];
		 vectorNou[i].nume = (char*)malloc((strlen(vectorF[i].nume) + 1));
		 strcpy_s(vectorNou[i].nume, strlen(vectorF[i].nume) + 1, vectorF[i].nume);
		 vectorNou[i].preturiMedicamente = (float*)malloc(sizeof(float) * nrElementeCopiate);
		 for (int i = 0; i < nrElementeCopiate; i++) {
			 vectorNou[i].preturiMedicamente = vectorF[i].preturiMedicamente;
		 }
	}
	return vectorNou;
}

void dezalocareV(struct Farmacie** vectorF , int* nrElemente) {
	//dezalocam elementele din vector si vectorul
	for (int i = 0; i < (*nrElemente); i++) {
		if((*vectorF)[i].nume!=NULL|| (*vectorF)[i].preturiMedicamente!=NULL)
		{
			free((*vectorF)[i].nume);
			free((*vectorF)[i].preturiMedicamente);
		}
		
	}
	free(*vectorF);
	(*vectorF) = NULL;
	(*nrElemente) = 0;

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

	struct Farmacie* vectorFarmacie;
	int numarFarmacii = 3;
	vectorFarmacie = (struct Farmacie*)malloc(sizeof(struct Farmacie) * numarFarmacii);
	float preturi2[] = { 2.5,55.7,25.5 };
	float preturi3[] = { 72.5, 13.5, 44.5, 155.5, 180.25 };
	vectorFarmacie[0] = initializare(1, "Catena", 5, preturi);
	vectorFarmacie[1] = initializare(2, "DrMax", 3, preturi2);
	vectorFarmacie[2] = initializare(3, "Beneva", 5, preturi3);
	printf("-------Vector Farmacii----------------\n\n");
	afisareVector(vectorFarmacie, numarFarmacii);
	int numarFarmaciiCopiate = 2;
	struct Farmacie* vectorCopiat = copiazaPrimeleNElemente( vectorFarmacie, numarFarmacii, numarFarmaciiCopiate);
	printf("\n\n------------Primele Farmacii-----------------\n\n");
	afisareVector(vectorCopiat, numarFarmaciiCopiate);
	dezalocareV(&vectorCopiat, &numarFarmaciiCopiate);
	return 0;
}