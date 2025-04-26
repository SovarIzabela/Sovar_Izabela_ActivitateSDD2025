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
//	Nod * first;
//	Nod * last;
//	int  nrNoduri;
//};
//typedef struct ListaDubla ListaDubla;
//
//Bloc citireBlocDinFisier(FILE* file) {
//	Bloc bloc;
//	char buffer[100];
//	char* sep =  ",;\n" ;
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
//	bloc.pretMediuMP = (float)atof(token);
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
//void adaugaBlocInListaFinal(ListaDubla* lista,  Bloc blocNou) {
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
//ListaDubla citireLDBlocDinFisier(const char* numeFisier) {
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
//	return lista;
//
//}
//
//void dezalocareBloc(Bloc bloc) {
//	if (bloc.adresa != NULL) {
//		free(bloc.adresa);
//	}
//
//}
//
//void dezalocareLDBloc(ListaDubla*lista) {
//	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
//	Nod* p = lista->first;
//	while (p) {
//		Nod* aux = p;
//		p = p->next;
//		if (aux->info.adresa != NULL) {
//			free(aux->info.adresa);
//		}
//		free(aux);
//	}
//
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	//calculeaza pretul mediu al masinilor din lista.
//	if(lista.first)
//	{
//		float suma = 0;
//		Nod* p = lista.first;
//
//		while (p) {
//			suma = suma + p->info.pretMediuMP;
//			p = p->next;
//		}
//		return suma / lista.nrNoduri;
//	}
//
//	return 0;
//}
//
//void stergeBlocDupaAnConstructie(ListaDubla* lista,  int an) {
//	if (lista->first == NULL) {
//		return;
//	}
//	Nod* p = lista->first;
//	while (p && p->info.anConstructie!=an) {
//		p = p->next;
//
//	}
//	if (p == NULL) {
//		return;
//	}
//	if (p->prev == NULL) {
//		lista->first = p->next;
//
//		if (lista->first) {
//			lista->first->prev = NULL;
//		}
//
//	}
//	else{
//		p->prev->next = p->next;
//	}
//
//	if (p->next != NULL) {
//		p->next->prev = p->prev;
//	}
//	else {
//		lista->last = p->prev;
//	}
//
//	if (p->info.adresa != NULL) {
//		free(p->info.adresa);
//	}
//	free(p);
//	p = NULL;
//	lista->nrNoduri--;
//}
//
//char* getAdresaBlocScumpMP(ListaDubla lista) {
//	//cauta ADRESA pentru blocul cu cel mai amre pret/mp
//	//returneaza adresa blocului
//	if (lista.first)
//	{
//		Nod* maxim = lista.first;
//		Nod* p = lista.first->next;
//		while (p) {
//			if (p->info.pretMediuMP > maxim->info.pretMediuMP)
//			{
//				maxim = p;
//
//			}
//			p = p->next;
//		}
//
//		char* adresa = (char*)malloc(strlen(maxim->info.adresa) + 1);
//		strcpy(adresa, maxim->info.adresa);
//
//
//
//		return adresa;
//	}
//	else {
//		return NULL;
//	}
//}
//
//int main() {
//
//
//	ListaDubla nou = citireLDBlocDinFisier("bloc.txt");
//	afisareListaBlocDeLAiNCEPUT(nou);
//	printf("-----De la sfarsit-----------\n");
//	afisareListaBlocdElAsFARSIT(nou);
//
//	printf("----functia de stergere----------\n");
//
//	stergeBlocDupaAnConstructie(&nou, 1986);
//	afisareListaBlocDeLAiNCEPUT(nou);
//
//	printf("----functia de stergere----------\n");
//
//	stergeBlocDupaAnConstructie(&nou, 1955);
//	afisareListaBlocDeLAiNCEPUT(nou);
//
//	printf("pretul mediu al listei este : %.2f \n",calculeazaPretMediu(nou));
//
//	char* adresa = getAdresaBlocScumpMP(nou);
//	printf("Adresa cu cel mai scum pretMP este: %s\n", adresa);
//	if (adresa) {
//		free(adresa);
//	}
//	dezalocareLDBloc(&nou);
//	return 0;
//}