//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct Student {
//		int id;
//		int varsta;
//		char* nume;
//		float medie;
//		char initialaTata;
//};
//typedef struct Student Student;
//
//struct Nod {
//	Student info;
//	struct Nod* prev;
//	struct Nod* next;
//
//};
//typedef struct Nod Nod;
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//};
//typedef struct ListaDubla ListaDubla;
//
//Student citireStudentDinFisier(FILE* file) {
//	Student s = { 0 };
//	char buffer[100];
//	char* separator = " ,;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, separator);
//	if (token==NULL) return s;
//	s.id = atoi(token);
//
//	token = strtok(NULL, separator);
//	if (token == NULL) return s;
//	s.varsta = atoi(token);
//	
//	token = strtok(NULL, separator);
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
//	s.initialaTata = (token)[0];
//	
//	return s;
//
//	
//}
//
//void afisareStudent(Student student) {
//	
//	printf("ID:%d\n", student.id);
//	printf("Varsta:%d\n", student.varsta);
//	printf("Nume:%s\n", student.nume);
//	printf("Medie:%.2f\n", student.medie);
//	printf("InitialaTata:%c\n", student.initialaTata);
//	printf("\n");
//}
//
//Student initalizare(int id,int varsta,const char* nume,float medie,char initialaTata) {
//	Student s;
//	s.id = id;
//	s.varsta = varsta;
//	s.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(s.nume, nume);
//	s.medie = medie;
//	s.initialaTata = initialaTata;
//	return s;
//
//}
//
//void dezalocareStudent(Student* s) {
//
//	if (s->nume != NULL) {
//		free(s->nume);
//		s->nume = NULL;
//	}
//	
//}
//
//void afisareVector(Student* s, int nrStudenti) {
//
//	for (int i = 0; i < nrStudenti; i++) {
//		afisareStudent(s[i]);
//	}
//
//}
//
//void dezalocareVector(Student** s, int* nrStudenti) {
//
//	for (int i = 0; i < (*nrStudenti); i++) {
//		if ((*s)[i].nume != NULL) {
//			free((*s)[i].nume);
//		}
//	}
//
//	free(*s);
//	(*s) = NULL;
//	*nrStudenti = 0;
//
//}
//
// Student* copiazaPrimeleNElemente( Student* vector, int nrElemente, int nrElementeCopiate) {
//	
//	Student *vectorNou=NULL;
//	vectorNou = (Student*)malloc(sizeof(Student) * nrElementeCopiate);
//	for (int i = 0; i < nrElementeCopiate; i++) {
//		vectorNou[i].id = vector[i].id;
//		vectorNou[i].varsta = vector[i].varsta;
//		vectorNou[i].nume = (char*)malloc(strlen(vector[i].nume) + 1);
//		strcpy(vectorNou[i].nume, vector[i].nume);
//
//		vectorNou[i].medie = vector[i].medie;
//		vectorNou[i].initialaTata = vector[i].initialaTata;
//	}
//
//
//
//	return vectorNou;
//}
//
//
// void copiazaAnumiteElemente(Student* vector, char nrElemente, float prag,  Student** vectorNou, int* dimensiune) {
//
//	 *dimensiune = 0;
//	 for (int i = 0; i < nrElemente; i++) {
//		 if (vector[i].medie > prag) {
//			 (*dimensiune)++;
//		 }
//	 }
//
//	 if (*vectorNou != NULL) {
//		 free(*vectorNou);
//	 }
//
//	 *vectorNou = (Student*)malloc(sizeof(Student) * (*dimensiune));
//	 int k = 0;
//	 for (int i = 0; i < nrElemente; i++) {
//		
//		 if(vector[i].medie>prag)
//		 {
//			 (*vectorNou)[k] = vector[i];
//			 (*vectorNou)[k].nume = (char*)malloc(strlen(vector[i].nume)+1);
//			 strcpy((*vectorNou)[k].nume, vector[i].nume);
//			 k++;
//		 }
//
//
//	 }
//
//
//}
//
// Student getPrimulElementConditionat(Student* vector, int nrElemente, const char* numeCautat){
//	
//	Student s = {0};
//	for (int i = 0; i < nrElemente; i++) {
//		if (strcmp(vector[i].nume, numeCautat) == 0) {
//			return vector[i];
//		}
//		
//		
//	}
//
//	return s;
//	
//	
//}
//
// int numaraStudentiPesteVarsta(Student* vector, int nrStudenti, int varstaLimita) {
//
//	 int contor = 0;
//	 for (int i = 0; i < nrStudenti; i++) {
//		 if (vector[i].varsta > varstaLimita) {
//			 
//			 contor++;
//		 }
//	 }
//
//	 return contor;
// }
//
// Student* vectorStudentiPesteVarsta(Student* vector, int nrStudenti, int varstaLimita, int* nrGasiti) {
//	
//	 *nrGasiti = 0;
//	 int dimensiune = 0;
//	 for (int i = 0; i < nrStudenti; i++) {
//		 if (vector[i].varsta > varstaLimita) {
//
//				dimensiune++;
//		 }
//	 }
//
//	 *nrGasiti = dimensiune;
//	 Student* vectornou = (Student*)malloc(sizeof(Student) * (*nrGasiti));
//
//
//	 int k = 0;
//	 for (int i = 0; i < nrStudenti; i++) {
//		 if (vector[i].varsta > varstaLimita) {
//			 vectornou[k].id = vector[i].id;
//			 vectornou[k].medie = vector[i].medie;
//			 vectornou[k].initialaTata = vector[i].initialaTata;
//			 vectornou[k].medie = vector[i].medie;
//			 vectornou[k].nume = (char*)malloc(strlen(vector[i].nume) + 1);
//			 strcpy(vectornou[k].nume, vector[i].nume);
//			 vectornou[k].varsta = vector[i].varsta;
//			 k++;
//		 }
//	 }
//
//	 return vectornou;
//
// }
//
//  void adaugaStudentInVector(Student * *student, int* nrStudenti, Student studentNou) {
//	  Student* vectornou = (Student*)malloc(sizeof(Student) * (*nrStudenti+1));
//	  int k = 0;
//	  for (int i = 0; i < (*nrStudenti); i++) {
//		  vectornou[k] = (*student)[i];
//		  vectornou[k].nume = (char*)malloc(strlen((*student)[i].nume) + 1);
//		  strcpy(vectornou[k].nume, (*student)[i].nume);
//		  k++;
//	  }
//		
//	  vectornou[(*nrStudenti)] = studentNou;
//	  vectornou[*nrStudenti].nume = malloc(strlen(studentNou.nume) + 1);
//	  strcpy(vectornou[*nrStudenti].nume, studentNou.nume);
//
//	  (*nrStudenti)++;
//	  *student = vectornou;
//		
//	  
//  }
//
//
//void afisareListaStudentInceput(ListaDubla lista) {
//	
//	
//	Nod* p = lista.first;
//	while (p) {
//		afisareStudent(p->info);
//		p = p->next;
//	}
//
//
//
//}
//
//void afisareListaStudentSfarsit(ListaDubla lista) {
//	Nod* p = lista.last;
//	while (p) {
//		afisareStudent(p->info);
//		p = p->prev;
//	}
//
//
//}
//
//void adaugaStudentInListaFinal(ListaDubla* lista, Student studentNou) {
//	
//
//	Nod* Nou = (Nod*)malloc(sizeof(Nod));
//	Nou->info = studentNou;
//	Nou->next = NULL;
//	Nou->prev = lista->last;
//
//	if(lista->last!=NULL)
//	{
//		lista->last->next = Nou;
//	}
//	else {
//		lista->first = Nou;
//	}
//	lista->last = Nou;
//	lista->nrNoduri++;
//
//
//
//}
//
//void adaugaLaInceputInLista(ListaDubla*lista, Student studentnou) {
//	Nod* Nou = (Nod*)malloc(sizeof(Nod));
//	Nou->info = studentnou;
//	Nou->next = lista->first;
//	Nou->prev = NULL;
//
//	if (lista->first != NULL) {
//		lista->first->prev = Nou;
//	}
//	else {
//		lista->last = Nou;
//		
//	}
//
//	lista->first = Nou;
//	lista->nrNoduri++;
//
//
//}
//
//ListaDubla citireLDStudentDinFisier(const char* numeFisier) {
//	
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	while (!feof(f)) {
//		Student s = citireStudentDinFisier(f);
//		adaugaLaInceputInLista(&lista, s);
//	}
//
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDStudent(ListaDubla* lista) {
//	
//	Nod* p = lista->first;
//	while (p) {
//		Nod* next = p->next;
//		p = p->next;
//		
//		if (p->info.nume != NULL) {
//			free(p->info.nume);
//		}
//		free(p);
//		p = next;
//	}
//
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	//calculeaza nota medie a tuturor studentilor din lista
//	float suma = 0;
//	Nod* p = lista.first;
//	while (p) {
//
//		suma = suma + p->info.medie;
//		
//		p = p->next;
//	}
//	float media = suma / lista.nrNoduri;
//
//	return media;
//}
//
//void stergeStudentDupaID(ListaDubla* lista, int id) {
//	//sterge studentul cu id-ul primit.
//	//tratati situatia ca studentul se afla si pe prima pozitie, si pe ultima pozitie
//	Nod* p = lista->first;
//	while (p&&p->info.id!=id) {
//		
//		p = p->next;
//
//	}
//
//	if (p == NULL) {
//		return;
//	}
//	
//	if (p == lista->first) {
//		lista->first = p->next;
//		if (p->next) {
//			p->next->prev = NULL;
//		}
//		else {
//			lista->last = NULL;
//		}
//	}
//	if(p->next&&p->prev)
//	{
//		p->prev->next = p->next;
//		p->next->prev = p->prev;
//	}
//	
//	if (p->next == NULL) {
//		p->prev->next = NULL;
//	}
//
//
//	if (p->info.nume != NULL) {
//		free(p->info.nume);
//	}
//
//	free(p);
//
//	lista->nrNoduri--;
//}
//
//char* getNumeStudentMedieMare(ListaDubla lista) {
//	//cauta media cea mai mare
//	//returneaza numele studentului
//
//	if(lista.first)
//	{
//		Nod* p = lista.first;
//		Nod* maxim = lista.first->next;
//		while(p)
//		{
//			if (p->info.medie > maxim->info.medie) {
//				maxim = p;
//			}
//			p = p->next;
//		}
//
//		char* nume = (char*)malloc(strlen(maxim->info.nume) + 1);
//		strcpy(nume, maxim->info.nume);
//		return nume;
//	}
//	else {
//		return NULL;
//	}
//	
//
//
//	
//}
//
//int main() {
//
//	
//	/*Student s1 = initalizare(1, 20, "Popescu", 9.5, 'I');
//	Student s2 = initalizare(1, 21, "Ionescu", 8.5, 'V');
//
//	printf("----S1------\n");
//	afisareStudent(s1);
//	printf("----S2------\n");
//	afisareStudent(s2);
//	dezalocareStudent(&s1);
//	dezalocareStudent(&s2);
//
//	printf("----S3 din fisier------\n");
//	FILE* f = fopen("student.txt", "r");
//	Student s3= citireStudentDinFisier(f);
//	afisareStudent(s3);
//	dezalocareStudent(&s3);
//	fclose(f);*/
//
//	int nrStudenti = 4;
//	Student* vector = (Student*)malloc(sizeof(Student)*nrStudenti);
//	vector[0] = initalizare(1, 20, "Popescu", 9.5, 'I');
//	vector[1] = initalizare(2, 21, "Ionescu", 8.5, 'V');
//	vector[2] = initalizare(3, 19, "Vasilescu", 6.5, 'C');
//	vector[3] = initalizare(4, 25, "Popescu", 9.5, 'I');
//	
//	afisareVector(vector, nrStudenti);
//
//	int nrElementeCopiate = 2;
//	Student* primeleElemente = NULL;
//	primeleElemente = copiazaPrimeleNElemente(vector, nrStudenti, nrElementeCopiate);
//	printf("----Vector Copiat----\n");
//	afisareVector(primeleElemente, nrElementeCopiate);
//
//	Student* anumitiStudenti = NULL;
//	int nrAnumitiStudenti = 0; 
//	copiazaAnumiteElemente(vector, nrStudenti, 9.0, &anumitiStudenti, &nrAnumitiStudenti);
//	printf("----Vector Copiat----\n");
//	afisareVector(anumitiStudenti,nrAnumitiStudenti);
//
//	Student rezultat = getPrimulElementConditionat(vector, nrStudenti, "Popescu");
//	afisareStudent(rezultat);
//
//	printf("Numarul de studentii cu varsta peste 21 sunt: %d", numaraStudentiPesteVarsta(vector, nrStudenti, 21));
//	int nrGasiti = 0;
//	printf("Vector studenti peste 20 ani\n");
//	Student* vector2 = vectorStudentiPesteVarsta(vector, nrStudenti, 20, &nrGasiti);
//	afisareVector(vector2, nrGasiti);
//
//
//
//	Student studentNou = initalizare(1, 20, "Izabela", 9.5, 'I');
//
//	adaugaStudentInVector(&vector, &nrStudenti, studentNou);
//
//	afisareVector(vector, nrStudenti);
//	
//	ListaDubla lista = citireLDStudentDinFisier("student.txt");
//	afisareListaStudentSfarsit(lista);
//
//
//	printf("---Sterge din Lista------\n");
//	stergeStudentDupaID(&lista, 10);
//	afisareListaStudentInceput(lista);
//
//	dezalocareVector(&anumitiStudenti, &nrAnumitiStudenti);
//	dezalocareVector(&vector, &nrStudenti);
//	dezalocareVector(&primeleElemente, &nrElementeCopiate);
//	
//	return 0;
//}