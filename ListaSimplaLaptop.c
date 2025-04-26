//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<stdbool.h>
//
//
//
//struct Laptop {
//
//	int id;
//	char* marca;
//	char* model;
//	float pret;
//	int anFabricatie;
//	bool esteGaming;
//	
//};
//typedef struct Laptop Laptop;
//
//struct Nod {
//	Laptop info;
//	struct Nod* next;
//
//
//};
// 
//typedef struct Nod Nod;
//
//Laptop citireLaptopDinFisier(FILE* file) {
//
//	Laptop l;
//	l.marca = NULL;
//	l.model = NULL;
//	
//	char buffer[100];
//	char* separator = ",;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, separator);
//	if (token == NULL) return l;
//	l.id = atoi(token);
//
//	//char* marca;
//	token = strtok(NULL, separator);
//	if (token == NULL) return l;
//	l.marca = (char*)malloc(strlen(token)+1);
//	strcpy(l.marca, token);
//
//	//char* model;
//	token = strtok(NULL, separator);
//	if (token == NULL) return l;
//	l.model = (char*)malloc(strlen(token)+1);
//	strcpy(l.model, token);
//
//	/*float pret;*/
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return l;
//	l.pret = atof(token);
//
//	/*int anFabricatie;*/
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return l;
//	l.anFabricatie = atoi(token);
//
//	/*bool esteGaming;*/
//	token = strtok(NULL, separator);
//	if (token == NULL) return l;
//	l.esteGaming = atoi(token) != 0;
//
//	
//	return l;
//	
//}
//
//void afisareLaptop(Laptop laptop) {
//
//	printf("ID: %d\n", laptop.id);
//	printf("Marca: %s\n", laptop.marca);
//	printf("Model: %s\n", laptop.model);
//	printf("Pret: %.2f\n", laptop.pret);
//	printf("An fabricarie: %d\n", laptop.anFabricatie);
//	printf("Este Gamming: %d\n", laptop.esteGaming);
//	printf("\n");
//
//}
//
//
//
//void afisareListaLaptop(Nod* cap) {
//
//	while (cap) {
//
//		afisareLaptop(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaLaptopInListasfarsit(Nod **cap, Laptop LaptopNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = LaptopNou;
//	nou->next = NULL;
//	if (*cap) {
//		Nod* p = (*cap);
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//
//	}
//	else
//	{
//		(*cap) = nou;
//		
//	}
//
//
//
//}
//
//
//void adaugaLaInceputInLista(Nod** cap, Laptop LaptopNou) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = LaptopNou;
//	nou->next = *cap;
//	(*cap) = nou;
//
//
//
//}
//
//Nod* citireListaLaptopDinFisier(const char* numeFisier) {
//
//	Nod* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file) {
//		while (!feof(file)) {
//			Laptop laptop = citireLaptopDinFisier(file);
//			if (laptop.marca != NULL && laptop.model != NULL)
//			{
//				adaugaLaptopInListasfarsit(&cap, laptop);
//			}
//			
//		}
//
//
//		fclose(file);
//		return cap;
//
//
//	}
//}
//void dezalocareNod(Nod* nod) {
//
//	if (nod != NULL) {
//		if (nod->info.marca != NULL) {
//			free(nod->info.marca);
//		}
//		if (nod->info.model != NULL) {
//			free(nod->info.model);
//		}
//
//		free(nod);
//	}
//
//
//
//}
//
//void dezalocareListaLaptop(Nod**cap) {
//
//	
//	while (*cap!=NULL) {
//		Nod* aux = (*cap);
//		*cap = (*cap)->next;
//		dezalocareNod(aux);
//	}
//
//	
//}
//
//float calculeazaPretMediu(Nod* nod) {
//	
//	float suma = 0;
//	int contor = 0;
//
//	while (nod) {
//		suma = suma + nod->info.pret;
//		contor++;
//		nod = nod->next;
//	}
//	if (contor > 0) {
//		return  suma / contor;
//	}
//
//	return 0;
//}
//
//void stergeLaptopDinMarca(Nod**cap, const char* marcaCautata) {
//	while ((*cap) && strcmp((*cap)->info.marca, marcaCautata) == 0) {
//		Nod* p = (*cap);
//		(*cap) = (*cap)->next;
//		dezalocareNod(p);
//	}
//
//	
//	Nod* aux = (*cap);
//
//	while (aux &&aux->next) {
//		if (strcmp(aux->next->info.marca, marcaCautata) == 0) {
//			Nod* p = aux->next;
//			aux->next = p->next;
//			dezalocareNod(p);
//		}
//		else {
//			aux = aux->next;
//		}
//
//	}
//
//	
//
//
//	
//}
//
//float calculeazaPretulLaptopMarca(Nod*cap, const char* marca) {
//	
//	float suma = 0;
//	while(cap)
//	{
//		if (strcmp(cap->info.marca, marca) == 0) {
//
//			suma = suma + cap->info.pret;
//		}
//
//		cap = cap->next;
//	}
//
//
//	return suma;
//}
//
//int main() {
//
//
//	Nod* nou = citireListaLaptopDinFisier("laptop.txt");
//	afisareListaLaptop(nou);
//
//	stergeLaptopDinMarca(&nou, "Dell");
//	printf("-----STERGERE------\n");
//	afisareListaLaptop(nou);
//
//	dezalocareListaLaptop(&nou);
//
//
//
//	return 0;
//}