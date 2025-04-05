//#define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
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
//Bloc initializare(int nrEtaje, int nrApartamente, float pretMediuMP, char* adresa, int anConstructie, unsigned char tipCertificatEnergetic) {
//	Bloc b;
//	
//	b.nrEtaje = nrEtaje;
//	b.nrApartamente = nrApartamente;
//	b.pretMediuMP = pretMediuMP;
//	b.adresa = (char*)malloc(sizeof(char)*(strlen(adresa) + 1));
//	strcpy_s(b.adresa, strlen(adresa) + 1, adresa);
//	b.anConstructie = anConstructie;
//	b.tipCertificatEnergetic = tipCertificatEnergetic;
//
//	return b;
//}
//
//void afisareBloc(Bloc bloc) {
//	printf("Nr Etaje: %d\n", bloc.nrEtaje);
//	printf("Nr Apartamente: %d\n", bloc.nrApartamente);
//	printf("Pret Mediu MP: %.2f\n", bloc.pretMediuMP);
//	printf("Adresa: %s\n", bloc.adresa);
//	printf("An constructie: %d\n", bloc.anConstructie);
//	printf("Tip Certificat Energetic: %c\n\n", bloc.tipCertificatEnergetic);
//	
//}
//
//void afisareVectorBloc(Bloc* bloc, int nrBlocuri) {
//
//	for (int i = 0; i < nrBlocuri; i++) {
//		afisareBloc(bloc[i]);
//	}
//	
//
//}
//
//void adaugaBlocInVector(Bloc** bloc, int* nrElemente, Bloc blocAdaugat) {
//
//	Bloc* vectorNou = (Bloc*)malloc(sizeof(Bloc) * ((*nrElemente)+1));
//
//	for (int i = 0; i < (*nrElemente); i++) {
//		vectorNou[i] = (*bloc)[i];
//
//	}
//
//	vectorNou[(*nrElemente)] = blocAdaugat;
//	free(*bloc);
//	(*bloc) = vectorNou;
//	(*nrElemente)++;
//
//
//}
//
//Bloc citireBlocDinFisier(FILE* file) {
//	
//
//	Bloc b;
//	char buffer[100];
//	char delimitator[4] =  ",;\n" ;
//	fgets(buffer, 100, file);
//
//
//	b.nrEtaje = atoi(strtok(buffer, delimitator));
//	b.nrApartamente = atoi(strtok(NULL,delimitator));
//	b.pretMediuMP = atof(strtok(NULL, delimitator));
//	char* aux;
//	aux = strtok(NULL, delimitator);
//	b.adresa = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.adresa, aux);
//	
//	b.anConstructie = atoi(strtok(NULL, delimitator));
//	b.tipCertificatEnergetic = strtok(NULL, delimitator)[0];
//
//
//	return b;
//	
//}
//
//Bloc* citireVectorBlocDinFisier(const char* numeFisier, int* nrElementeCitite) {
//	
//	FILE* f = fopen(numeFisier, "r");
//	Bloc* vectorBloc = NULL;
//	(*nrElementeCitite) = 0;
//	while (!feof(f)) {
//		adaugaBlocInVector(&vectorBloc, nrElementeCitite, citireBlocDinFisier(f));
//	}
//	fclose(f);
//	return vectorBloc;
//}
//
//void dezalocareVectorBloc(Bloc** bloc, int*nrBloc) {
//	for (int i = 0; i < (*nrBloc); i++) {
//		if((*bloc)[i].adresa!=NULL)
//		{
//				free((*bloc)[i].adresa);
//		}
//	}
//	
//	free(*bloc);
//	(*bloc) = NULL;
//	(*nrBloc) = 0;
//
//}
//
//
//int main() {
//
//	Bloc  bloc1 = { 2,10,150.2,"bdTimisoara",2017,'A' };
//	Bloc  bloc2 = { 5,19,180.2,"bdIuliuManiu",2022,'A' };
//	Bloc  bloc3 = { 7,30,150.2,"Veteranilor",2019,'B' };
//	afisareBloc(bloc1);
//
//	Bloc* vectorBloc =NULL;
//	int numarBlocuri = 3;
//	vectorBloc = (Bloc*)malloc(sizeof(Bloc)*numarBlocuri);
//	vectorBloc[0] = initializare(2, 10, 150.2, "bdTimisoara", 2017, 'A');
//	vectorBloc[1] = initializare(5, 19, 180.2, "bdIuliuManiu", 2022, 'A');
//	vectorBloc[2] = initializare(7, 30, 150.2, "Veteranilor", 2019, 'B');
//
//	afisareVectorBloc(vectorBloc, numarBlocuri);
//
//	adaugaBlocInVector(&vectorBloc, &numarBlocuri, bloc3);
//	afisareVectorBloc(vectorBloc, numarBlocuri);
//
//
//	FILE* file = fopen("bloc1.txt", "r");
//	if (file == NULL) {
//		printf("Eroare la deschiderea fisierului");
//		return 1;
//	}
//
//	Bloc bloc4 =citireBlocDinFisier(file);
//	printf("Bloc citit din fisier\n");
//	afisareBloc(bloc4);
//	fclose(file);
//
//	printf("-------BlocNou----------\n");
//	int nrBlocNou = 0;
//	Bloc * vector2Bloc = citireVectorBlocDinFisier("bloc.txt", &nrBlocNou);
//	afisareVectorBloc(vector2Bloc, nrBlocNou);
//
//	dezalocareVectorBloc(&vector2Bloc, &nrBlocNou);
//
//	return 0;
//
//}