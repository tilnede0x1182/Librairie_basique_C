#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fic; 
	char ligne_lue[512];
	
	// ouverture du fichier
	fic = fopen("resultat.txt", "w"); // ouvrir en ecriture
	if (fic == NULL){
			printf ("Impossible d'ouvrir le fichier resultat.txt\n");
			exit(1);
	}

	do{
		fgets(ligne_lue, 512, stdin);
		fputs(ligne_lue, fic);
	}
	while (strcmp(ligne_lue, "FIN\n") != 0); 

	// fermeture du fichier
	if (fclose(fic)==EOF) {
			printf ("Probleme de fermeture du fichier resultat.txt\n");
			exit(1);
	}
	
	printf ("les donnees ont ete stockees dans resultat.txt\n");

	return 0;
}
