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
//
// Student citireStudentFisier(FILE* f) {
//	
//			struct Student s;
//			s.nume = NULL;
//			char buffer[100];
//			char delimitator[4] = ",;\n";
//			fgets(buffer, 100, f);
//			
//			char* token = strtok(buffer, delimitator);
//			if (token == NULL) return s;
//			s.id = atoi(token);
//	
//			token = strtok(NULL, delimitator);
//			if (token == NULL) return s;
//			s.varsta = atoi(token);
//	
//			token = strtok(NULL, delimitator);
//			if (token == NULL) return s;
//			s.nume = (char*)malloc(strlen(token) + 1);
//			strcpy(s.nume, token);
//	
//			token = strtok(NULL, delimitator);
//			if (token == NULL) return s;
//			s.medie = atof(token);
//	
//			token = strtok(NULL, delimitator);
//			if (token == NULL) return s;
//			s.initialaTata = token[0];
//	
//			return s;
//			
//			
//	
//}
//
//typedef struct Nod Nod;
//void afisareStudent(struct Student s)
//{
//	printf("Studentul cu id-ul %d si nume %s are varsta %d ani, media %5.2f si initiala tatalui %c\n\n",
//		s.id, s.nume, s.varsta, s.medie, s.initialaTata);
//}
//
//void afisareListaStud(Nod * cap) {
//
//	while (cap != NULL) {
//		afisareStudent(cap->info);
//		cap = cap->next;
//	}
//
//}
//
//void adaugareStudentInListaFinal(Nod**cap, Student studentNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = studentNou;
//	nou->next = NULL;
//	if (*cap) {
//		Nod* p = *cap;
//		while (p->next) {
//			p = p->next;
//		}
//
//		p->next = nou;
//	}
//	else {
//		(*cap) = nou;
//	}
//}
//
//void adaugaStudentInListaInceput(Nod** cap, Student studentNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = studentNou;
//	nou->next = NULL;
//	(*cap) = nou;
//}
//
//Nod* citireListaDinFisier(const char* numeFisier) {
//	Nod* cap = NULL;
//	FILE* f = fopen(numeFisier, "r");
//
//	if (f) {
//		while (!feof(f)) {
//			Student s = citireStudentFisier(f);
//			if (s.nume != NULL)
//			adaugareStudentInListaFinal(&cap, s);
//		}
//	}
//	  
//	fclose(f);
//	return cap;
//
//}
//
//void dezalocareLista(Nod**cap) {
//
//	while (*cap) {
//		Nod* p = *cap;
//		(*cap) = (*cap)->next;
//		if (p->info.nume) {
//			free (p->info.nume);
//		}
//
//		free(p);
//	}
//
//}
//
//
//void main() {
//
//
//	Nod* cap = citireListaDinFisier("student.txt");
//	afisareListaStud(cap);
//	dezalocareLista(&cap);
//
//}