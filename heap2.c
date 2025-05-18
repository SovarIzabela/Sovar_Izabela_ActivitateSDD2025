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


struct Heap {

	Masina* vector;
	int lungime;
	int nrMasini;
};
typedef struct Heap Heap;

Masina citireMasinaDinFisier(FILE* file) {

	Masina m = {0};

	char buffer[100];
	char* delimitator = " ,;\n";
	fgets(buffer, 100, file);

	char* token = strtok(buffer, delimitator);
	m.id = atoi(token);
	token = strtok(NULL, delimitator);
	if (token == NULL) return m;
	m.nrUsi = atoi(token);

	token = strtok(NULL, delimitator);
	if (token == NULL) return m;
	m.pret = atof(token);
	
	token = strtok(NULL, delimitator);
	if (token == NULL) return m;
	m.model = (char*)malloc(strlen(token)+1);
	strcpy(m.model, token);

	token = strtok(NULL, delimitator);
	if (token == NULL) return m;
	m.numeSofer = (char*)malloc(strlen(token)+1);
	strcpy(m.numeSofer, token);

	
	token = strtok(NULL, delimitator);
	if (token == NULL) return m;
	m.serie = token[0];
	
	return m;
	
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

Masina initializareMasina(int id, int nrUsi, float pret,const char* model,const char* numeSofer,unsigned char serie) {

	Masina m;
	m.id = id;
	m.nrUsi = nrUsi;
	m.pret = pret;
	m.model = _strdup(model);
	m.numeSofer = _strdup(numeSofer);
	m.serie = serie;

	return m;


}

Heap initializareHeap(int lungime) {

	Heap h;
	h.lungime = lungime;
	h.nrMasini = 0;
	h.vector = (Masina*)malloc(sizeof(Masina) * lungime);

	return h;

}

void adaugaHeap(Heap* h, Masina m) {

	if (h->nrMasini < h->lungime) {
		h->vector[h->nrMasini++] = m;
	}
	else {
		printf("Heap plin");
	}

}

void filtreazaHeap(Heap heap, int pozitie) {
	
	int fiuStanga = 2 * pozitie +1;
	int fiuDreapta = 2 * pozitie + 2; 

	int pozitieMaxim = pozitie;

	if (fiuStanga < heap.nrMasini && heap.vector[pozitieMaxim].id < heap.vector[fiuStanga].id) {

		pozitieMaxim = fiuStanga;
	}
	if (fiuDreapta < heap.nrMasini && heap.vector[pozitieMaxim].id < heap.vector[fiuDreapta].id) {

		pozitieMaxim = fiuDreapta;
	}

	if (pozitieMaxim != pozitie) {

		Masina aux = heap.vector[pozitieMaxim];
		heap.vector[pozitieMaxim] = heap.vector[pozitie];
		heap.vector[pozitie] = aux;
		
		if (pozitieMaxim <= (heap.nrMasini - 2) / 2) {
			filtreazaHeap(heap, pozitieMaxim);
		}

	}


}

Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {
	
	Heap h = initializareHeap(10);

	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		h.vector[h.nrMasini++] = m;

	}

	fclose(f);

	for (int i = (h.nrMasini - 2) / 2; i >= 0; i--) {
		filtreazaHeap(h, i);
	}

	return h;
}

void afisareHeap(Heap heap) {
	

	for (int i = 0; i < heap.nrMasini; i++) {
		afisareMasina(heap.vector[i]);
	}
}

void afiseazaHeapAscuns(Heap heap) {
	for (int i = heap.nrMasini; i < heap.lungime; i++) {
		afisareMasina(heap.vector[i]);
	}
}

Masina extrageMasina(Heap* h) {

	if (h->nrMasini > 0) {
		Masina aux = h->vector[0];
		h->vector[0] = h->vector[h->nrMasini - 1];
		h->vector[h->nrMasini - 1] = aux;
		h->nrMasini--;



		for (int i = (h->nrMasini - 2) / 2; i >= 0; i--) {
			filtreazaHeap(*h, i);
		}

		return aux;
	}
}


void dezalocareHeap(Heap* heap) {
	
	for (int i = 0; i < heap->nrMasini; i++) {
		free(heap->vector[i].model);
		free(heap->vector[i].numeSofer);
	}

	free(heap->vector);
	heap->vector = NULL;
	heap->lungime = 0;
	heap->nrMasini = 0;
	
}

int main() {

	Heap h = initializareHeap(10);

	Masina m1 = initializareMasina(1, 4, 2000, "dacia", "ion", "d");
	Masina m2 = initializareMasina(2, 4, 2000, "mercedes", "david", "a");
	Masina m3 = initializareMasina(3, 4, 2000, "ford", "valy", "b");
	Masina m4 = initializareMasina(4, 4, 2000, "tesla", "Jon", "a");


	adaugaHeap(&h, m1);
	adaugaHeap(&h, m2);
	adaugaHeap(&h, m3);
	adaugaHeap(&h, m4);

	for (int i = (h.nrMasini - 2) / 2; i >= 0; i--) {
		filtreazaHeap(h, i);
	}


	Heap h2 = citireHeapDeMasiniDinFisier("masini_heap.txt");
	afisareHeap(h2);

	printf("masina extrasa\n");
	afisareMasina(extrageMasina(&h2));

	afiseazaHeapAscuns(h2);


	dezalocareHeap(&h);
	dezalocareHeap(&h2);
	return 0;
}