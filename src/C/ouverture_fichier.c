/* =============================================================================
 * ouverture_fichier.c
 * Test des fonctions ouvrir_fichier et fermer_fichier du module io_utils.
 * ============================================================================= */

/* =============================================================================
 * Importations
 * ============================================================================= */

#include "io_utils.h"

#include <stdio.h>

/* =============================================================================
 * Variables globales de test
 * ============================================================================= */

static int tests_reussis = 0;
static int tests_total = 0;

/* =============================================================================
 * Fonctions utilitaires de test
 * ============================================================================= */

/**
 *	Affiche le resultat d'un test.
 *
 *	@param nom_test Nom du test
 *	@param reussi 1 si le test a reussi, 0 sinon
 */
static void afficher_resultat(const char *nom_test, int reussi) {
	tests_total++;
	if (reussi) {
		tests_reussis++;
		printf("[OK] %s\n", nom_test);
	} else {
		printf("[ECHEC] %s\n", nom_test);
	}
}

/* =============================================================================
 * Tests
 * ============================================================================= */

/**
 *	Teste l'ouverture et fermeture d'un fichier existant.
 */
static void test_ouverture_fichier_existant(void) {
	const char *chemin = "Sauvegarde.txt";
	FILE *fichier = ouvrir_fichier(chemin, "r");
	int ouvert = (fichier != NULL);
	fermer_fichier(fichier, chemin);
	afficher_resultat("ouvrir_fichier avec fichier existant", ouvert);
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	printf("\n=== Tests io_utils : ouverture/fermeture ===\n\n");

	test_ouverture_fichier_existant();

	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
