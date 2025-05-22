//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//struct Nod {
//
//	Masina info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//
//};
//typedef struct Nod Nod;
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret= atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//Nod* initilalizareArbore() {
//	return NULL;
//}
//
//void rotireStanga(Nod**rad) {
//	Nod* aux = (*rad)->dreapta;
//	(*rad)->dreapta = aux->stanga;
//	aux->stanga = (*rad);
//	*rad = aux;
//
//}
//
//void rotireDreapta(Nod**rad) {
//	Nod* aux = (*rad)->stanga;
//	(*rad)->stanga = aux->dreapta;
//	aux->dreapta = (*rad);
//	*rad = aux;
//}
//
//int calculeazaInaltimeArbore(Nod* rad) {
//	if (rad != NULL) {
//		int hs = calculeazaInaltimeArbore(rad->stanga);
//		int hd = calculeazaInaltimeArbore(rad->dreapta);
//		return 1 + (hs > hd ? hs : hd);
//		
//	}
//	else {
//		return 0; 
//	}
//
//
//
//	
//}
//
//int calculeazaGE(Nod* rad) {
//	return calculeazaInaltimeArbore(rad->stanga) - calculeazaInaltimeArbore(rad->dreapta);
//}
//
//void adaugaMasinaInArbore(Nod** rad, Masina masinaNoua) {
//
//	if ((*rad) != NULL) {
//
//		if (masinaNoua.id < (*rad)->info.id) {
//			adaugaMasinaInArbore(&(*rad)->stanga, masinaNoua);
//		}
//		else {
//			adaugaMasinaInArbore(&(*rad)->dreapta, masinaNoua);
//		}
//
//		int ge = calculeazaGE(*rad);
//		if (ge == -2) {
//			if (calculeazaGE((*rad)->dreapta) == 1) {
//				rotireDreapta(&(*rad)->dreapta);
//			}
//
//			rotireStanga((rad));
//		}
//		if (ge == 2) {
//			if (calculeazaGE((*rad)->stanga) == -1) {
//				rotireStanga(&(*rad)->stanga);
//			}
//
//			rotireDreapta(rad);
//		}
//
//
//
//	}
//	else {
//
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->stanga = NULL;
//		nou->dreapta = NULL;
//		nou->info = masinaNoua;
//		nou->info.model = (char*)malloc(strlen(masinaNoua.model) + 1);
//		strcpy(nou->info.model, masinaNoua.model);
//		nou->info.numeSofer = (char*)malloc(strlen(masinaNoua.numeSofer) + 1);
//		strcpy(nou->info.numeSofer, masinaNoua.numeSofer);
//		(*rad) = nou;
//
//	}
//
//}
//
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	
//	FILE* f = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	if (f) {
//		while (!feof(f)) {
//			Masina m = citireMasinaDinFisier(f);
//			adaugaMasinaInArbore((&nou), m);
//
//			free(m.model);
//			free(m.numeSofer);
//
//		}
//	}
//
//	fclose(f);
//	return nou;
//
//}
//
//void afisareMasiniDinArboreRSD(Nod * rad) {
//
//	if (rad != NULL) {
//		afisareMasina(rad->info);
//		afisareMasiniDinArboreRSD(rad->stanga);
//		afisareMasiniDinArboreRSD(rad->dreapta);
//	}
//
//
//}
//
//void afisareMasiniDinArboreINordine(Nod* rad) {
//
//	if (rad != NULL) {
//		afisareMasiniDinArboreINordine(rad->stanga);
//		afisareMasina(rad->info);
//		
//		afisareMasiniDinArboreINordine(rad->dreapta);
//	}
//
//
//}
//
//void dezalocareArboreDeMasini(Nod**rad) {
//	if ((*rad)) {
//		dezalocareArboreDeMasini(&(*rad)->stanga);
//		dezalocareArboreDeMasini(&(*rad)->dreapta);
//		free((*rad)->info.model);
//		free((*rad)->info.numeSofer);
//		free(*rad);
//	}
//
//	(*rad) = NULL;
//}
//
//Masina getMasinaByID(Nod*rad, int id) {
//	Masina m;
//	m.id = -1;
//
//	if (rad != NULL) {
//		if (id < rad->info.id) {
//			return getMasinaByID(rad->stanga, id);
//		}
//		else if (id > rad->info.id) {
//			return getMasinaByID(rad->dreapta, id);
//		}
//		else {
//			return rad->info;
//		}
//
//
//
//	}
//	
//
//
//	return m;
//}
//
//int determinaNumarNoduri(/*arborele de masini*/) {
//	//calculeaza numarul total de noduri din arborele binar de cautare
//	return 0;
//}
//
//
//
//float calculeazaPretTotal(/*arbore de masini*/) {
//	//calculeaza pretul tuturor masinilor din arbore.
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*arbore de masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//int main() {
//	Nod* arbore = citireArboreDeMasiniDinFisier("masini_arbore.txt");
//
//	Nod* arbore1 = initilalizareArbore();
//	Masina m = { 25, 5, 3500,_strdup("dacia"), _strdup("ion"), 'c' };
//	adaugaMasinaInArbore(&arbore1, m);
//	afisareMasiniDinArboreINordine(arbore1);
//	afisareMasina(getMasinaByID(arbore, 2));
//
//	dezalocareArboreDeMasini(&arbore1);
//	dezalocareArboreDeMasini(&arbore);
//	return 0;
//}