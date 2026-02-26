/* =============================================================================
 * io_utils.h
 * En-tete des utilitaires d'entrees/sorties fichiers et arguments CLI.
 * ============================================================================= */

#ifndef IO_UTILS_H
#define IO_UTILS_H

/* =============================================================================
 * Importations
 * ============================================================================= */

#include <stdio.h>
#include <stddef.h>

/* =============================================================================
 * Declarations de fonctions
 * ============================================================================= */

/**
 *	Ouvre un fichier avec le mode specifie.
 *	Termine le programme si l'ouverture echoue.
 *
 *	@param chemin Chemin du fichier a ouvrir
 *	@param mode Mode d'ouverture (r, w, a, etc.)
 *	@return Pointeur vers le fichier ouvert
 */
FILE *ouvrir_fichier(const char *chemin, const char *mode);

/**
 *	Ferme un fichier ouvert.
 *	Termine le programme si la fermeture echoue.
 *
 *	@param fichier Pointeur vers le fichier a fermer
 *	@param chemin Chemin du fichier (pour message d'erreur)
 */
void fermer_fichier(FILE *fichier, const char *chemin);

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
                        char *chaine, size_t capacite);

#endif
