//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<stdbool.h>
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
//
//struct Nod {
//	Laptop info;
//	struct Nod* next;
//
//
//};
//typedef struct Nod Nod;
//
//struct HashTable {
//	Nod** tabela;
//	int dim;
//};
//typedef struct HashTable HashTable;
//
//Laptop citireLaptopDinFisier(FILE* file) {
//	Laptop laptop;
//	char buffer[100];
//	char* separator = " ,;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, separator);
//	if (token == NULL) return laptop;
//	laptop.id = atoi(token);
//	
//	token = strtok(NULL, separator);
//	if (token == NULL) return laptop;
//	laptop.marca = (char*)malloc(strlen(token)+1);
//	strcpy(laptop.marca, token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return laptop;
//	laptop.model = (char*)malloc(strlen(token)+1);
//	strcpy(laptop.model, token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return laptop;
//	laptop.pret = atof(token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return laptop;
//	laptop.anFabricatie = atoi(token);
//	
//	token = strtok(NULL, separator);
//	if (token == NULL) return laptop;
//	laptop.esteGaming = atoi(token)!=0;
//	
//	return laptop;
//
//	
//}
//
//void afisareLaptop(Laptop laptop) {
//	
//	printf("ID:%d\n ", laptop.id);
//	printf("Marca:%s\n ", laptop.marca);
//	printf("Model:%s\n ", laptop.model);
//	printf("Pret:%.2f\n ", laptop.pret);
//	printf("An fabricatie:%d\n ", laptop.anFabricatie);
//	printf("Este Gamming?:%d\n ", laptop.esteGaming);
//	printf("\n");
//	
//}
//
//void afisareListaLaptop(const Nod* cap) {
//
//	if (!cap) {
//		printf("Lista este goala\n");
//		return;
//	}
//
//	Nod* p = cap;
//	while (p) {
//		afisareLaptop(p->info);
//		p = p->next;
//	}
//	
//}
//
//void adaugaLaptopInListaFinal(Nod**cap,  Laptop LaptopNou) {
//
//	Nod* p = *cap;
//	while (p->next) {
//		p = p->next;
//	}
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = LaptopNou;
//	nou->next = NULL;
//	p->next = nou;
//
//	
//}
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.tabela = (Nod**)malloc(sizeof(Nod*)*dimensiune);
//	for (int i = 0; i < dimensiune; i++) {
//		ht.tabela[i] = NULL;
//	}
//
//	return ht;
//}
//
//int calculeazaHash(const char*marca, int dimensiune) {
//	
//	int suma = 0;
//	for (int i = 0; i < strlen(marca) ; i++) {
//		suma = suma + marca[i];
//	}
//
//	return suma % dimensiune;
//
//}
//
//void inserareLaptopInTabela(HashTable hash, Laptop laptop) {
//
//	int pozitie = calculeazaHash(laptop.marca, hash.dim);
//
//	if (hash.tabela[pozitie] == NULL) {
//		hash.tabela[pozitie] = (Nod*)malloc(sizeof(Nod));
//		hash.tabela[pozitie]->info = laptop;
//		hash.tabela[pozitie]->next = NULL;
//	}
//	else {
//		adaugaLaptopInListaFinal(&(hash.tabela[pozitie]), laptop);
//	}
//
//
//
//}
//
//HashTable citireLaptopDinTabela(const char* numeFisier, int dimensiune) {
//
//	HashTable ht = initializareHashTable(dimensiune);
//	FILE* f = fopen(numeFisier, "r");
//
//	while (!feof(f)) {
//		Laptop l = citireLaptopDinFisier(f);
//		inserareLaptopInTabela(ht, l);
//	}
//
//	fclose(f);
//	return ht;
//}
//
//void afisareTabelaDeLaptop(HashTable ht) {
//	
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.tabela[i] != NULL) {
//			printf("Laptopurile de pe pozitia %d sunt: \n", i);
//			afisareListaLaptop(ht.tabela[i]);
//		}
//		else {
//			printf("Nu sunt laptopuri pe pozitia %d\n",i);
//		}
//	}
//
//}
//
//
//
//void dezalocareListaLaptop(Nod** cap) {
//	Nod* p = *cap;
//	while (p) {
//		Nod* aux = p;
//		p = p->next;
//		if (aux->info.marca != NULL) {
//			free(aux->info.marca);
//			aux->info.marca = NULL;
//		}
//
//		if (aux->info.model != NULL) {
//			free(aux->info.model);
//			aux->info.model = NULL;
//		}
//
//		free(aux);
//	}
//
//	*cap = NULL;
//}
//
//void dezalocareTabelaDeMasini(HashTable *ht) {
//	
//	for (int i = 0; i < ht->dim; i++) {
//		dezalocareListaLaptop(&(ht->tabela[i]));
//	}
//
//
//	free(ht->tabela);
//	
//	ht->tabela = NULL;
//	ht->dim = 0;
//
//
//
//
//}
//
//float media(Nod* cap) {
//	float suma = 0;
//	int nrElemente = 0;
//	Nod* p = cap;
//	while (cap) {
//		suma = suma + cap->info.pret;
//		nrElemente++;
//		cap = cap->next;
//		
//	}
//	if(nrElemente>=0)
//	{
//		return suma / nrElemente;
//	}
//	
//}
//
//
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//
//
//	float* preturi = NULL;
//	 *nrClustere = 0;
//
//	 for (int i = 0; i < ht.dim; i++) {
//		 if (ht.tabela[i] != NULL) {
//			 (*nrClustere)++;
//		 }
//	 }
//
//	 preturi = (float*)malloc(sizeof(float) * (*nrClustere));
//	 int contor = 0;
//
//	 for (int i = 0; i < ht.dim; i++) {
//		 if (ht.tabela[i] != NULL) {
//			 preturi[contor] = media(ht.tabela[i]);
//			 contor++;
//		 }
//	 }
//
//	 return preturi;
//}
//
//Laptop getLaptopDupaNume(Nod* cap, const char* marcaCautata) {
//
//	Laptop l;
//	l.id = -1;
//	while (cap && strcmp(cap->info.marca, marcaCautata) != 0) {
//		
//			cap = cap->next;
//	
//	}
//	if (cap) {
//		l = cap->info;
//		l.marca = (char*)malloc(strlen(cap->info.marca) + 1);
//		strcpy(l.marca, cap->info.marca);
//	}
//
//	return l;
//
//}
//
//Laptop getLaptopDupaMarca(HashTable ht ,const char* marcaCautata ) {
//	Laptop l;
//	l.id = -1;
//	
//
//	int pozitie = calculeazaHash(marcaCautata, ht.dim);
//	if (pozitie >= 0 && pozitie < ht.dim) {
//		return getLaptopDupaNume(ht.tabela[pozitie], marcaCautata);
//	}
//
//	return l;
//
//
//
//
//}
//
//int main() {
//	HashTable ht = citireLaptopDinTabela("laptop.txt",11);
//	afisareTabelaDeLaptop(ht);
//
//
//	int nrClustere = 0;
//	float* medii = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//	printf("Mediile pe clustere:\n");
//	for (int i = 0; i < nrClustere; i++) {
//		printf("%.2f\n", medii[i]);
//	}
//	free(medii);
//	/*dezalocareTabelaDeMasini(&ht);*/
//
//	return 0;
//}