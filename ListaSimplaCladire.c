//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include<malloc.h>
//#include<stdio.h>
//#include<string.h>
//
//struct StructBloc {
//
//	int nrEtaje;
//	int nrApartamente;
//	float pretMediuMP;
//	char* adresa;
//	int anConstructie;
//	unsigned char tipCertificatEnergetic;
//
//};
//typedef struct StructBloc Bloc;
//
//struct Nod {
//	Bloc info;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
//Bloc citireBlocDinFisier(FILE* file) {
//		
//	
//		Bloc b;
//		char buffer[100];
//		char delimitator[4] =  ",;\n" ;
//		fgets(buffer, 100, file);
//	
//	
//		b.nrEtaje = atoi(strtok(buffer, delimitator));
//		b.nrApartamente = atoi(strtok(NULL,delimitator));
//		b.pretMediuMP = atof(strtok(NULL, delimitator));
//		char* aux;
//		aux = strtok(NULL, delimitator);
//		b.adresa = (char*)malloc(strlen(aux) + 1);
//		strcpy(b.adresa, aux);
//		
//		b.anConstructie = atoi(strtok(NULL, delimitator));
//		b.tipCertificatEnergetic = strtok(NULL, delimitator)[0];
//	
//	
//		return b;
//		
//	}
//
//void afisareBloc(Bloc bloc) {
//		printf("Nr Etaje: %d\n", bloc.nrEtaje);
//		printf("Nr Apartamente: %d\n", bloc.nrApartamente);
//		printf("Pret Mediu MP: %.2f\n", bloc.pretMediuMP);
//		printf("Adresa: %s\n", bloc.adresa);
//		printf("An constructie: %d\n", bloc.anConstructie);
//		printf("Tip Certificat Energetic: %c\n\n", bloc.tipCertificatEnergetic);
//		
//	}
//void afisareListaMasini(Nod * nod) {
//
//	while (nod!=NULL) {
//		afisareBloc(nod->info);
//		nod = nod->next;
//	}
//	
//	
//}
//
//void adaugaMasinaInLista(Nod**nod, Bloc blocNou ) {
//
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = blocNou;
//	nou->next = NULL;
//
//	if (nod) {
//		Nod* p = (*nod);
//
//		while (p->next != NULL) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		*nod = nou;
//	}
//}
//
//void adaugaLaInceputInLista(Nod** nod, Bloc blocNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = blocNou;
//	nou->next = (*nod);
//	*nod = nou;
//
//	
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//	
//	Nod* cap = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f) {
//		while (!feof(f)) {
//
//			adaugaLaInceputInLista(&cap, citireBlocDinFisier(f));
//			
//		}
//	}
//	fclose(f);
//	return cap;
//
//}
//
//void dezalocareListaMasini(Nod**cap) {
//	
//	
//		while (*cap){
//
//			Nod* p = *cap;
//			*cap = p->next;
//			if (p->info.adresa) {
//				free(p->info.adresa);
//			}
//			free(p);
//	}
//
//}
//
//float calculeazaPretMediu(/*lista de masini*/) {
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
//
//void main() {
//
//	Nod* cap = citireListaMasiniDinFisier("bloc.txt");
//	afisareListaMasini(cap);
//	dezalocareListaMasini(&cap);
//
//	return 0;
//
//}