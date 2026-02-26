/* =============================================================================
 * ecriture_stdin.c
 * Test des fonctions d'ecriture de fichier du module io_utils.
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
 * Fonctions utilitaires
 * ============================================================================= */

/**
 *	Verifie si une ligne correspond au mot-cle de fin "FIN".
 *
 *	@param ligne Ligne a verifier
 *	@return 1 si la ligne est "FIN", 0 sinon
 */
static int est_fin(const char *ligne) {
	if (!ligne) {
		return 0;
	}
	if (strncmp(ligne, "FIN", 3) != 0) {
		return 0;
	}
	char suivant = ligne[3];
	return suivant == '\0' || suivant == '\n' || suivant == '\r';
}

/* =============================================================================
 * Tests - Cas banal
 * ============================================================================= */

/**
 *	Teste l'ecriture dans un fichier.
 */
static void test_ecriture_fichier(void) {
	const char *chemin = "tests/outputs/test_ecriture.txt";
	const char *contenu = "Ligne de test\n";

	FILE *fichier = ouvrir_fichier(chemin, "w");
	int ecrit = (fputs(contenu, fichier) != EOF);
	fermer_fichier(fichier, chemin);

	afficher_resultat("ecriture dans fichier", ecrit);

	fichier = ouvrir_fichier(chemin, "r");
	char buffer[256];
	char *lu = fgets(buffer, sizeof(buffer), fichier);
	fermer_fichier(fichier, chemin);

	int lecture_ok = (lu != NULL && strcmp(buffer, contenu) == 0);
	afficher_resultat("relecture du fichier ecrit", lecture_ok);
}

/* =============================================================================
 * Tests - Cas limites detection FIN
 * ============================================================================= */

/**
 *	Teste la detection du mot-cle FIN avec differents cas.
 */
static void test_detection_fin_banal(void) {
	int ok = est_fin("FIN") && est_fin("FIN\n");
	afficher_resultat("detection FIN et FIN\n", ok);
}

/**
 *	Teste est_fin avec FIN\r (retour chariot Windows).
 */
static void test_detection_fin_retour_chariot(void) {
	int ok = est_fin("FIN\r");
	afficher_resultat("detection FIN\r", ok);
}

/**
 *	Teste est_fin avec des cas qui ne sont pas FIN.
 */
static void test_detection_fin_negatif(void) {
	int ok = !est_fin("FINAL") && !est_fin("fin") && !est_fin("FI");
	afficher_resultat("non-detection FINAL, fin, FI", ok);
}

/**
 *	Teste est_fin avec NULL.
 */
static void test_detection_fin_null(void) {
	int ok = !est_fin(NULL);
	afficher_resultat("est_fin(NULL) retourne 0", ok);
}

/**
 *	Teste est_fin avec chaine vide.
 */
static void test_detection_fin_vide(void) {
	int ok = !est_fin("");
	afficher_resultat("est_fin(\"\") retourne 0", ok);
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(void) {
	printf("\n=== Tests io_utils : ecriture fichier ===\n\n");

	printf("--- Cas banal ---\n");
	test_ecriture_fichier();
	test_detection_fin_banal();

	printf("\n--- Cas limites ---\n");
	test_detection_fin_retour_chariot();
	test_detection_fin_negatif();
	test_detection_fin_null();
	test_detection_fin_vide();

	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
