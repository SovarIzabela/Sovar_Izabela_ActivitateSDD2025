#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct Farmacie {

	int id;
	char* nume;
	unsigned char numarMedicamente;
	float* preturiMedicamente;

};
typedef struct Farmacie Farmacie;


struct Nod {

	Farmacie info;
	struct Nod* prev;
	struct Nod* next;

};
typedef struct Nod Nod;



struct ListaDubla {
	Nod* first;
	Nod* last;
	int nrNoduri;
};
typedef struct ListaDubla ListaDubla;

Farmacie citireFarmacieDinFisier(FILE* file) {

	Farmacie f = { 0,NULL,0,NULL };
	char buffer[100];
	char* separator = ",;\n";
	fgets(buffer, 100, file);

	
	char* token = strtok(buffer, separator);
	if (token == NULL) return f;
	f.id = atoi(token);

	 token = strtok(NULL, separator);
	if (token== NULL) return f;
	f.nume = (char*)malloc(strlen(token) + 1);
	strcpy(f.nume, token);

	token = strtok(NULL, separator);
	if (token == NULL) return f;
	f.numarMedicamente = (unsigned char)atoi(token);

	token = strtok(NULL, separator);
	
	f.preturiMedicamente = (float*)malloc(sizeof(float) * f.numarMedicamente);
	if (f.preturiMedicamente == NULL) {
		free(f.nume);
		return f;
	}
	for (int i = 0; i < f.numarMedicamente; i++) {
		 token = strtok(NULL, separator);
		 if (token == NULL) {
			 free(f.nume);
			 free(f.preturiMedicamente);
			 f.nume = NULL;
			 f.preturiMedicamente = NULL;
			 return f;
		 }
		 f.preturiMedicamente[i] = atof(token);
	}

	return f;

}

void afisareFarmacii(Farmacie farmacie) {

	printf("ID este : %d\n", farmacie.id);
	printf("Numele farmaciei este : %s\n", farmacie.nume);
	printf("Numar de medicamente : %d\n", farmacie.numarMedicamente);
	printf("Preturile sunt : %.2f\n", farmacie.preturiMedicamente);
	printf("\n");
	
}

void afisareListaFarmaciiINCEPUT(ListaDubla lista) {
	Farmacie f;
	Nod* p = lista.first;
	while (p) {

		afisareFarmacii(p->info);
		p = p->next;
	}


}

void afisareListaFarmaciiSfarsit(ListaDubla lista) {
	Farmacie f;
	Nod* p = lista.last;
	while (p) {

		afisareFarmacii(p->info);
		p = p->prev;
	}


}

void adaugaFarmacieInListaFINAL(ListaDubla*lista, Farmacie FarmacieNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = FarmacieNoua;
	nou->next = NULL;
	nou->prev = lista->last;

	if (lista->last = NULL) {
		lista->last->next = nou;
	}
	else {
		lista->first = nou;
	}
	lista->last = nou;
	lista->nrNoduri++;

}

void adaugaLaInceputInLista(ListaDubla* lista, Farmacie FarmacieNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = FarmacieNoua;
	nou->next = NULL;
	nou->prev = lista->first;

	if (lista->first == NULL) {
		lista->first->prev = nou;
	}
	else {
		lista->last = nou;
	}

	lista->first = nou;
	lista->nrNoduri++;

}

ListaDubla citireLDFarmacieDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
	FILE* f = fopen(numeFisier, "r");
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;

	while (!feof(f)) {
		adaugaLaInceputInLista(&lista, citireFarmacieDinFisier(f));

	}


	fclose(f);
	return lista;
}

void dezalocareLDFarmacie(ListaDubla* lista) {
	Nod* p = lista->first;
	while (p) {
		Nod* aux = p;
		p = p->next;
		if (aux->info.nume != NULL) {
			free(aux->info.nume);
		}
		if (aux->info.preturiMedicamente != NULL) {
			free(aux->info.preturiMedicamente);
		}
		free(aux);
	}

	lista->first = NULL;
	lista->last = NULL;
	lista->nrNoduri = 0;
}

float calculeazaPretMediu(ListaDubla lista) {
	if(lista.first)
	{
		float suma = 0;
		int nrTotalMedicamente = 0;
		Nod* p = lista.first;
		while (p) {
			for(int i = 0; i<p->info.numarMedicamente;i++)
			{
				suma = suma + p->info.preturiMedicamente[i];
				
			}
			p = p->next;

		}

		return suma / nrTotalMedicamente;
	}

	return 0;
}

void stergeFarmacieDupaID(/*lista masini*/ int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	return NULL;
}

int main() {


	return 0;
}