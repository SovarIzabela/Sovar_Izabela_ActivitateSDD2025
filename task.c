#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct SistemIluminat {
	int id;
	char* tipSistem;
	int nrBecuri;
	float* puteriBecuri;
	char* locatieSistem;

};
typedef struct SistemIluminat SistemIluminat;

SistemIluminat citireSistemIluminatTastatura() {

	SistemIluminat si;
	//id
	printf("Introduceti id-ul:");
	scanf("%d", &si.id);
	getchar();
	//char* tipSistem;
	char buffer[100];
	printf("Introduceti tipul sistemului :");
	fgets(buffer, 100, stdin);
	buffer[strcspn(buffer, "\n")] = "\0";
	si.tipSistem = (char*)malloc(strlen(buffer) + 1);
	strcpy(si.tipSistem, buffer);
	/*int nrBecuri;*/
	printf("Introduceti nrBecuri:");
	scanf("%d", &si.nrBecuri);
	getchar();
	/*float* puteriBecuri;*/

	si.puteriBecuri = (float*)malloc(sizeof(float)*si.nrBecuri);
	for (int i = 0; i < si.nrBecuri; i++) {
		printf("Introduceti puterea becului: %d\n", i + 1);
		scanf("%f", &si.puteriBecuri[i]);
	}
	getchar();
	/*char* locatieSistem;*/
	printf("Introduceti tipul sistemului :");
	fgets(buffer, 100, stdin);
	buffer[strcspn(buffer, "\n")] = "0";
	si.locatieSistem = (char*)malloc(sizeof(strlen(buffer) + 1));
	strcpy(si.locatieSistem, buffer);

	return si;
	
}
 SistemIluminat initializare(int id,const char* tipSistem,int nrBecuri,float* puteriBecuri,const char* locatieSistem) {
	 SistemIluminat s;
	 s.id = id;
	 s.tipSistem = (char*)malloc(strlen(tipSistem) + 1);
	 strcpy(s.tipSistem, tipSistem);
	 s.nrBecuri = nrBecuri;

	 s.puteriBecuri = (float*)malloc(sizeof(float) * nrBecuri);
	 for (int i = 0; i < s.nrBecuri; i++) {
		 s.puteriBecuri[i] = puteriBecuri[i];
	 }

	 s.locatieSistem = (char*)malloc(strlen(locatieSistem) + 1);
	 strcpy(s.locatieSistem, locatieSistem);

	return s;
}

 void afisare(SistemIluminat s) {
	
	 printf("--------Sistem Iluminat---------\n");
	 printf("Id:%d\n ", s.id);
	 printf("TipSistem :%s\n ", s.tipSistem);
	 printf("NrBecuri:%d\n ", s.nrBecuri);
	 printf("Puterea becurilor sunt :\n" );
	 for (int i = 0; i < s.nrBecuri; i++) {
		 printf("%.2f\n", s.puteriBecuri[i]);
	 }
	 printf("Locatie Sistem:%s\n ", s.locatieSistem);


 }

void modifica_LocatieSistem( SistemIluminat* s, const char* locatieNoua) {
	
	if ((*s).locatieSistem != NULL) {

		free((*s).locatieSistem);
	}
	s->locatieSistem = (char*)malloc(strlen(locatieNoua)+1);
	strcpy( s->locatieSistem, locatieNoua);
}

void modifica_puteriBecuri(SistemIluminat* s, float* puteriNoi, int nrNou) {

	if (s->puteriBecuri != NULL) {
		free(s->puteriBecuri);
	}

	s->puteriBecuri = (float*)malloc(sizeof(float) * nrNou);
	for (int i = 0; i < nrNou; i++) {
		s->puteriBecuri[i] = puteriNoi[i];
	}
	s->nrBecuri = nrNou;
}

void afisareVector(SistemIluminat* vector, int nrElemente) {
	
	
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);
		
	}
	
}

void adaugaSistemIluminatInVector(SistemIluminat** vector, int* nrElemente, SistemIluminat sistemNou) {

	SistemIluminat* vectornou = (SistemIluminat*)malloc(sizeof(SistemIluminat) * (*nrElemente)+1);

	for (int i = 0; i < (*nrElemente); i++) {
		vectornou[i] = *vector[i];
	}



	vectornou[(*nrElemente)] = sistemNou;

	free(*vector);
	(*vector) = vectornou;
	(*nrElemente)++;

}

 SistemIluminat* copiazaPrimeleNElemente(struct SistemIluminat* vector, int nrElemente, int nrElementeCopiate) {
	//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	 SistemIluminat*vectorNou=NULL;

	return vectorNou;
}

void dezalocareVector(struct SistemIluminat** vector, int* nrElemente) {
	
	
	for (int i = 0; i < (*nrElemente); i++) {
		if ((*vector)[i].locatieSistem != NULL) {
			free((*vector)[i].locatieSistem);
			(*vector)[i].locatieSistem = NULL;
		}
		if ((*vector)[i].puteriBecuri != NULL) {
			free((*vector)[i].puteriBecuri);
			(*vector)[i].puteriBecuri = NULL;
		}
		if ((*vector)[i].tipSistem != NULL) {
			free((*vector)[i].tipSistem);
			(*vector)[i].tipSistem = NULL;
		}

	}

	free(*vector);
	(*vector) = NULL;
	*nrElemente = 0;
}

void copiazaAnumiteElemente(SistemIluminat* vector, char nrElemente, int pragNrbecuri,  SistemIluminat** vectorNou, int* dimensiune) {
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie

	*dimensiune = 0;
	for (int i = 0; i < nrElemente; i++) {

		if (vector[i].nrBecuri >= pragNrbecuri) {
			(*dimensiune)++;
		}
	}


	*vectorNou = (SistemIluminat*)malloc(sizeof(SistemIluminat) * (*dimensiune));

	int k = 0;
		for (int i = 0; i < nrElemente; i++) {
			if (vector[i].nrBecuri >= pragNrbecuri) {
				(*vectorNou)[k] = vector[i];
				(*vectorNou)[k].tipSistem = (char*)malloc(strlen(vector[i].tipSistem)+1);
				strcpy((*vectorNou)[k].tipSistem, vector[i].tipSistem);
				(*vectorNou)[k].puteriBecuri = (float*)malloc(sizeof(vector[i].puteriBecuri) * (vector[i].nrBecuri));
				for (int i = 0; i < (vector[i].nrBecuri); i++) {
					(*vectorNou)[k].puteriBecuri = vector[i].puteriBecuri;
				}


				(*vectorNou)[k].locatieSistem =(char*)malloc(strlen( vector[i].locatieSistem)+1);
				strcpy((*vectorNou)[k].locatieSistem, vector[i].locatieSistem);

				k++;
			}



	}





}

 SistemIluminat getPrimulElementConditionat(struct SistemIluminat* vector, int nrElemente, const char* conditie) {
	//trebuie cautat elementul care indeplineste o conditie
	//dupa atributul de tip char*. Acesta este returnat.
	
}



void dezalocare( SistemIluminat*s) {
	
	if (s->locatieSistem != NULL) {
		free(s->locatieSistem);
		s->locatieSistem = NULL;
	}
	if (s->puteriBecuri != NULL) {
		free(s->puteriBecuri);
		s->puteriBecuri = NULL;
	}
	if (s->tipSistem != NULL) {
		free(s->tipSistem);
		s->tipSistem = NULL;
	}
	


}


SistemIluminat citireSistemIluminatFisier(FILE* file) {
	SistemIluminat s;

	char buffer[100];
	char* delimitator = " ';\n";
	fgets(buffer, 100, file);

	char* token = strtok(buffer, delimitator);
	if (token == NULL) return s;
	s.id = atoi(token);

	token = strtok(NULL, delimitator);
	if (token == NULL) return s;
	s.tipSistem = (char*)malloc(strlen(token) + 1);
	strcpy(s.tipSistem, token);

	token = strtok(NULL, delimitator);
	if (token == NULL) return s;
	s.nrBecuri = atoi(token);

	
	s.puteriBecuri = (float*)malloc(sizeof(float) * s.nrBecuri);
	for (int i = 0; i < s.nrBecuri; i++) {
		token = strtok(NULL, delimitator);
		if (token == NULL) return s;
		s.puteriBecuri[i] =(float) atof(token[i]);
	}

	token = strtok(NULL, delimitator);
	if (token == NULL) return s;
	s.locatieSistem = (char*)malloc(strlen(token) + 1);
	strcpy(s.locatieSistem, token);


	return s;

}



int main() {

	/*SistemIluminat s1 = citireSistemIluminatTastatura();*/
	float becuri[] = { 25.5,75.2,85.3 };
	SistemIluminat s2 = initializare(101, "LED", 3, becuri, "Bucatarie");
	afisare(s2);
	modifica_LocatieSistem(&s2, "baie");
	afisare(s2);

	float puteri[] = { 25.2,35.8 };
	modifica_puteriBecuri(&s2, puteri, 2);
	afisare(s2);

	int nrElem = 4;
	SistemIluminat* vector = (SistemIluminat*)malloc(sizeof(SistemIluminat) * nrElem);
	vector[0] = initializare(102, "LED", 3, becuri, "pivnita");
	vector[1] = initializare(103, "LED", 3, becuri, "dormitor");
	vector[2] = initializare(104, "LED", 3, becuri, "poarta");
	vector[3] = initializare(105, "LED", 3, becuri, "living");
	afisareVector(vector, nrElem);
	int dim = 0;
	SistemIluminat* anumiteElemente = NULL;
	copiazaAnumiteElemente(vector, nrElem, 3, &anumiteElemente,&dim);
	printf("-------------Anumite Elemente----------\n");
	afisareVector(anumiteElemente,dim);

	dezalocare(&s2);
	return 0;

}