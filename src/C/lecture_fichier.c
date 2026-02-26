/* =============================================================================
 * lecture_fichier.c
 * Test des fonctions de lecture de fichier du module io_utils.
 * ============================================================================= */

/* =============================================================================
 * Importations
 * ============================================================================= */

#include "io_utils.h"

#include <stdio.h>
#include <string.h>

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
 * Tests - Cas banal
 * ============================================================================= */

/**
 *	Teste la lecture d'un fichier et le comptage de lignes.
 */
static void test_lecture_et_comptage(void) {
	const char *chemin = "tests/utilitaire_tests/Sauvegarde.txt";
	FILE *fichier = ouvrir_fichier(chemin, "r");
	char ligne[512];
	int nombre_lignes = 0;

	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
		nombre_lignes++;
	}
	fermer_fichier(fichier, chemin);

	int reussi = (nombre_lignes > 0);
	printf("  -> %d lignes lues dans %s\n", nombre_lignes, chemin);
	afficher_resultat("lecture fichier et comptage lignes", reussi);
}

/**
 *	Teste la fonction verif_et_recup_arg avec arguments simules.
 */
static void test_verif_recup_arg(void) {
	char buffer[255];
	char *args_simules[] = {"programme", "Sauvegarde.txt"};

	verif_et_recup_arg(2, args_simules, 2, buffer, sizeof(buffer));

	int reussi = (strcmp(buffer, "Sauvegarde.txt") == 0);
	printf("  -> argument recupere : \"%s\"\n", buffer);
	afficher_resultat("verif_et_recup_arg avec 2 arguments", reussi);
}

/* =============================================================================
 * Tests - Cas limites
 * ============================================================================= */

/**
 *	Teste la lecture d'un fichier vide.
 */
static void test_lecture_fichier_vide(void) {
	const char *chemin = "tests/outputs/test_vide.txt";
	FILE *fichier = ouvrir_fichier(chemin, "w");
	fermer_fichier(fichier, chemin);

	fichier = ouvrir_fichier(chemin, "r");
	char ligne[512];
	int nombre_lignes = 0;

	while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
		nombre_lignes++;
	}
	fermer_fichier(fichier, chemin);

	int reussi = (nombre_lignes == 0);
	printf("  -> %d lignes dans fichier vide\n", nombre_lignes);
	afficher_resultat("lecture fichier vide (0 lignes)", reussi);
}

/**
 *	Teste verif_et_recup_arg avec argument court (1 caractere).
 */
static void test_verif_recup_arg_court(void) {
	char buffer[255];
	char *args_simules[] = {"programme", "a"};

	verif_et_recup_arg(2, args_simules, 2, buffer, sizeof(buffer));

	int reussi = (strcmp(buffer, "a") == 0);
	printf("  -> argument court recupere : \"%s\"\n", buffer);
	afficher_resultat("verif_et_recup_arg argument 1 caractere", reussi);
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;

	printf("\n=== Tests io_utils : lecture fichier ===\n\n");

	printf("--- Cas banal ---\n");
	test_lecture_et_comptage();
	test_verif_recup_arg();

	printf("\n--- Cas limites ---\n");
	test_lecture_fichier_vide();
	test_verif_recup_arg_court();

	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
