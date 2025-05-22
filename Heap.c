//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//
//	Masina* vector;
//	int nrmasini;
//	int lungime;
//
//};
//typedef struct Heap Heap;
//
//void afisareMasina(Masina m) {
//
//	printf("ID: %d\n", m.id);
//	printf("NrUsi: %d\n", m.nrUsi);
//	printf("Pret: %.2f\n", m.pret);
//	printf("Model: %s\n", m.model);
//	printf("NumeSofer: %s\n", m.numeSofer);
//	printf("Serie: %c\n\n", m.serie);
//}
//
//Heap initializareHeap( int lungime) {
//	Heap h;
//	h.lungime = lungime;
//	h.nrmasini = 0;
//	h.vector = (Masina*)malloc(sizeof(Masina) * lungime);
//	return h;
//}
//
//
//
//Masina citireMasinaDinFisier(FILE* f) {
//
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, f);
//	//char* token;
//	Masina m;
//	char* token = strtok(buffer, sep);
//	m.id = atoi(token);
//
//	token = strtok(NULL, sep);
//	m.nrUsi = atoi(token);
//	token = strtok(NULL, sep);
//	m.pret = atof(token);
//
//	token = strtok(NULL, sep);
//	m.model = malloc(strlen(token) + 1);
//	strcpy(m.model,token);
//
//	token = strtok(NULL, sep);
//	m.numeSofer =malloc(strlen(token) + 1);
//	strcpy(m.numeSofer, token);
//
//	token = strtok(NULL, sep);
//	m.serie = *(token);
//
//	return m;
//
//
//
//
//}
//
//void filtrareHeap(Heap h, int pozitieNod) {
//
//	int fiustanga = 2 * pozitieNod + 1;
//	int fiudreapta = 2 * pozitieNod + 2;
//	int maxim = pozitieNod;
//
//	if (fiustanga < h.nrmasini && h.vector[maxim].id < h.vector[fiustanga].id) {
//		maxim = fiustanga;
//	}
//	if (fiudreapta < h.nrmasini && h.vector[maxim].id < h.vector[fiudreapta].id) {
//		maxim = fiudreapta;
//	}
//
//
//	if (maxim != pozitieNod) {
//
//		Masina aux = h.vector[maxim];
//		h.vector[maxim] = h.vector[pozitieNod];
//		h.vector[pozitieNod] = aux;
//
//		if (maxim <= (h.nrmasini - 2) / 2) {
//
//			filtrareHeap(h, maxim);
//		}
//
//
//
//	}
//
//}
//
//
//
//Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {
//
//	Heap h1 = initializareHeap(10);
//	FILE* f = fopen(numeFisier, "r");
//
//	
//
//	while (!feof(f)) {
//		Masina m = citireMasinaDinFisier(f);
//		h1.vector[h1.nrmasini++] = m;
//
//	}
//	fclose(f);
//	for (int i = ((h1.nrmasini - 2) / 2); i >=0; i--) {
//		filtrareHeap(h1, i);
//	}
//	return h1;
// }
//
//
//void afisareHeap(Heap h) {
//
//	for (int i = 0; i < h.nrmasini; i++) {
//		afisareMasina(h.vector[i]);
//	}
//}
//
//
//void afisareheapAscuns(Heap h) {
//
//	for (int i = h.nrmasini; i < h.lungime; i++) {
//		afisareMasina(h.vector[i]);
//	}
//
//
//}
//
//
//Masina extrageMasina(Heap* h) {
//
//	if (h->nrmasini > 0) {
//		Masina aux = h->vector[0];
//		h->vector[0] = h->vector[h->nrmasini - 1];
//		h->vector[h->nrmasini - 1] = aux;
//		h->nrmasini--;
//
//		for (int i = (h->nrmasini - 2) / 2; i >= 0; i--) {
//			filtrareHeap(*h, i);
//		}
//		return aux;
//
//
//	}
//	
//
//}
//
//
//void dezalocareHeap(Heap* h) {
//
//	for (int i = 0; i < h->lungime; i++) {
//		free(h->vector[i].model);
//		free(h->vector[i].numeSofer);
//		
//	}
//	free(h->vector);
//	h->lungime = 0;
//	h->nrmasini = 0;
//	h->vector = NULL;
//}
//
//void adaugaMasinaHeap(Heap* h, Masina m) {
//
//	if (h->nrmasini < h->lungime) {
//		h->vector[h->nrmasini++] = m;
//
//	}
//	else {
//		return"heap plin";
//	}
//
//	for (int i = (h->nrmasini - 2) / 2; i >= 0; i--) {
//		filtrareHeap(*h, i);
//	}
//
//
//}
//
//
//
//int main() {
//
//	Heap h = initializareHeap(15);
//	Masina m1 = { 17,5,20000.5,_strdup("dacia"),_strdup("valy"), 'd' };
//	adaugaMasinaHeap(&h, m1);
//	Heap h1 = citireHeapDeMasiniDinFisier("masini_heap.txt");
//	afisareHeap(h);
//	
//	
//
//
//	afisareHeap(h1);
//	afisareMasina(extrageMasina(&h1));
//
//	afisareheapAscuns(h1);
//	
//	free(m1.model);
//	free(m1.numeSofer);
//	dezalocareHeap(&h1);
//	return 0;
//}
