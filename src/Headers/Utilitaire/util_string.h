/* =============================================================================
 * util_string.h
 * En-tete des utilitaires de manipulation de chaines de caracteres.
 * ============================================================================= */

#ifndef UTIL_STRING_H
#define UTIL_STRING_H

/* =============================================================================
 * Importations
 * ============================================================================= */

#include <stddef.h>

/* =============================================================================
 * Declarations de fonctions
 * ============================================================================= */

/**
 *	Calcule la longueur d'une chaine de caracteres.
 *
 *	@param chaine Chaine dont on veut calculer la longueur
 *	@return Longueur de la chaine (0 si NULL)
 */
size_t calcLength(const char *chaine);

/**
 *	Affiche une chaine de caracteres sur la sortie standard.
 *
 *	@param chaine Chaine a afficher
 */
void aff(const char *chaine);

/**
 *	Concatene deux chaines : chaine_1 + chaine_2.
 *
 *	@param chaine_1 Premiere chaine (debut du resultat)
 *	@param chaine_2 Seconde chaine (fin du resultat)
 *	@return Nouvelle chaine allouee (a liberer par l'appelant)
 */
char *copieFinChaine(const char *chaine_1, const char *chaine_2);

/**
 *	Concatene deux chaines : chaine_2 + chaine_1.
 *
 *	@param chaine_1 Seconde chaine (fin du resultat)
 *	@param chaine_2 Premiere chaine (debut du resultat)
 *	@return Nouvelle chaine allouee (a liberer par l'appelant)
 */
char *copieDebutChaine(const char *chaine_1, const char *chaine_2);

/**
 *	Extrait une sous-chaine entre les indices debut et fin.
 *
 *	@param chaine Chaine source
 *	@param debut Indice de debut (inclus)
 *	@param fin Indice de fin (exclus)
 *	@return Nouvelle sous-chaine allouee, NULL si erreur
 */
char *coupeStr(const char *chaine, int debut, int fin);

#endif
