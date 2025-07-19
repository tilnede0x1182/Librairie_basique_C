#include <stdio.h>
#include <stdlib.h>

int main (int blabla, char **tabs1) {
	const char path[] = "Sauvegarde";
	char Cmode = 'r';
	char * mode = &Cmode;

	FILE *fic;

	// ouverture du fichier
	fic = fopen(path, mode); // ouvrir en lecture

	if (!fic) {
		printf("Impossible d'ouvrir le fichier %s\n", fic);
		exit(1);
	}

	//printf(".............. Ouverture du fichier %s\n", nom_fic);

	return 0;
}
