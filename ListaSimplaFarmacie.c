//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include<malloc.h>
//#include<stdio.h>
//#include<string.h>
//
//struct Farmacie {
//
//	int id;
//	char* nume;
//	unsigned char numarMedicamente;
//	float* preturiMedicamente;
//
//};
//typedef struct Farmacie Farmacie;
//struct Nod {
//	Farmacie info;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
//void afisare(struct Farmacie f) {
//	printf("Farmacia cu id-ul %d, si numele %s, are un numar de medicamente de %hhu, cu preturile: \n\n",
//		f.id,  f.nume,f.numarMedicamente);
//	for (int i = 0; i < f.numarMedicamente; i++){
//		printf(" %5.2f, ", f.preturiMedicamente[i]);
//	}
//
//	printf("\n\n");
//}
//struct Farmacie citireFarmacieDinFisier(FILE* file) {
//	struct Farmacie f = { 0, NULL, 0, NULL };
//	char buffer[100];
//	char delimitator[4] = ".;\n";
//
//	if (fgets(buffer, sizeof(buffer), file)) {
//		char* token = strtok(buffer, delimitator);
//		if (token == NULL) return f;
//		f.id = atoi(token);
//
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return f;
//		f.nume = (char*)malloc(strlen(token) + 1);
//		strcpy(f.nume, token);
//
//		token = strtok(NULL, delimitator);
//		if (token == NULL) {
//			free(f.nume);
//			f.nume = NULL;
//			return f;
//		}
//		f.numarMedicamente = (unsigned char)atoi(token);
//
//		f.preturiMedicamente = (float*)malloc(sizeof(float) * f.numarMedicamente);
//		for (int i = 0; i < f.numarMedicamente; i++) {
//			token = strtok(NULL, delimitator);
//			if (token == NULL) {
//				free(f.nume);
//				free(f.preturiMedicamente);
//				f.nume = NULL;
//				f.preturiMedicamente = NULL;
//				return f;
//			}
//			f.preturiMedicamente[i] = atof(token);
//		}
//	}
//	return f;
//}
//
//
//
//
//
//
//void afisareListaMasini(Nod* nod) {
//	
//	while (nod != NULL) {
//		afisare(nod->info);
//		nod = nod->next;
//	}
//
//
//	
//}
//
//void adaugaMasinaInListaLaSfarsit(Nod**nod,  Farmacie masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//
//	if (*nod) {
//		Nod* p = (*nod);
//		while (p->next!=NULL) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//
//		(*nod) = nou;
//
//	}
//
//
//}
//
//void adaugaLaInceputInLista(Nod** nod, Farmacie farmacieNoua) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = farmacieNoua;
//	nou->next = (*nod);
//	(*nod) = nou;
//
//
//
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//
//	Nod* nou = NULL;
//
//	FILE* f = fopen(numeFisier, "r");
//if(f)
//{
//	while (!feof(f)) {
//		Farmacie farmacie = citireFarmacieDinFisier(f);
//		adaugaLaInceputInLista(&nou, farmacie);
//	}
//	fclose(f);
//	return nou;
//}
//
//}
//
//void dezalocareListaMasini(Nod** nod) {
//	
//	while (*nod) {
//		Nod* p = (*nod);
//		*nod = p->next;
//		if (p->info.nume != NULL) {
//			free(p->info.nume);
//		}
//		if (p->info.preturiMedicamente != NULL) {
//			free(p->info.preturiMedicamente);
//		}
//
//		free(p);
//
//	}
//
//
//}
//
//float calculeazaPretMediu(Nod* cap) {
//	//calculeaza pretul mediu al masinilor din lista.
//	return 0;
//}
//
//void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
//	//sterge toate masinile din lista care au seria primita ca parametru.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//void main() {
//
//
//	Nod * cap = citireListaMasiniDinFisier("farmacie.txt");
//	afisareListaMasini(cap);
//	dezalocareListaMasini(&cap);
//
//
//	return 0;
//}