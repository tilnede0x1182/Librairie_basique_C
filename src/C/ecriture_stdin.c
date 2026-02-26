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
 * Tests
 * ============================================================================= */

/**
 *	Teste l'ecriture dans un fichier.
 */
static void test_ecriture_fichier(void) {
	const char *chemin = "test_ecriture.txt";
	const char *contenu = "Ligne de test\n";

	FILE *fichier = ouvrir_fichier(chemin, "w");
	int ecrit = (fputs(contenu, fichier) != EOF);
	fermer_fichier(fichier, chemin);

	afficher_resultat("ecriture dans fichier", ecrit);

	/* Verification de la lecture */
	fichier = ouvrir_fichier(chemin, "r");
	char buffer[256];
	char *lu = fgets(buffer, sizeof(buffer), fichier);
	fermer_fichier(fichier, chemin);

	int lecture_ok = (lu != NULL && strcmp(buffer, contenu) == 0);
	afficher_resultat("relecture du fichier ecrit", lecture_ok);
}

/**
 *	Teste la detection du mot-cle FIN.
 */
static void test_detection_fin(void) {
	int test1 = est_fin("FIN");
	int test2 = est_fin("FIN\n");
	int test3 = !est_fin("FINAL");
	int test4 = !est_fin("fin");
	int test5 = !est_fin(NULL);

	int tous_ok = test1 && test2 && test3 && test4 && test5;
	afficher_resultat("detection mot-cle FIN", tous_ok);
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(void) {
	printf("\n=== Tests io_utils : ecriture fichier ===\n\n");

	test_ecriture_fichier();
	test_detection_fin();

	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
