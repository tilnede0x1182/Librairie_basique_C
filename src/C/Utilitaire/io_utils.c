/* =============================================================================
 * io_utils.c
 * Utilitaires d'entrees/sorties pour la gestion de fichiers et arguments CLI.
 * ============================================================================= */

/* =============================================================================
 * Importations
 * ============================================================================= */

#include "io_utils.h"

#include <stdlib.h>
#include <string.h>

/* =============================================================================
 * Fonctions utilitaires - Gestion de fichiers
 * ============================================================================= */

/**
 *	Ouvre un fichier avec le mode specifie.
 *	Termine le programme si l'ouverture echoue.
 *
 *	@param chemin Chemin du fichier a ouvrir
 *	@param mode Mode d'ouverture (r, w, a, etc.)
 *	@return Pointeur vers le fichier ouvert
 */
FILE *ouvrir_fichier(const char *chemin, const char *mode) {
	FILE *fichier = fopen(chemin, mode);
	if (!fichier) {
		fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", chemin);
		exit(EXIT_FAILURE);
	}
	return fichier;
}

/**
 *	Ferme un fichier ouvert.
 *	Termine le programme si la fermeture echoue.
 *
 *	@param fichier Pointeur vers le fichier a fermer
 *	@param chemin Chemin du fichier (pour message d'erreur)
 */
void fermer_fichier(FILE *fichier, const char *chemin) {
	if (fichier && fclose(fichier) == EOF) {
		fprintf(stderr, "Probleme de fermeture du fichier %s\n", chemin);
		exit(EXIT_FAILURE);
	}
}

/* =============================================================================
 * Fonctions utilitaires - Arguments CLI
 * ============================================================================= */

/**
 *	Verifie le nombre d'arguments et recupere le premier argument.
 *	Termine le programme si les arguments sont invalides.
 *
 *	@param nombre_args Nombre d'arguments recus (argc)
 *	@param arguments Tableau d'arguments (argv)
 *	@param nombre_souhaite Nombre d'arguments attendus
 *	@param chaine Buffer de destination pour l'argument
 *	@param capacite Taille du buffer de destination
 */
void verif_et_recup_arg(int nombre_args, char *arguments[], int nombre_souhaite,
                        char *chaine, size_t capacite) {
	if (nombre_args != nombre_souhaite) {
		fprintf(stderr, "Usage : programme nom_fichier\n");
		exit(EXIT_FAILURE);
	}
	size_t longueur = strlen(arguments[1]);
	if (longueur >= capacite) {
		fprintf(stderr, "Nom de fichier trop long (max %zu caracteres)\n", capacite - 1);
		exit(EXIT_FAILURE);
	}
	strncpy(chaine, arguments[1], capacite);
	chaine[capacite - 1] = '\0';
}
