//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct AnimalCompanie {
//
//	int id;
//	char* nume;
//	char* specie;
//	int varsta;
//	float greutate;
//	char sex;
//
//
//
//};
//typedef struct AnimalCompanie AnimalCompanie;
//
//struct Nod {
//	AnimalCompanie info;
//	struct Nod* next;
//};
//
//typedef struct Nod Nod;
//
//struct HashTable {
//	int dim;
//	Nod** tabela;
//};
//typedef struct HashTable HashTable;
//
//AnimalCompanie citireAnimalCompanieDinFisier(FILE* file) {
//	
//	AnimalCompanie a;
//	char buffer[100];
//	char* delimitator = " ;,\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, delimitator);
//	if (token == NULL) return a;
//	a.id = atoi(token);
//
//	 token = strtok(NULL, delimitator);
//	if (token == NULL) return a;
//	a.nume = (char*)malloc(strlen(token) + 1);
//	strcpy(a.nume, token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return a;
//	a.specie = (char*)malloc(strlen(token) + 1);
//	strcpy(a.specie, token);
//	
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return a;
//	a.varsta = atoi(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return a;
//	a.greutate = atof(token);
//	
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return a;
//	a.sex = (token[0]);
//
//	return a;
//	
//
//
//}
//
//void afisareAnimalCompanie(AnimalCompanie AnimalCompanie) {
//	printf("Id: %d\n", AnimalCompanie.id);
//	printf("Nume. usi : %s\n", AnimalCompanie.nume);
//	printf("Specie: %s\n", AnimalCompanie.specie);
//	printf("Varsta: %d\n", AnimalCompanie.varsta);
//	printf("Greutate: %f\n", AnimalCompanie.greutate);
//	printf("Sex: %c\n\n", AnimalCompanie.sex);
//}
//
//void afisareListaMasini(Nod* cap) {
//
//	Nod* p = cap;
//	while (p!=NULL)
//	{
//		afisareAnimalCompanie(p->info);
//		p = p->next;
//
//	}
//
//
//}
//
//void adaugaAnimalCompanieInListaFinal(Nod**cap, AnimalCompanie AnimalCompanieNou) {
//	
//
//	Nod* p = *cap;
//	while (p->next) {
//		p = p->next;
//	}
//
//	
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = AnimalCompanieNou;
//		nou->next = NULL;
//		p->next = nou;
//	
//
//
//}
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.tabela = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0; i < dimensiune; i++) {
//		ht.tabela[i] = NULL;
//	}
//
//	return ht;
//}
//
//int calculeazaHash(const char* nume,int dimensiune) {
//	
//	int suma = 0;
//	for (int i = 0; i < strlen(nume); i++) {
//		suma = suma + nume[i];
//	}
//
//	return suma % dimensiune;
//
//}
//
//void inserareAnimalCompanieInTabela(HashTable hash, AnimalCompanie animal) {
//
//	int pozitie = calculeazaHash(animal.nume, hash.dim);
//	if (hash.tabela[pozitie] == NULL) {
//		hash.tabela[pozitie] = (Nod*)malloc(sizeof(Nod));
//		hash.tabela[pozitie]->info = animal;
//		hash.tabela[pozitie]->next = NULL;
//
//	}
//	else {
//		adaugaAnimalCompanieInListaFinal(&(hash.tabela[pozitie]), animal);
//	}
//
//
//
//}
//
//HashTable citireAnimalCompanieTABELA(const char* numeFisier, int dimensiune) {
//	
//	FILE* f = fopen(numeFisier, "r");
//	
//	HashTable ht = initializareHashTable(dimensiune);
//	while (!feof(f)) {
//		AnimalCompanie a = citireAnimalCompanieDinFisier(f);
//		inserareAnimalCompanieInTabela(ht, a);
//	}
//
//	fclose(f);
//	return ht;
//
//}
//
//void afisareTabelaDeMasini(HashTable ht) {
//	
//	
//	for (int i = 0; i < ht.dim; i++) {
//
//		if (ht.tabela[i] != NULL) {
//
//			printf("Cartile de pe pozitia %d sunt:\n", i);
//			afisareListaMasini(ht.tabela[i]);
//			
//		}
//		else {
//			printf("Nu sunt carti de afisat pe pozitia %d\n",i);
//		}
//		
//	}
//
//
//}
//
//void dezalocareLista(Nod** cap) {
//	Nod* p = (*cap);
//	while (p != NULL) {
//		Nod* aux = p;
//		p = p->next;
//
//		if (aux->info.nume != NULL) {
//			free(aux->info.nume);
//		}
//
//		if (aux->info.specie != NULL) {
//			free(aux->info.specie);
//		}
//
//		free(aux);
//	}
//	*cap = NULL;
//}
//
//
//void dezalocareTabelaDeMasini(HashTable *ht) {
//	
//
//	for (int i = 0; i < ht->dim; i++) {
//		dezalocareLista(&(ht->tabela[i]));
//	}
//
//	free(ht->tabela);
//	ht->tabela = NULL;
//	ht->dim = 0;
//}
//
//float media(Nod* cap) {
//
//	float rezultat = 0;
//	int contor = 0;
//	while (cap) {
//		rezultat = rezultat + cap->info.greutate;
//		contor++;
//		cap = cap->next;
//	}
//	if(contor>0)
//	{
//		return rezultat / contor;
//	}
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	
//	float* greutate = NULL;
//	*nrClustere = 0;
//	for(int i=0;i<ht.dim;i++)
//	{
//		if (ht.tabela != NULL) {
//			(*nrClustere)++;
//		}
//	}
//	 greutate = (float*)malloc(sizeof(float) * (*nrClustere));
//	int contor = 0;
//	for (int i = 0; i < ht.dim; i++) {
//		if(ht.tabela[i]!=NULL)
//		{
//			greutate[contor] = media(ht.tabela[i]);
//			contor++;
//		}
//	}
//
//	return greutate;
//}
//
//AnimalCompanie getAnimalCompanieDupaCheie(HashTable ht /*valoarea pentru AnimalCompanie cautata*/) {
//	AnimalCompanie m;
//	//cauta AnimalCompanie dupa valoarea atributului cheie folosit in calcularea hash-ului
//	//trebuie sa modificam numele functiei 
//	return m;
//}
//
//
//
//int main() {
//
//	
//
//	HashTable ht = citireAnimalCompanieTABELA("animal.txt", 10);
//	afisareTabelaDeMasini(ht);
//	int nrClustere = 0;
//	float* mediiPeClustere = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//
//	printf("Medii pe clustere \n");
//	for (int i = 0; i < nrClustere; i++) {
//		printf("%.2f\n",mediiPeClustere[i] );
//		
//	}
//	free(mediiPeClustere);
//
//	dezalocareTabelaDeMasini(&ht);
//	return 0;
//}