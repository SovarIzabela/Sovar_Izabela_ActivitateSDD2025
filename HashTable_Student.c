//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include <string.h>
//#include<stdlib.h>
//
//struct Student {
//	int id;
//	int varsta;
//	char* nume;
//	float medie;
//	char initialaTata;
//};
//typedef struct Student Student;
//
//struct Nod {
//	Student info;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct HashTable {
//	int dim;
//	Nod** tabela;
//};
//typedef struct HashTable HashTable;
//
//Student citireStudentDinFisier(FILE* f) {
//	Student s;
//	s.nume = NULL;
//	char buffer[100];
//	char delimitator[4] = ",;\n";
//	fgets(buffer, 100, f);
//			
//	char* token = strtok(buffer, delimitator);
//	if (token == NULL) return s;
//	s.id = atoi(token);
//	
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return s;
//	s.varsta = atoi(token);
//	
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return s;
//	s.nume = (char*)malloc(strlen(token) + 1);
//	strcpy(s.nume, token);
//	
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return s;
//	s.medie = atof(token);
//	
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return s;
//	s.initialaTata = token[0];
//	
//	return s;
//}
//
//void afisareStudent(Student student) {
//	printf("ID:%d\n", student.id);
//	printf("Varsta:%d\n", student.varsta);
//	printf("Nume:%s\n", student.nume);
//	printf("Medie:%.2f\n", student.medie);
//	printf("InitialaTata:%c\n", student.initialaTata);
//	printf("\n");
//}
//
//void afisareListaStudenti(Nod*cap) {
//	while (cap) {
//		afisareStudent(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaStudentInListaFinal(Nod*cap,Student StudentNou) {
//	
//	Nod* p = cap;
//	while (p->next) {
//		p = p->next;
//	}
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = StudentNou;
//	nou->next = NULL;
//	p->next = nou;
//
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
//int calculeazaHash(const char*nume, int dimensiune) {
//	int suma = 0;
//	for (int i = 0; i < strlen(nume); i++) {
//		suma += nume[i];
//	}
//	return suma % dimensiune;
//}
//
//void inserareStudentInTabela(HashTable hash, Student student) {
//
//
//	int pozitie = calculeazaHash(student.nume, hash.dim);
//	if (hash.tabela[pozitie] == NULL) {
//		hash.tabela[pozitie] = (Nod*)malloc(sizeof(Nod));
//		hash.tabela[pozitie]->info = student;
//		hash.tabela[pozitie]->next = NULL;
//
//	}
//	else {
//		adaugaStudentInListaFinal(hash.tabela[pozitie], student);
//	}
//
//
//}
//
//HashTable citireStudentiDinFisier(const char* numeFisier, int dimensiune) {
//	HashTable h = initializareHashTable(dimensiune);
//	FILE* f = fopen(numeFisier, "r");
//
//	while (!feof(f)) {
//		Student s = citireStudentDinFisier(f);
//		if(s.nume!=NULL)
//		{
//			inserareStudentInTabela(h, s);
//		}
//
//	}
//
//	fclose(f);
//	return h;
//}
//
//void afisareTabelaDeStudenti(HashTable ht) {
//	
//
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.tabela[i] != NULL) {
//			printf("Masinile de pe pozitia %d\n", i);
//			afisareListaStudenti(ht.tabela[i]);
//		}
//		else {
//			printf("Nu sunt studenti\n");
//		}
//	}
//}
//
//void dezalocareListaStudenti(Nod** cap) {
//
//	Nod* p = *cap;
//	while (p) {
//		Nod* aux = p;
//		p = p->next;
//		if (aux->info.nume != NULL) {
//			free(aux->info.nume);
//		}
//		free(aux);
//	}
//
//	*cap = NULL;
//}
//
//void dezalocareTabelaDeStudenti(HashTable *ht) {
//	
//	for (int i = 0; i < ht->dim; i++) {
//		dezalocareListaStudenti(&(ht->tabela[i]));
//
//		
//	}
//
//	free(ht->tabela);
//	ht->tabela = NULL;
//	ht->dim = 0;
//}
//
//float media(Nod* cap) {
//	float suma = 0;
//	int nrElemente = 0;
//	while (cap != NULL) {
//		suma += cap->info.medie;
//		nrElemente++;
//		cap = cap->next;
//	}
//	if (nrElemente > 0) {
//		return suma / nrElemente;
//	}
//	
//}
//
//float* calculeazaMediilePerClustere(HashTable ht, int* nrClustere){
//	
//	float* preturi = NULL;
//	*nrClustere = 0;
//
//	for (int i = 0; i < ht.dim; i++) {
//
//		if(ht.tabela[i]!=NULL)
//		{
//			(*nrClustere)++;
//		}
//	}
//
//	preturi = (float*)malloc(sizeof(float) * (*nrClustere));
//	int contor = 0;
//	
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.tabela[i] != NULL) {
//			preturi[contor] = media(ht.tabela[i]);
//			contor++;
//		}
//	}
//
//	return preturi;
//}
//
//Student getStudentDinLista(Nod* cap, const char* numeCautat) {
//	Student s;
//	s.id = -1;
//	while (cap && strcmp(cap->info.nume, numeCautat) != 0) {
//		cap = cap->next;
//	}
//	if (cap) {
//		s = cap->info;
//		s.nume = (char*)malloc(strlen(cap->info.nume) + 1);
//		strcpy(s.nume, cap->info.nume);
//
//	}
//
//	return s;
//}
//
//Student getStudentDupaNume(HashTable ht, const char*numeCautat) {
//	Student s;
//	s.id = -1;
//
//	int poz = calculeazaHash(numeCautat, ht.dim);
//	if (poz >= 0 && poz < ht.dim) {
//		return getStudentDinLista(ht.tabela[poz], numeCautat);
//	}
//	
//	return s;
//}
//
//int main() {
//
//	HashTable ht = citireStudentiDinFisier("student.txt", 7);
//	afisareTabelaDeStudenti(ht);
//	int nrClustere = 0;
//	float* medii = calculeazaMediilePerClustere(ht, &nrClustere);
//	printf("Mediile pe clustere: \n");
//	for (int i = 0; i < nrClustere; i++) {
//		printf("%.2f", medii[i]);
//	}
//
//	Student s = getStudentDupaNume(ht, "MihaiIonescu");
//	printf("Studentul cautat\n");
//	afisareStudent(s);
//	if (s.nume != NULL) {
//		free(s.nume);
//	}
//
//	dezalocareTabelaDeStudenti(&ht);
//	return 0;
//}