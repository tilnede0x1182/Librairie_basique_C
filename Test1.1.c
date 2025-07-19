#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void verif_et_recup_arg(int nb, char *arguments[], int nb_souhaite, char *chaine) {
	if(nb != nb_souhaite){
		printf("Usage : lignes nom_fichier\n");
		exit(1);
	}

	strcpy(chaine, arguments[1]);
}

int main (int argc, char *argv[]) {
	FILE *fic; 
	int nb_lignes;
	char ligne_lue[512];
	char nom_fic[255];

	verif_et_recup_arg(argc, argv, 2, nom_fic);
	
	// ouverture du fichier
	fic = fopen(nom_fic, "r"); // ouvrir en lecture
	if(fic == NULL){
			printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
			exit(1);
	}
	printf(".............. Ouverture du fichier %s\n", nom_fic);

	// compter et afficher les lignes du fichier
	nb_lignes = 0;
	while (fgets(ligne_lue, 512, fic) != NULL){
		printf("\t%s", ligne_lue);
		nb_lignes++;
	}
	printf("le fichier %s comporte %d lignes\n", nom_fic, nb_lignes);

	// fermeture du fichier
	if (fclose(fic) == EOF) {
			printf("Probleme de fermeture du fichier %s", nom_fic);
			exit(1);
	}
	printf (".............. Fermeture du fichier %s\n", nom_fic);

	return 0;
}
