#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct Farmacie {
	int id;
	char* denumire;
	unsigned char nrMedicamente;
	float* preturi;

};
 typedef struct Farmacie Farmacie;

 struct Nod {
	 Farmacie info;
	 struct Nod* next;
 };
 typedef struct Nod Nod;

 void inserareStivaLIFO(Nod** first, Farmacie f) {
	 Nod* nou = (Nod*)malloc(sizeof(Nod));
	 nou->info = f;
	 nou->next = *first;
	 *first = nou;


 }

 void inserareCoadaFIFO(Nod** first, Farmacie f) {

	 if (!*first) {
		 *first = (Nod*)malloc(sizeof(Nod));
		 (*first)->info = f;
		 (*first)->next = NULL;
	 }

	 Nod* iterator = *first;
	 while (iterator->next) {
		 iterator = iterator->next;
	 }
	 Nod* nou = (Nod*)malloc(sizeof(Nod));
	 nou->info = f;
	 nou->next = NULL;

	 iterator->next = nou;



 }

 void stergeNodStiva(Nod** first) {

	 Nod* next = (*first)->next;
	 free(*first);
	 *first = next;
 }

 Nod* seek(Nod* first) {
	 return first;
 }


 void afisareNod(Nod* first) {
	

	 printf("ID: %d\n", first->info.id);
	 printf("Denumire: %s\n", first->info.denumire);
	 printf("NrMedicamente: %d\n", first->info.nrMedicamente);

	 for(int i =0;i<first->info.nrMedicamente;i++)
	 {
		 printf("ID: %.2f\n", first->info.preturi[i]);
	 }

 }

 void afisareStiva(Nod* first) {

	 while (first) {
		 afisareNod(first);
		 printf("----------\n");
		 first = first->next;
	 }

 }


int main() {

	float preturi[2] = {23.1f, 22.2f};
	Farmacie f1 = { 100, "Farma1", 2, preturi };
	Farmacie f2 = { 101, "Farma2", 2, preturi };
	Farmacie f3 = { 102, "Farma3", 2, preturi };
	Farmacie f4 = { 103, "Farma4", 2, preturi };
	Nod* stiva = NULL;
	inserareStivaLIFO(&stiva, f1);
	inserareStivaLIFO(&stiva, f2);
	inserareStivaLIFO(&stiva, f3);
	inserareStivaLIFO(&stiva, f4);

	afisareStiva(stiva);
	printf("------stiva dupa stergere----\n");
	stergeNodStiva(&stiva);


	Nod* coada = NULL;
	inserareCoadaFIFO(&coada, f1);
	inserareCoadaFIFO(&coada, f2);
	inserareCoadaFIFO(&coada, f3);
	printf("-----afisareCoada-------\n");
	afisareStiva(coada);

	return 0;
}