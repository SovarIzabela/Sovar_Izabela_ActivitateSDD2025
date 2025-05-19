//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
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
//
//struct Heap {
//	int lungime;
//	int nrMasini;
//	Masina* vector;
//};
//typedef struct Heap Heap;
//
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//
//	char buffer[100];
//	char* delimitator = " ,;\n";
//	fgets(buffer, 100, file);
//	Masina m; 
//
//	char* token = strtok(buffer, delimitator);
//	if (token == NULL) return m;
//	m.id = atoi(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return m;
//	m.nrUsi = atoi(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return m;
//	m.pret = atof(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return m;
//	m.model = _strdup(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return m;
//	m.numeSofer = _strdup(token);
//
//	token = strtok(NULL, delimitator);
//	if (token == NULL) return m;
//	m.serie = token[0];
//
//	return m;
//
//}
//
//void afisareMasina(Masina m) {
//	
//
//	printf("ID: %d\n", m.id);
//	printf("NrUsi: %d\n", m.nrUsi);
//	printf("Pret: %.2f\n", m.pret);
//	printf("Model: %s\n", m.model);
//	printf("NumeSofer: %s\n", m.numeSofer);
//	printf("Serie: %c\n\n", m.serie);
//
//}
//
//
//Heap initializareHeap( int lungime) {
//
//	Heap h;
//	h.lungime = lungime;
//	h.nrMasini = 0;
//	h.vector = (Masina*)malloc(sizeof(Masina) * lungime);
//
//	return h;
//
//}
//
//
//
//
//Masina initializareMasina(int id,int nrUsi,float pret,char* model,char* numeSofer,unsigned char serie) {
//
//	Masina m;
//	m.id = id;
//	m.nrUsi = nrUsi;
//	m.pret = pret;
//	m.model = _strdup(model);
//	m.numeSofer = _strdup(numeSofer);
//	m.serie = serie;
//
//	return m;
//
//
// }
//
//
//
//
//
//
//
//void filtreazaheap(Heap h, int pozitieNod) {
//	int pozFiuStanga = 2 * pozitieNod + 1;
//	int pozFiuDreapta = 2 * pozitieNod + 2;
//	int maxim = pozitieNod;
//
//	if (pozFiuStanga < h.nrMasini && h.vector[maxim].id < h.vector[pozFiuStanga].id) {
//		maxim = pozFiuStanga;
//	}
//	if (pozFiuDreapta < h.nrMasini && h.vector[maxim].id < h.vector[pozFiuDreapta].id) {
//		maxim = pozFiuDreapta;
//	}
//
//	if (maxim != pozitieNod) {
//		Masina aux = h.vector[maxim];
//		h.vector[maxim] = h.vector[pozitieNod];
//		h.vector[pozitieNod] = aux;
//
//		if (maxim <= (h.nrMasini - 2) / 2) {
//			filtreazaheap(h, maxim);
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
//void adaugainHeap(Heap* h, Masina m) {
//
//	if (h->nrMasini < h->lungime) {
//		h->vector[h->nrMasini++] = m;
//	}
//	else {
//		printf("Nu mai e spatiu in heap");
//	}
//
//	for (int i = (h->nrMasini - 2) / 2; i <= 0; i++) {
//
//		filtreazaheap(*h, i);
//	}
//
//
//
//
//}
//
//
//
//
//Heap citireHeapDeMasiniDinFisier(const char * numeFisier) {
//	Heap h = initializareHeap(10);
//	FILE* F = fopen(numeFisier, "r");
//
//	while (!feof(F)) {
//
//		Masina m = citireMasinaDinFisier(F);
//		h.vector[h.nrMasini++] = m;
//	}
//	fclose(F);
//
//	for (int i = (h.nrMasini - 2) / 2; i <= 0; i--) {
//		filtreazaheap(h, i);
//	}
//
//	return h;
//}
//
//
//
//
//
//void afisareHeap(Heap h) {
//
//	for (int i = 0; i < h.nrMasini; i++) {
//		afisareMasina(h.vector[i]);
//	}
//}
//
//
//
//
//void afisareHeapAscuns(Heap h) {
//	for (int i = h.nrMasini; i < h.lungime; i++) {
//		afisareMasina(h.vector[i]);
//	}
//}
//
//
//
//Masina extragemasina(Heap* h) {
//
//	if (h->nrMasini > 0) {
//		Masina aux = h->vector[0];
//		h->vector[0] = h->vector[h->nrMasini - 1];
//		h->vector[h->nrMasini - 1] = aux;
//		h->nrMasini--;
//		for (int i = (h->nrMasini - 2) / 2; i <= 0; i--) {
//			filtreazaheap(*h, i);
//		}
//
//		return aux;
//	}
//	
//}
//
//
//
//void dezalocareHeap(Heap* h) {
//
//	for (int i = 0; i < h->lungime;i++) {
//		free(h->vector[i].model);
//		free(h->vector[i].numeSofer);
//	}
//	free(h->vector);
//	h->vector = NULL;
//	h->nrMasini = 0;
//	h->lungime = 0;
//}
//
//
//int main() {
//
//
//	Heap h1 = initializareHeap(10);
//	Masina m1 = initializareMasina(1, 4, 15000.0, "Dacia Logan", "Andrei Popescu", 'A');
//	Masina m2 = initializareMasina(2, 2, 28000.5, "Mazda MX-5", "Elena Ionescu", 'B');
//	Masina m3 = initializareMasina(3, 4, 33000.0, "Toyota Corolla", "Ion Marinescu", 'C');
//	Masina m4 = initializareMasina(4, 5, 45000.0, "Audi Q5", "Mihai Georgescu", 'D');
//	Masina m5 = initializareMasina(5, 3, 21000.0, "Mini Cooper", "Raluca Ene", 'E');
//	Masina m6 = initializareMasina(6, 4, 18500.0, "Volkswagen Golf", "Florin Dumitru", 'F');
//	Masina m7 = initializareMasina(7, 4, 120000.0, "Tesla Model S", "Cristina Vlad", 'G');
//	Masina m8 = initializareMasina(8, 5, 78000.0, "BMW X5", "Ionut Badea", 'H');
//	Masina m9 = initializareMasina(9, 2, 97000.0, "Porsche 911", "Alina Stoica", 'I');
//	Masina m10 = initializareMasina(10, 4, 16500.0, "Ford Focus", "Stefan Radu", 'J');
//
//	adaugainHeap(&h1, m1);
//	adaugainHeap(&h1, m2);
//	adaugainHeap(&h1, m3);
//	adaugainHeap(&h1, m4);
//	adaugainHeap(&h1, m5);
//	adaugainHeap(&h1, m6);
//	adaugainHeap(&h1, m7);
//	adaugainHeap(&h1, m8);
//	adaugainHeap(&h1, m9);
//	adaugainHeap(&h1, m10);
//
//	Heap h2 = citireHeapDeMasiniDinFisier("masini_heap.txt");
//	afisareHeap(h1);
//	printf("-----------------afiare H2--------------------- \n");
//	afisareHeap(h2);
//
//	printf("-------Masina extrasa------\n");
//
//	afisareMasina( extragemasina(&h1));
//	printf("------------------afisare Heap ascuns--------------\n");
//	afisareHeapAscuns(h1);
//	dezalocareHeap(&h1);
//	return 0;
//}