//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//
//struct Heap {
//	int lungime;
//	int nrElemente;
//	Masina* vector;
//};
//typedef struct Heap Heap;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	Masina m = { 0 };
//	
//		char buffer[100];
//		char* delimitator = " ,;\n";
//		fgets(buffer, 100, file);
//	
//		char* token = strtok(buffer, delimitator);
//		m.id = atoi(token);
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return m;
//		m.nrUsi = atoi(token);
//	
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return m;
//		m.pret = atof(token);
//		
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return m;
//		m.model = (char*)malloc(strlen(token)+1);
//		strcpy(m.model, token);
//	
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return m;
//		m.numeSofer = (char*)malloc(strlen(token)+1);
//		strcpy(m.numeSofer, token);
//	
//		
//		token = strtok(NULL, delimitator);
//		if (token == NULL) return m;
//		m.serie = token[0];
//		
//		return m;
//
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//Masina initializareMasina(int id,int nrUsi,float pret,char* model,char* numeSofer, unsigned char serie) {
//	Masina m;
//
//	m.id = id;
//	m.nrUsi = nrUsi;
//	m.pret = pret;
//	m.model = _strdup(model);
//	m.numeSofer = _strdup(numeSofer);
//	m.serie = serie;
//
//
//	return m;
//
//}
//
//Heap initializareHeap(int lungime) {
//	
//	Heap h;
//	h.lungime = lungime;
//	h.nrElemente = 0;
//	h.vector = (Masina*)malloc(sizeof(Masina) * lungime);
//
//	return h;
//
//
//}
//
//
//
//void filtreazaHeap(Heap heap, int pozitieNod) {
//	int pozFiuStanga = 2 * pozitieNod + 1;
//	int pozFiuDreapta = 2 * pozitieNod + 2;
//	int maxim = pozitieNod;
//
//	if (pozFiuStanga < heap.nrElemente && heap.vector[maxim].id < heap.vector[pozFiuStanga].id)
//	{
//		maxim = pozFiuStanga;
//	}
//
//	if (pozFiuDreapta < heap.nrElemente && heap.vector[maxim].id < heap.vector[pozFiuStanga].id) {
//		maxim = pozFiuDreapta;
//	}
//
//	if(maxim!= pozitieNod){
//
//		Masina aux = heap.vector[maxim];
//
//		heap.vector[maxim] = heap.vector[pozitieNod];
//
//		heap.vector[pozitieNod] = aux;
//		if (maxim <= (heap.nrElemente - 2) / 2) {
//			filtreazaHeap(heap, maxim);
//		}
//
//	}
//	
//	
//}
//void adaugaInHeap(Heap* h, Masina m) {
//
//	if (h->nrElemente < h->lungime) {
//		h->vector[h->nrElemente++] = m;
//	}
//	else {
//		printf("Nu mai poti adauga in heap");
//	}
//
//
//	for (int i = (h->nrElemente - 2) / 2; i >= 0; i--) {
//		filtreazaHeap(*h, i);
//	}
//
//}
//Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {
//	
//	Heap h = initializareHeap(10);
//	FILE* f = fopen(numeFisier, "r");
//	while (!feof(f)) {
//		Masina m = citireMasinaDinFisier(f);
//		h.vector[h.nrElemente++] = m;
//	}
//
//	fclose(f);
//	for (int i = (h.nrElemente - 2) / 2; i >= 0; i--) {
//		filtreazaHeap(h, i);
//	}
//
//	return h;
//
//}
//
//void afisareHeap(Heap heap) {
//	
//	for (int i = 0; i < heap.nrElemente; i++) {
//		afisareMasina(heap.vector[i]);
//	}
//
//}
//
//void afiseazaHeapAscuns(Heap heap) {
//	
//	for (int i = heap.nrElemente; i < heap.lungime; i++) {
//		afisareMasina(heap.vector[i]);
//	}
//}
//
//Masina extrageMasina(Heap* heap) {
//	
//	if (heap->nrElemente > 0) {
//
//		Masina aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->nrElemente - 1];
//		heap->vector[heap->nrElemente - 1] = aux;
//		heap->nrElemente--;
//
//		for (int i = (h.nrElemente - 2) / 2; i >= 0; i--) {
//		filtreazaHeap(*h, i);
//	}
//		return aux;
//	}
//
//
//}
//
//
//void dezalocareHeap(Heap* heap) {
//	
//	for (int i = 0; i < heap->lungime; i++) {
//		free(heap->vector[i].model);
//		free(heap->vector[i].numeSofer);
//
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->nrElemente = 0;
//	heap->lungime = 0;
//
//
//}
//
//int main() {
//
//	Heap h1 = initializareHeap(10);
//	Masina m1 = initializareMasina(10, 5, 40000.0, "Toyota Corolla", "Popescu Andrei", 'A');
//	Masina m2 = initializareMasina(7, 3, 32000.5, "Volkswagen Golf", "Ionescu Maria", 'B');
//	Masina m3 = initializareMasina(5, 4, 29000.0, "BMW X3", "Vasilescu Mihai", 'C');
//	Masina m4 = initializareMasina(8, 5, 35000.0, "Audi A4", "Marin Ioana", 'D');
//	Masina m5 = initializareMasina(3, 2, 18000.0, "Fiat 500", "Georgescu Elena", 'E');
//	Masina m6 = initializareMasina(6, 4, 27000.0, "Renault Megane", "Dumitru Radu", 'F');
//	Masina m7 = initializareMasina(4, 5, 30000.0, "Skoda Octavia", "Tudor Anca", 'G');
//	Masina m8 = initializareMasina(9, 3, 33000.0, "Mercedes A-Class", "Iliescu Stefan", 'H');
//	Masina m9 = initializareMasina(2, 5, 25000.0, "Kia Ceed", "Barbu Cristina", 'I');
//	Masina m10 = initializareMasina(1, 4, 21000.0, "Dacia Duster", "Zamfir Alexandru", 'J');
//
//	adaugaInHeap(&h1, m1);
//	adaugaInHeap(&h1, m2);
//	adaugaInHeap(&h1, m3);
//	adaugaInHeap(&h1, m4);
//	adaugaInHeap(&h1, m5);
//	adaugaInHeap(&h1, m6);
//	adaugaInHeap(&h1, m7);
//	adaugaInHeap(&h1, m8);
//	adaugaInHeap(&h1, m9);
//	adaugaInHeap(&h1, m10);
//
//	afisareHeap(h1);
//
//	Heap h2 = citireHeapDeMasiniDinFisier("masini_heap.txt");
//	printf("---h2---------\n");
//	afisareHeap(h2);
//
//	dezalocareHeap(&h1);
//	dezalocareHeap(&h2);
//
//	return 0;
//}