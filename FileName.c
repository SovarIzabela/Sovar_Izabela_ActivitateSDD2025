//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//
//struct StructBloc {
//
//	int nrEtaje;
//	int nrApartamente;
//	float pretMediuMP;
//	char* adresa;
//	int anConstructie;
//	unsigned char tipCertificatEnergetic;
//
//};
//typedef struct StructBloc Bloc;
//
//struct Nod {
//	Bloc  info;
//	struct Nod* next;
//	struct Nod* prev;
//};
//typedef struct Nod Nod;
//
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int  nrNoduri;
//};
//typedef ListaDubla ListaDubla;
//
//Bloc citireBlocDinFisier(FILE* file) {
//	Bloc bloc;
//	char buffer[100];
//	char* sep = ",;\n";
//	fgets(buffer, 100, file);
//
//	char* token = strtok(buffer, sep);
//	if (token == NULL) return bloc;
//	bloc.nrEtaje = atoi(token);
//
//	token = strtok(NULL, sep);
//	if (token == NULL) return bloc;
//	bloc.nrApartamente = atoi(token);
//
//	token = strtok(NULL, sep);
//	if (token == NULL) return bloc;
//	bloc.pretMediuMP = atof(token);
//
//	token = strtok(NULL, sep);
//	if (token == NULL) return bloc;
//	bloc.adresa = malloc(strlen(token) + 1);
//	strcpy(bloc.adresa, token);
//
//
//	token = strtok(NULL, sep);
//	if (token == NULL) return bloc;
//	bloc.anConstructie = atoi(token);
//
//
//
//	token = strtok(NULL, sep);
//	if (token == NULL) return bloc;
//	bloc.tipCertificatEnergetic = (token)[0];
//
//	return bloc;
//
//}
//
//void afisareBloc(Bloc Bloc) {
//
//	printf("nrEtaje: %d\n", Bloc.nrEtaje);
//	printf("nrApartamente: %d\n", Bloc.nrApartamente);
//	printf("pretMediuMP: %.2f\n", Bloc.pretMediuMP);
//	printf("Adresa: %s\n", Bloc.adresa);
//	printf("An Constructie: %d\n", Bloc.anConstructie);
//	printf("tipCertificatEnergetic: %c\n", Bloc.tipCertificatEnergetic);
//	printf("\n");
//
//}
//
//void afisareListaBlocDeLAiNCEPUT(ListaDubla lista) {
//
//	Nod* p = lista.first;
//
//	while (p) {
//		afisareBloc(p->info);
//		p = p->next;
//	}
//
//}
//
//void afisareListaBlocdElAsFARSIT(ListaDubla lista) {
//	Nod* p = lista.last;
//
//	while (p) {
//		afisareBloc(p->info);
//		p = p->prev;
//	}
//}
//
//void adaugaBlocInListaFinal(ListaDubla* lista, Bloc blocNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = blocNou;
//	nou->next = NULL;
//	nou->prev = lista->last;
//
//	if (lista->last != NULL) {
//
//		lista->last->next = nou;
//	}
//	else {
//		lista->first = nou;
//
//	}
//
//	lista->last = nou;
//
//	lista->nrNoduri++;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Bloc BlocNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = BlocNou;
//	nou->next = lista->first;
//	nou->prev = NULL;
//
//	if (lista->first != NULL) {
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//
//	lista->first = nou;
//	lista->nrNoduri++;
//
//
//}
//
//ListaDubla* citireLDBlocDinFisier(const char* numeFisier) {
//
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	while (!feof(f)) {
//		adaugaBlocInListaFinal(&lista, citireBlocDinFisier(f));
//	}
//
//	fclose(f);
//	return &lista;
//
//}
//
//void dezalocareLDBloc(/*lista dubla de masini*/) {
//	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
//}
//
//float calculeazaPretMediu(/*lista de masini*/) {
//	//calculeaza pretul mediu al masinilor din lista.
//	return 0;
//}
//
//void stergeBlocDupaID(/*lista masini*/ int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//}
//
//char* getNumeSoferBlocScumpa(/*lista dublu inlantuita*/) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	return NULL;
//}
//
//int main() {
//
//
//	return 0;
//}