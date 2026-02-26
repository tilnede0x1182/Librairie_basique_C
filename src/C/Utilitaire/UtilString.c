/* =============================================================================
 * UtilString.c
 * Utilitaires de manipulation de chaines de caracteres.
 * ============================================================================= */

/* =============================================================================
 * Importations
 * ============================================================================= */

#include "util_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =============================================================================
 * Fonctions utilitaires - Calcul et affichage
 * ============================================================================= */

/**
 *	Calcule la longueur d'une chaine de caracteres.
 *	Reimplementation de strlen pour exercice pedagogique.
 *
 *	@param chaine Chaine dont on veut calculer la longueur
 *	@return Longueur de la chaine (0 si NULL)
 */
size_t calcLength(const char *chaine) {
	size_t compteur = 0;
	if (!chaine) {
		return 0;
	}
	while (chaine[compteur] != '\0') {
		compteur++;
	}
	return compteur;
}

/**
 *	Affiche une chaine de caracteres sur la sortie standard.
 *	Affiche "(null)" si la chaine est NULL.
 *
 *	@param chaine Chaine a afficher
 */
void aff(const char *chaine) {
	if (!chaine) {
		printf("(null)\n");
		return;
	}
	printf("%s\n", chaine);
}

/* =============================================================================
 * Fonctions utilitaires - Allocation memoire
 * ============================================================================= */

/**
 *	Alloue un buffer pour la concatenation de deux chaines.
 *	Termine le programme si l'allocation echoue.
 *
 *	@param longueur_1 Longueur de la premiere chaine
 *	@param longueur_2 Longueur de la seconde chaine
 *	@return Pointeur vers le buffer alloue
 */
static char *allouer_buffer_concat(size_t longueur_1, size_t longueur_2) {
	char *buffer = malloc((longueur_1 + longueur_2 + 1) * sizeof(char));
	if (!buffer) {
		fprintf(stderr, "Allocation memoire impossible\n");
		exit(EXIT_FAILURE);
	}
	return buffer;
}

/* =============================================================================
 * Fonctions utilitaires - Concatenation
 * ============================================================================= */

/**
 *	Concatene deux chaines : c1 + c2.
 *	Alloue une nouvelle chaine contenant c1 suivi de c2.
 *
 *	@param chaine_1 Premiere chaine (debut du resultat)
 *	@param chaine_2 Seconde chaine (fin du resultat)
 *	@return Nouvelle chaine allouee (a liberer par l'appelant)
 */
char *copieFinChaine(const char *chaine_1, const char *chaine_2) {
	size_t longueur_1 = calcLength(chaine_1);
	size_t longueur_2 = calcLength(chaine_2);
	char *resultat = allouer_buffer_concat(longueur_1, longueur_2);
	memcpy(resultat, chaine_1, longueur_1);
	memcpy(resultat + longueur_1, chaine_2, longueur_2);
	resultat[longueur_1 + longueur_2] = '\0';
	return resultat;
}

/**
 *	Concatene deux chaines : c2 + c1.
 *	Alloue une nouvelle chaine contenant c2 suivi de c1.
 *
 *	@param chaine_1 Seconde chaine (fin du resultat)
 *	@param chaine_2 Premiere chaine (debut du resultat)
 *	@return Nouvelle chaine allouee (a liberer par l'appelant)
 */
char *copieDebutChaine(const char *chaine_1, const char *chaine_2) {
	return copieFinChaine(chaine_2, chaine_1);
}

/* =============================================================================
 * Fonctions utilitaires - Extraction
 * ============================================================================= */

/**
 *	Extrait une sous-chaine entre les indices debut et fin.
 *	Les indices sont inclusifs pour debut, exclusifs pour fin.
 *
 *	@param chaine Chaine source
 *	@param debut Indice de debut (inclus)
 *	@param fin Indice de fin (exclus)
 *	@return Nouvelle sous-chaine allouee (a liberer par l'appelant), NULL si erreur
 */
char *coupeStr(const char *chaine, int debut, int fin) {
	if (!chaine || debut < 0 || fin < debut) {
		return NULL;
	}
	size_t longueur = calcLength(chaine);
	if ((size_t) fin > longueur) {
		fin = (int) longueur;
	}
	size_t portion = (size_t) (fin - debut);
	char *resultat = malloc((portion + 1) * sizeof(char));
	if (!resultat) {
		fprintf(stderr, "Allocation memoire impossible\n");
		exit(EXIT_FAILURE);
	}
	memcpy(resultat, chaine + debut, portion);
	resultat[portion] = '\0';
	return resultat;
}
