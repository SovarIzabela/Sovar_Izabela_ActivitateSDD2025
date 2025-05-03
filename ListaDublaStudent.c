#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Student {
		int id;
		int varsta;
		char* nume;
		float medie;
		char initialaTata;
};
typedef struct Student Student;

struct Nod {
	Student info;
	struct Nod* prev;
	struct Nod* next;

};
typedef struct Nod Nod;

struct ListDubla {
	Nod* first;
	Nod* last;
	int nrNoduri;
};

Student citireStudentDinFisier(FILE* file) {
	Student s = { 0 };
	char buffer[100];
	char* separator = " ,;\n";
	fgets(buffer, 100, file);

	char* token = strtok(buffer, separator);
	if (token==NULL) return s;
	s.id = atoi(token);

	token = strtok(NULL, separator);
	if (token == NULL) return s;
	s.varsta = atoi(token);
	
	token = strtok(NULL, separator);
	if (token == NULL) return s;
	s.nume = (char*)malloc(strlen(token) + 1);
	strcpy(s.nume, token);
	
	token = strtok(NULL, separator);
	if (token == NULL) return s;
	s.medie = atof(token);
	
	token = strtok(NULL, separator);
	if (token == NULL) return s;
	s.initialaTata = (token)[0];
	
	return s;

	
}

void afisareStudent(Student student) {
	
	printf("ID:%d\n", student.id);
	printf("Varsta:%d\n", student.varsta);
	printf("Nume:%s\n", student.nume);
	printf("Medie:%.2f\n", student.medie);
	printf("InitialaTata:%c\n", student.initialaTata);
	printf("\n");
}

Student initalizare(int id,int varsta,const char* nume,float medie,char initialaTata) {
	Student s;
	s.id = id;
	s.varsta = varsta;
	s.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(s.nume, nume);
	s.medie = medie;
	s.initialaTata = initialaTata;
	return s;

}

void dezalocareStudent(Student* s) {

	if (s->nume != NULL) {
		free(s->nume);
		s->nume = NULL;
	}
	
}

void afisareVector(Student* s, int nrStudenti) {

	for (int i = 0; i < nrStudenti; i++) {
		afisareStudent(s[i]);
	}

}

void dezalocareVector(Student** s, int* nrStudenti) {

	for (int i = 0; i < (*nrStudenti); i++) {
		if ((*s)[i].nume != NULL) {
			free((*s)[i].nume);
		}
	}

	free(*s);
	(*s) = NULL;
	*nrStudenti = 0;

}

 Student* copiazaPrimeleNElemente( Student* vector, int nrElemente, int nrElementeCopiate) {
	
	Student *vectorNou=NULL;
	vectorNou = (Student*)malloc(sizeof(Student) * nrElementeCopiate);
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i].id = vector[i].id;
		vectorNou[i].varsta = vector[i].varsta;
		vectorNou[i].nume = (char*)malloc(strlen(vector[i].nume) + 1);
		strcpy(vectorNou[i].nume, vector[i].nume);

		vectorNou[i].medie = vector[i].medie;
		vectorNou[i].initialaTata = vector[i].initialaTata;
	}



	return vectorNou;
}


 void copiazaAnumiteElemente(Student* vector, char nrElemente, float prag,  Student** vectorNou, int* dimensiune) {

	 *dimensiune = 0;
	 for (int i = 0; i < nrElemente; i++) {
		 if (vector[i].medie > prag) {
			 (*dimensiune)++;
		 }
	 }

	 if (*vectorNou != NULL) {
		 free(*vectorNou);
	 }

	 *vectorNou = (Student*)malloc(sizeof(Student) * (*dimensiune));
	 int k = 0;
	 for (int i = 0; i < nrElemente; i++) {
		
		 if(vector[i].medie>prag)
		 {
			 (*vectorNou)[k] = vector[i];
			 (*vectorNou)[k].nume = (char*)malloc(strlen(vector[i].nume)+1);
			 strcpy((*vectorNou)[k].nume, vector[i].nume);
			 k++;
		 }


	 }


}

 Student getPrimulElementConditionat(Student* vector, int nrElemente, const char* numeCautat){
	
	Student s = {0};
	for (int i = 0; i < nrElemente; i++) {
		if (strcmp(vector[i].nume, numeCautat) == 0) {
			return vector[i];
		}
		
		
	}

	return s;
	
	
}


void afisareListaStudent(/*lista dubla de masini*/) {
	//afiseaza toate elemente de tip masina din lista dublu inlantuita
	//prin apelarea functiei afisareMasina()
}

void adaugaStudentInLista(/*lista dubla de masini*/ Student masinaNoua) {
	//adauga la final in lista primita o noua masina pe care o primim ca parametru
}

void adaugaLaInceputInLista(/*lista dubla de masini*/ Student masinaNoua) {
	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru
}

void* citireLDStudentDinFisier(const char* numeFisier) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaDinFisier()
	//ATENTIE - la final inchidem fisierul/stream-ul
}

void dezalocareLDStudent(/*lista dubla de masini*/) {
	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
}

float calculeazaPretMediu(/*lista de masini*/) {
	//calculeaza pretul mediu al masinilor din lista.
	return 0;
}

void stergeStudentDupaID(/*lista masini*/ int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
}

char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	return NULL;
}

int main() {

	
	/*Student s1 = initalizare(1, 20, "Popescu", 9.5, 'I');
	Student s2 = initalizare(1, 21, "Ionescu", 8.5, 'V');

	printf("----S1------\n");
	afisareStudent(s1);
	printf("----S2------\n");
	afisareStudent(s2);
	dezalocareStudent(&s1);
	dezalocareStudent(&s2);

	printf("----S3 din fisier------\n");
	FILE* f = fopen("student.txt", "r");
	Student s3= citireStudentDinFisier(f);
	afisareStudent(s3);
	dezalocareStudent(&s3);
	fclose(f);*/

	int nrStudenti = 4;
	Student* vector = (Student*)malloc(sizeof(Student)*nrStudenti);
	vector[0] = initalizare(1, 20, "Popescu", 9.5, 'I');
	vector[1] = initalizare(2, 21, "Ionescu", 8.5, 'V');
	vector[2] = initalizare(3, 19, "Vasilescu", 6.5, 'C');
	vector[3] = initalizare(4, 25, "Popescu", 9.5, 'I');
	
	afisareVector(vector, nrStudenti);

	int nrElementeCopiate = 2;
	Student* primeleElemente = NULL;
	primeleElemente = copiazaPrimeleNElemente(vector, nrStudenti, nrElementeCopiate);
	printf("----Vector Copiat----\n");
	afisareVector(primeleElemente, nrElementeCopiate);

	Student* anumitiStudenti = NULL;
	int nrAnumitiStudenti = 0; 
	copiazaAnumiteElemente(vector, nrStudenti, 9.0, &anumitiStudenti, &nrAnumitiStudenti);
	printf("----Vector Copiat----\n");
	afisareVector(anumitiStudenti,nrAnumitiStudenti);

	Student rezultat = getPrimulElementConditionat(vector, nrStudenti, "Popescu");
	afisareStudent(rezultat);

	dezalocareVector(&anumitiStudenti, &nrAnumitiStudenti);
	dezalocareVector(&vector, &nrStudenti);
	dezalocareVector(&primeleElemente, &nrElementeCopiate);
	
	return 0;
}