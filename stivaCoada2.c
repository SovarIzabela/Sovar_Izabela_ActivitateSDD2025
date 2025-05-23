#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Nod {
	Masina info;
	struct Nod* next;


};
typedef struct Nod Nod;
Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}


void pushSTIVA(Nod**top, Masina masina) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masina;
	nou->next = *top;
	*top = nou;

}

Masina popStack(Nod**top) {
	Masina m;
	if (*top) {
		Nod* aux = *top;
		m = aux->info;
		*top = aux->next;
		free(aux);
	}

	return m;
}

int emptyStack(Nod*top) {
	return top == NULL;
}

Nod* citireStackMasiniDinFisier(const char* numeFisier) {

	Nod* top = NULL;
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		pushSTIVA(&top, m);
	}
	fclose(f);
	return top;

}

void dezalocareStivaDeMasini(Nod**top) {
	while (!emptyStack(*top)) {
		Masina m = popStack(top);
		free(m.model);
		free(m.numeSofer);
	}
}

int size(Nod* top) {
	
	int suma = 0;
	while (top != NULL) {
		
		suma++;
		top = top->next;
		
	}
	return suma;

}


void enqueue(Nod**prim, Nod**ultim, Masina masina) {
	
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masina;
	nou->next = NULL;
	if (*ultim == NULL) {
		*prim = *ultim = nou;
	}
	else {
		(*ultim)->next = nou;
		*ultim = nou;
	}




}

Masina dequeue(Nod**prim) {
	
	Masina m= { 0, 0, 0.0, NULL, NULL, 0 };
	if (*prim) {
		Nod* aux = *prim;
		m = aux->info;
		*prim = aux->next;
		free(aux);
	}

	return m;
}

void* citireCoadaDeMasiniDinFisier(const char* numeFisier, Nod**prim, Nod**ultim) {
	
	Nod* top = NULL;
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		enqueue(prim, ultim, m);
	}
	fclose(f);
	return top;


}

void dezalocareCoadaDeMasini(Nod**prim) {
	while (*prim) {
		Masina m = dequeue(*prim);
		if (m.model) free(m.model);
		if (m.numeSofer) free(m.numeSofer);

	}
	*prim = NULL;
}

void afisareStiva(Nod* top) {
	printf("------Stiva LIFO------ \n");
	while (top) {
		afisareMasina(top->info);
		top = top->next;
	}


}
void afisareCoada(Nod* prim) {
	printf("------Coada FIFO------ \n");
	while (prim) {
		afisareMasina(prim->info);
		prim = prim->next;
	}
}


Masina getMasinaByID(Nod* lista, int id) {
	Masina m = {0,0,0, NULL,NULL,0};
	while (lista) {
		if (id == lista->info.id) {
			return lista->info;
			lista = lista->next;
		}
	}

	return m;
}

float calculeazaPretTotal(Nod* lista) {
	float pret = 0;
	while (lista) {
		pret = pret + lista->info.pret;
		lista = lista->next;
	}
	return pret;

}

int main() {
	Masina m1 = { 1, 4, 23000.5, _strdup("Dacia"), _strdup("IonPopescu"), 'A' };
	Masina m2 = { 2, 5, 26000.0, _strdup("BMW"), _strdup("MariaIonescu"), 'B' };
	Masina m3 = { 3, 5, 26000.0, _strdup("KIA"), _strdup("MariaIonescu"), 'C' };
	Nod* stiva = NULL;
	pushSTIVA(&stiva, m1);
	pushSTIVA(&stiva, m2);
	pushSTIVA(&stiva, m3);
	afisareStiva(stiva);
	popStack(&stiva);
	printf("--------");
	afisareStiva(stiva);



	Nod* prim = NULL;
	Nod* ultim = NULL;
	enqueue(&prim, &ultim, m1);
	enqueue(&prim, &ultim, m2);
	enqueue(&prim, &ultim, m3);
	afisareCoada(prim);
	dequeue(&prim);
	printf("--------");
	afisareCoada(prim);

	//dezalocareCoadaDeMasini(&prim);
	ultim = NULL;
	dezalocareStivaDeMasini(&stiva);


	return 0;
}