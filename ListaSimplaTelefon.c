//#define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//struct Telefon {
//
//	int id;
//	char* nume;
//	char* firmaProducatoare;
//	float pret;
//	unsigned int anFabricatie;
//	bool dualSim;
//
//};
//
//typedef struct Telefon Telefon;
//
//struct Nod {
//	Telefon info;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//Telefon citireTelefonDinFisier(FILE* file) {
//
//	Telefon t;
//	t.firmaProducatoare = NULL;
//	t.nume = NULL;
//
//	char buffer[100];
//	char* delimitator = ",;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, delimitator);
//	if (token == NULL) return t;
//	t.id = atoi(token);
//
//	token =strtok (NULL, delimitator);
//	if (token == NULL) return t;
//	t.nume = (char*)malloc(strlen(token) + 1);
//	strcpy(t.nume, token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return t;
//	t.firmaProducatoare = (char*)malloc(strlen(token) + 1);
//	strcpy(t.firmaProducatoare, token);
//
//	token = strtok (NULL, delimitator);
//	if (token == NULL) return t;
//	t.pret = atof(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return t;
//	t.anFabricatie = atoi(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return t;
//	t.dualSim = atoi(token) != 0;;
//
//	return t;
//	
//}
//
//void afisareTelefon(Telefon telefon) {
//
//	printf("Id:%d\n", telefon.id);
//	printf("NumeTelefon:%s\n", telefon.nume);
//	printf("Firma Producatoare:%s\n", telefon.firmaProducatoare);
//	printf("Pret:%.2f\n", telefon.pret);
//	printf("An Fabricatie:%d\n", telefon.anFabricatie);
//	printf("Are DualSIM:%d\n", telefon.dualSim);
//	printf("\n");
//
//}
//
//void afisareListaTelefoane(Nod* nod) {
//
//	while (nod != NULL) {
//		afisareTelefon(nod->info);
//		nod = nod->next;
//	}
//
//}
//
//void adaugaTelefonInListaSFARSIT(Nod** cap, Telefon telefonNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = telefonNou;
//	nou->next = NULL;
//
//	if (*cap) {
//		Nod* p = (*cap);
//		while (p->next)
//		{
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		(*cap) = nou;
//	}
//
//
//}
//
//void adaugaLaInceputInLista(Nod** cap, Telefon telefonNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = telefonNou;
//	nou->next = (*cap)
//	nou = (*cap);
//
//}
//
//Nod* citireListaTelefonDinFisier(const char* numeFisier) {
//
//	Nod* nod = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file)
//	{
//		while (!feof(file)) {
//			Telefon t = citireTelefonDinFisier(file);
//			if (t.nume != NULL && t.firmaProducatoare != NULL)
//			{
//				adaugaTelefonInListaSFARSIT(&nod, t);
//			}
//		}
//	}
//
//	fclose(file);
//	return nod;
//
//
//}
//void dezalocareNod(Nod* nod) {
//	if (nod != NULL) {
//		if (nod->info.nume != NULL) {
//			free(nod->info.nume);
//		}
//		if (nod->info.firmaProducatoare != NULL) {
//			free(nod->info.firmaProducatoare);
//		}
//		free(nod);
//
//	}
//}
//
//void dezalocareListaTelefoane(Nod** nod) {
//
//	while (*nod != NULL) {
//
//		Nod* p = (*nod);
//		(*nod) = p->next;
//		dezalocareNod(p);
//	}
//}
//
//float calculeazaPretMediu(Nod* cap) {
//
//	float suma = 0;
//	int contor = 0;
//	while (cap) {
//		suma = suma + cap->info.pret;
//		contor++;
//		cap = cap->next;
//	}
//	if (contor > 0)
//	{
//		return suma = suma / contor;
//	}
//
//	return 0;
//}
//
//
//
//void stergeTelefonDupaFirma(Nod** cap, const char* firmaCautata) {
//
//	while ((*cap) && strcmp((*cap)->info.firmaProducatoare,firmaCautata)==0){
//
//		Nod* aux = (*cap);
//		(*cap) = aux->next;
//		dezalocareNod(aux);
//	}
//
//	Nod* p = *cap;
//	while (p && p->next) {
//		if (strcmp(p->next->info.firmaProducatoare, firmaCautata) == 0) {
//			Nod* aux = p->next;
//			p->next = aux->next;
//			dezalocareNod(aux);
//		}
//		else {
//			p = p->next;
//		}
//	}
//
//
//	}
//	
//
//float calculeazaPretulTelefonuluiUnuiProducator(Nod*cap, const char* numeProducator) {
//	
//	float suma = 0;
//	while(cap)
//	{
//		if (strcmp(cap->info.firmaProducatoare,numeProducator) == 0) {
//			suma = suma + cap->info.pret;
//			
//		}
//
//		cap = cap->next;
//	}
//	
//	return suma;
//}
//
//
//
//int main(){
//
//	Nod* lista = citireListaTelefonDinFisier("telefon.txt");
//	afisareListaTelefoane(lista);
//	printf("Pretul mediu din lista este:%.2f\nn", calculeazaPretMediu(lista));
//	printf("Pretul unui telefon al firmei x este :%.2f\n", calculeazaPretulTelefonuluiUnuiProducator(lista,"Samsung"));
//	afisareListaTelefoane(lista);
//	stergeTelefonDupaFirma(&lista, "Apple");
//	printf("------------Dupa Stergere------\n");
//	afisareListaTelefoane(lista);
//	dezalocareListaTelefoane(&lista);
//	return 0;
//}