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
//
//	Student info;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
//
//Student citireStudentDinFisier(FILE* file) {
//
//	Student s = {0};
//	s.nume = NULL;
//	char buffer[100];
//	char* separator = " ,;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, separator);
//	if (token == NULL) return s;
//	s.id = atoi(token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return s;
//	s.varsta = atoi(token);
//
//	 token = strtok(NULL, separator);
//	if (token == NULL) return s;
//	s.nume = (char*)malloc(strlen(token) + 1);
//	strcpy(s.nume, token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return s;
//	s.medie = atof(token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return s;
//	s.initialaTata = (token[0]);
//
//	return s;
//
//}
//
//void afisareMasina(Student student) {
//
//	printf("ID:%d\n", student.id);
//	printf("Varsta:%d\n", student.varsta);
//	printf("Nume:%s\n", student.nume);
//	printf("Medie:%.2f\n", student.medie);
//	printf("Initiala Tata:%c\n", student.initialaTata);
//	printf("\n");
//
//
//}
//
//void afisareListaMasini(Nod* nod) {
//
//	Nod* p = nod;
//
//	while (p) {
//		afisareMasina(p->info);
//		p = p->next;
//	}
//
//}
//
//void adaugaStudentInListaFinal(Nod**cap, Student Studentnou) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = Studentnou;
//	nou->next = NULL;
//
//	if (*cap) {
//		Nod* p = (*cap);
//		
//		while(p->next) {
//
//			p = p->next;
//		}
//		
//		p->next = nou;
//
//	}
//	else {
//		(*cap) = nou;
//	}
//
//
//
//
//}
//
//void adaugaLaInceputInLista(Nod**cap, Student StudentNou) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = StudentNou;
//	nou->next = (*cap);
//	(*cap) = nou;
//}
//
//void* citireListaStudentDinFisier(const char* numeFisier) {
//	
//	FILE* f = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	
//
//	while (!feof(f)) {
//		Student s = citireStudentDinFisier(f);
//		adaugaStudentInListaFinal(&nou, s);
//
//	}
//	fclose(f);
//	return nou;
//
//
//}
//
//void dezalocareListaStudenti(Nod** nod) {
//	
//	while (*nod) {
//		Nod* p = *nod;
//		(*nod) = ((*nod)->next);
//		if (p->info.nume != NULL) {
//			free(p->info.nume);
//		}
//		free(p);
//
//	}
//
//
//}
//
//float calculeazamediaMedie(Nod* cap) {
//
//	float suma = 0;
//	int contor = 0;
//	Nod* p = cap;
//	while (p) {
//
//		suma = suma + p->info.medie;
//		p = p->next;
//		contor++;
//	}
//
//	if (contor == 0) return 0;
//
//	float media = suma / contor;
//
//	
//	return media;
//}
//
//void stergeStudentDinSeria(Nod**cap, int idCautat) {
//
//	Nod* deSters = (*cap);
//	if ((*cap) == NULL) {
//		return;
//	}
//
//	while ((*cap)->info.id==idCautat) {
//		Nod* deSters = (*cap);
//		(*cap) = (*cap)->next;
//		free(deSters->info.nume);
//		free(deSters);
//	}
//
//	Nod* p = (*cap);
//	while (p && p->next) {
//		if (p->next->info.id == idCautat) {
//			 deSters = p->next;
//			p->next = deSters->next;
//			free(deSters->info.nume);
//			free(deSters);
//		}
//		else {
//			p = p->next;
//		}
//
//	}
//
//
//
//}
//
//
//
//int main() {
//
//
//	Nod* nod = citireListaStudentDinFisier("student.txt");
//	afisareListaMasini(nod);
//
//	printf("Media este : %.2f \n", calculeazamediaMedie(nod));
//
//	dezalocareListaStudenti(&nod);
//	return 0;
//}