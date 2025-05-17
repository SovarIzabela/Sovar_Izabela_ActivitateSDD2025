
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

Heap initializareHeap(int lungime) {
	
	Heap heap;
	heap.lungime = lungime;
	heap.nrMasini = 0;

	heap.vector = (Masina*)malloc(sizeof(Masina) * lungime);
	return heap;



}

void filtreazaHeap(Heap heap, int pozitieNod) {
	
	int fiuStanga = 2 * pozitieNod + 1;
	int fiuDreapta = 2 * pozitieNod + 2;
	int pozMaxim = pozitieNod;

	if (fiuStanga < heap.nrMasini&&heap.vector[pozMaxim].id < heap.vector[fiuStanga].id) {
		pozMaxim = fiuStanga;
	}

	if (fiuDreapta<heap.nrMasini&&heap.vector[pozMaxim].id < heap.vector[fiuDreapta].id) {
		pozMaxim = fiuDreapta;
	}

	if (pozMaxim != pozitieNod) {
		Masina aux = heap.vector[pozMaxim];
		heap.vector[pozMaxim] = heap.vector[pozitieNod];
		heap.vector[pozitieNod] = aux;
		//2 * pozMaxim - 1 <= heap.nrMasini - 1;
		if (pozMaxim <=( heap.nrMasini - 2) / 2) {
			filtreazaHeap(heap, pozMaxim);
		}

	}


}

Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {

	FILE* f = fopen(numeFisier, "r");
	Heap h = initializareHeap(10);

	while (!feof(f)) {
		h.vector[h.nrMasini++] = citireMasinaDinFisier(f);
	}
	fclose(f);

	for (int i = ((h.nrMasini - 2) / 2); i >= 0; i--) {
		filtreazaHeap(h, i);
	}

	return h;
}

void afisareHeapVizibil(Heap h) {
	
	for (int i = 0; i < h.nrMasini; i++) {
		afisareMasina(h.vector[i]);
	}

}

void afiseazaHeapAscuns(Heap heap) {
	
	for (int i = heap.nrMasini; i < heap.lungime; i++) {
		afisareMasina(heap.vector[i]);
	}


}

Masina extrageMasina(Heap* heap) {

	if (heap->nrMasini > 0) {

		Masina aux = heap->vector[0];
		heap->vector[0] = heap->vector[heap->nrMasini - 1];
		heap->vector[heap->nrMasini - 1] = aux;
		heap->nrMasini--;

		for (int i = ((heap->nrMasini - 2) / 2); i >= 0; i--) {
			filtreazaHeap(*heap, i);
		}

		return aux;

	}



}

void dezalocareHeap(Heap* heap) {
	
	for (int i = 0; i < heap->lungime; i++) {

		free(heap->vector[i].model);
		free(heap->vector[i].numeSofer);

	}
	free(heap->vector);
	heap->vector = NULL;
	heap->lungime = 0;
	heap->nrMasini = 0;



}

int main() {



	Heap heap = citireHeapDeMasiniDinFisier("masini.txt");
	afisareHeapVizibil(heap);

	printf("----Masini extrase----\n");
	afisareMasina(extrageMasina(&heap));

	printf("----Masini ascunse----\n");
	afiseazaHeapAscuns(heap);

	dezalocareHeap(&heap);
	return 0;
}
