//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
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
//
//struct Nod {
//	Masina info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//};
//typedef struct Nod Nod;
//
//
//Masina citireMasinaDinFisier(FILE* f) {
//		char buffer[100];
//		char sep[3] = ",\n";
//		fgets(buffer, 100, f);
//		char* aux;
//		Masina m1;
//
//		aux = strtok(buffer, sep);
//		m1.id = atoi(aux);
//		m1.nrUsi = atoi(strtok(NULL, sep));
//		m1.pret= atof(strtok(NULL, sep));
//		aux = strtok(NULL, sep);
//		m1.model = malloc(strlen(aux) + 1);
//		strcpy_s(m1.model, strlen(aux) + 1, aux);
//	
//		aux = strtok(NULL, sep);
//		m1.numeSofer = malloc(strlen(aux) + 1);
//		strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//	
//		m1.serie = *strtok(NULL, sep);
//		return m1;
//
//}
//
//void afisareMasina(Masina m) {
//
//	printf("ID: %d\n", m.id);
//	printf("NrUsi: %d\n", m.nrUsi);
//	printf("Pret: %.2f\n", m.pret);
//	printf("Model: %s\n", m.model);
//	printf("NumeSofer: %s\n", m.numeSofer);
//	printf("Serie: %c\n\n", m.serie);
//
//
//}
//
//void rotireStanga(Nod**rad) {
//	Nod* aux = (*rad)->dreapta;
//	(*rad)->dreapta = aux->stanga;
//	aux->stanga = (*rad);
//	(*rad) = aux;
//
//
//
//
//}
//void rotireDreapta(Nod**rad) {
//
//	Nod* aux = (*rad)->stanga;
//	(*rad)->stanga = aux->dreapta;
//	aux->dreapta = (*rad);
//	(*rad) = aux;
//
//}
//int calculeazaInaltimeArbore(Nod* rad) {
//	if (rad) {
//		int hs = calculeazaInaltimeArbore(rad->stanga);
//		int hd = calculeazaInaltimeArbore(rad->dreapta);
//		return 1 + (hs > hd ? hd : hd);
//	}
//	else {
//		return 0;
//	}
//}
//
//int calculeazaGe(Nod* rad) {
//	return calculeazaInaltimeArbore(rad->stanga) - calculeazaInaltimeArbore(rad->dreapta);
//}
//
//void adaugaMasinaInArbore(Nod** rad, Masina m) {
//
//	if ((*rad) != NULL) {
//		if (m.id < (*rad)->info.id) {
//			adaugaMasinaInArbore(&(*rad)->stanga, m);
//		}
//		else {
//			adaugaMasinaInArbore(&(*rad)->dreapta, m);
//		}
//
//		int GE = calculeazaGe(*rad);
//		if (GE == -2) {//dezechilibru dreapta
//			if (calculeazaGe((*rad)->dreapta) == 1) {
//				rotireDreapta(&(*rad)->dreapta);
//			}
//
//			rotireStanga(rad);
//		}
//
//		if (GE == 2) {//dezechilibru stanga
//			if (calculeazaGe((*rad)->stanga) == -1) {
//				rotireStanga(&(*rad)->stanga);
//			}
//
//			rotireDreapta(rad);
//		}
//
//	}
//	else {
//
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->dreapta = NULL;
//		nou->stanga = NULL;
//		nou->info = m;
//		nou->info.model = (char*)malloc(strlen(m.model) + 1);
//		strcpy( nou->info.model, m.model);
//		nou->info.numeSofer = (char*)malloc(strlen(m.numeSofer) + 1);
//		strcpy(nou->info.numeSofer, m.numeSofer);
//		(*rad) = nou;
//
//
//	}
//
//
//
//}
//
//
//Nod*  citireArboreMasiniDinFisier(const char* numeFisier) {
//
//	
//	FILE* f = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	if (f) {
//		while (!feof(f)) {
//
//			Masina m = citireMasinaDinFisier(f);
//			adaugaMasinaInArbore((&nou), m);
//			free(m.model);
//			free(m.numeSofer);
//
//
//		}
//
//	}
//	fclose(f);
//
//	return nou;
//
//}
//
//
//
//
//
//void afisareMasiniInOrdine(Nod* rad){
// 
//	if (rad != NULL) {
//		afisareMasiniInOrdine(rad->stanga);
//		afisareMasina(rad->info);
//		
//		afisareMasiniInOrdine(rad->dreapta);
//	}
//
//}
//
//void dezalocareArbore(Nod** rad) {
//
//	if ((*rad)) {
//
//		dezalocareArbore(&(*rad)->stanga);
//		dezalocareArbore(&(*rad)->dreapta);
//		free((*rad)->info.model);
//		free((*rad)->info.numeSofer);
//		free((*rad));
//	}
//
//	(*rad) = NULL;
//}
//
////calculeazaInaltimeArbore
//
//Masina getMasinaByid(Nod* rad, int id) {
//Masina m1;
//m1.id = -1;
// if(rad!=NULL)
// {
//	 if (id < rad->info.id) {
//		 return getMasinaByid(rad->stanga, id);
//	 }
//	 else if (id > rad->info.id) {
//		 return getMasinaByid(rad->dreapta, id);
//	 }
//	 else {
//		 return rad->info;
//	 }
// }
//
// return m1;
//
//
//}
//
//
//
//int main() {
//
//
//	Nod* nod = citireArboreMasiniDinFisier("masini_arbore.txt");
//	afisareMasiniInOrdine(nod);
//
//	printf("-------\n");
//	afisareMasina(getMasinaByid(nod, 3));
//	dezalocareArbore(&nod);
//	return 0;
//}