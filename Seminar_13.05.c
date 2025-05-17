#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;



typedef struct Nod {

	Masina info;
	struct	Nod* fiuStanga;
	struct	Nod* fiuDreapta;

};
typedef struct Nod Nod;

Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret= atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

int calculeazagradEchilibru(Nod* radacina) {

	return calculeazaInaltimeArbore(radacina->fiuStanga) - calculeazaInaltimeArbore(radacina->fiuDreapta);
}

int calculeazaInaltimeArbore(Nod* radacina) {
	

	if (radacina) {
		int HS = calculeazaInaltimeArbore(radacina->fiuStanga);
		int HD = calculeazaInaltimeArbore(radacina->fiuDreapta);
		return 1 + (HS > HD ? HS : HD);
	}
	else {
		return 0;
	}
	
}

void rotireStanga(Nod**rad) {                           
	Nod* aux = (*rad)->fiuDreapta;
	(*rad)->fiuDreapta = aux->fiuStanga;
	aux->fiuStanga = *rad;
	*rad = aux;
}


void rotireDreapta(Nod** rad) {
	Nod* aux = (*rad)->fiuStanga;
	(*rad)->fiuStanga = aux->fiuDreapta;
	aux->fiuDreapta = *rad;
	*rad = aux;
}


void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua) {
	
	if ((*radacina) != NULL){

		if (masinaNoua.id < (*radacina)->info.id) {
			adaugaMasinaInArbore(&(*radacina)->fiuStanga,masinaNoua);
		}
		else {
			adaugaMasinaInArbore(&(*radacina)->fiuDreapta, masinaNoua);
		}

		//verificam  gradul de echilibru

		int GE = calculeazagradEchilibru(*radacina);
		if (GE == -2) {
			if (calculeazaInaltimeArbore((*radacina)->fiuDreapta) == 1) {

			}
		}
	}
	else {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->fiuStanga = NULL;
		nou->fiuDreapta = NULL;
		nou->info = masinaNoua;
		nou->info.model = (char*)malloc(strlen(masinaNoua.model) + 1);
		strcpy(nou->info.model, masinaNoua.model);
		nou->info.numeSofer = (char*)malloc(strlen(masinaNoua.numeSofer) + 1);
		strcpy(nou->info.numeSofer, masinaNoua.numeSofer);

		(*radacina) = nou;
	}


}

Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
	

	FILE* f = fopen(numeFisier, "r");

	Nod* nou = NULL;
	if (f != NULL) {

		
		while (!feof(f)) {
			Masina masinanoua = citireMasinaDinFisier(f);
			adaugaMasinaInArbore(&nou, masinanoua);
			free(masinanoua.model);
			free(masinanoua.numeSofer);
		}
	}
	fclose(f);
	return nou;


}

void afisareMasiniDinArbore(Nod* radacina) {//rsd


	if (radacina != NULL) {
		afisareMasina(radacina->info);
		afisareMasiniDinArbore(radacina->fiuStanga);
		afisareMasiniDinArbore(radacina->fiuDreapta);
	}



}



void afisareInOrdine(Nod* radacina) {//srd


	if (radacina != NULL) {
		
		afisareInOrdine(radacina->fiuStanga);
		afisareMasina(radacina->info);
		afisareInOrdine(radacina->fiuDreapta);
	}



}
void dezalocareArboreDeMasini(Nod** radacina) {//postordine
	if ((*radacina) != NULL){

		dezalocareArboreDeMasini((&(*radacina)->fiuStanga));
		dezalocareArboreDeMasini((&(*radacina)->fiuDreapta));
		free((*radacina)->info.model);
		free((*radacina)->info.numeSofer);
		free(*radacina);
		(*radacina) = NULL;
	}




}

Masina getMasinaByID(Nod* rad, int id) {
	Masina m;

	m.id = -1;
	if (rad != NULL) {
		if (id < rad->info.id) {
			return getMasinaByID(rad->fiuStanga, id); 

			}else if(id>rad->info.id){
				return getMasinaByID(rad->fiuDreapta, id);
			}
			else {
			return rad->info;
		}
		
		}


	



	return m;
}

int determinaNumarNoduri(/*arborele de masini*/) {
	//calculeaza numarul total de noduri din arborele binar de cautare
	return 0;
}



float calculeazaPretTotal(/*arbore de masini*/) {
	//calculeaza pretul tuturor masinilor din arbore.
	return 0;
}

float calculeazaPretulMasinilorUnuiSofer(/*arbore de masini*/ const char* numeSofer) {
	//calculeaza pretul tuturor masinilor unui sofer.
	return 0;
}

int main() {
	Nod* radacina = citireArboreDeMasiniDinFisier("masini.txt");
	
	afisareInOrdine(radacina);

	afisareMasina(getMasinaByID(radacina, 7));
	return 0;
}