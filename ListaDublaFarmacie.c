//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
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
//
//
//struct Nod {
//
//	Farmacie info;
//	struct Nod* prev;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
//
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//};
//typedef struct ListaDubla ListaDubla;
//
//Farmacie citireFarmacieDinFisier(FILE* file) {
//	Farmacie f = { 0, NULL, 0, NULL };
//	char buffer[300];
//	char* separator = ",;\n";
//
//	if (fgets(buffer, sizeof(buffer), file) != NULL) {
//		char* token = strtok(buffer, separator);
//		if (token == NULL) return f;
//		f.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		if (token == NULL) return f;
//		f.nume = (char*)malloc(strlen(token) + 1);
//		if (f.nume) {
//			strcpy(f.nume, token);
//		}
//
//		token = strtok(NULL, separator);
//		if (token == NULL) {
//			free(f.nume);
//			f.nume = NULL;
//			return f;
//		}
//		f.numarMedicamente = (unsigned char)atoi(token);
//
//		f.preturiMedicamente = (float*)malloc(sizeof(float) * f.numarMedicamente);
//		if (f.preturiMedicamente == NULL) {
//			free(f.nume);
//			f.nume = NULL;
//			return f;
//		}
//
//		for (int i = 0; i < f.numarMedicamente; i++) {
//			token = strtok(NULL, separator);
//			if (token == NULL) {
//				free(f.nume);
//				free(f.preturiMedicamente);
//				f.nume = NULL;
//				f.preturiMedicamente = NULL;
//				f.numarMedicamente = 0;
//				return f;
//			}
//			f.preturiMedicamente[i] = (float)atof(token);
//		}
//	}
//
//	return f;
//}
//
//
//void afisareFarmacii(Farmacie farmacie) {
//
//	printf("ID este : %d\n", farmacie.id);
//	printf("Numele farmaciei este : %s\n", farmacie.nume);
//	printf("Numar de medicamente : %d\n", farmacie.numarMedicamente);
//	printf("Preturile sunt:\n");
//	for(int i=0;i<farmacie.numarMedicamente;i++)
//	{
//		printf(" : %.2f\n", farmacie.preturiMedicamente[i]);
//	}
//	printf("\n");
//	
//}
//
//void afisareListaFarmaciiINCEPUT(ListaDubla lista) {
//	Farmacie f;
//	Nod* p = lista.first;
//	while (p) {
//
//		afisareFarmacii(p->info);
//		p = p->next;
//	}
//
//
//}
//
//void afisareListaFarmaciiSfarsit(ListaDubla lista) {
//	Farmacie f;
//	Nod* p = lista.last;
//	while (p) {
//
//		afisareFarmacii(p->info);
//		p = p->prev;
//	}
//
//
//}
//
//void adaugaFarmacieInListaFINAL(ListaDubla*lista, Farmacie FarmacieNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = FarmacieNoua;
//	nou->next = NULL;
//	nou->prev = lista->last;
//
//	if (lista->last == NULL) {
//		lista->first = lista->last = nou;
//	}
//	else {
//		lista->last->next = nou;
//		nou->prev = lista->last;
//		lista->last = nou;
//	}
//	;
//	lista->nrNoduri++;
//
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Farmacie FarmacieNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = FarmacieNoua;
//	nou->next = NULL;
//	nou->prev = lista->first;
//
//	if (lista->first == NULL) {
//		lista->first=lista->last = nou;
//	}
//	else {
//		lista->first->prev = nou;
//		lista->first = nou;
//	}
//
//	
//	lista->nrNoduri++;
//
//}
//
//ListaDubla citireLDFarmacieDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	if (f == NULL) {
//		printf("Eroare la deschiderea fisierului %s\n", numeFisier);
//		return lista;
//	}
//
//	Farmacie farmacie;
//	while ((farmacie = citireFarmacieDinFisier(f)).nume != NULL) {
//		adaugaLaInceputInLista(&lista, farmacie);
//	}
//
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDFarmacie(ListaDubla* lista) {
//	Nod* p = lista->first;
//	while (p) {
//		Nod* aux = p;
//		p = p->next;
//		if (aux->info.nume != NULL) {
//			free(aux->info.nume);
//		}
//		if (aux->info.preturiMedicamente != NULL) {
//			free(aux->info.preturiMedicamente);
//		}
//		free(aux);
//	}
//
//	
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	if(lista.first)
//	{
//		float suma = 0;
//		int nrTotalMedicamente = 0;
//		Nod* p = lista.first;
//		while (p) {
//			for(int i = 0; i<p->info.numarMedicamente;i++)
//			{
//				suma = suma + p->info.preturiMedicamente[i];
//				nrTotalMedicamente++;
//				
//			}
//			p = p->next;
//
//		}
//
//		return suma / nrTotalMedicamente;
//	}
//
//	return 0;
//}
//
//void stergeFarmacieDupaID(ListaDubla*lista, int id) {
//	
//	if (lista->first == NULL) {
//		return;
//	}
//
//	Nod* p = lista->first;
//	while (p&&p->info.id != id) {
//		p = p->next;
//	}
//	if (p == NULL) {
//		return;
//	}
//
//	if (p->prev == NULL) {
//		lista->first = p->next;
//		if (lista->first) {
//			lista->first->prev = NULL;
//		}
//
//	}
//	else {
//		p->prev->next = p->next;
//	}
//
//	if (p->next!=NULL) {
//		p->next->prev = p->prev;
//
//	}
//	else {
//		lista->last = p->prev;
//	}
//
//	if (p->info.nume != NULL) {
//		free(p->info.nume);
//	}
//	if (p->info.preturiMedicamente != NULL) {
//		free(p->info.preturiMedicamente);
//	}
//	free(p);
//	p->info.nume = NULL;
//	p->info.preturiMedicamente = NULL;
//	lista->nrNoduri--;
//
//
//}
//
//char* getNumeSoferMasinaScumpa(ListaDubla lista) {
//	/*cauta farmacia cu cel mai scump medicament
//	returneaza numele farmaciei.*/
//	
//	if (lista.first == NULL) {
//		return NULL;
//	}
//
//
//	Nod* p = lista.first;
//	Nod* maxFarmacie = NULL;
//	float maxPret = 0;
//		while (p) {
//		for(int i =0;i<p->info.numarMedicamente;i++)
//		{
//			if (p->info.preturiMedicamente[i] > maxPret) {
//				maxPret = p->info.preturiMedicamente[i];
//				maxFarmacie = p;
//			}
//		}
//
//			p = p->next;
//		}
//
//		if(maxFarmacie)
//
//		{
//			char* numeF = (char*)malloc(strlen(maxFarmacie->info.nume) + 1);
//			strcpy(numeF, maxFarmacie->info.nume);
//			return numeF;
//		}
//		else {
//			return NULL;
//		}
//
//		
//	
//
//	
//}
//
//int main() {
//
//	
//
//	ListaDubla lista = citireLDFarmacieDinFisier("farmacie.txt");
//
//	afisareListaFarmaciiINCEPUT(lista);
//
//	return 0;
//}