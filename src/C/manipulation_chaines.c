/* =============================================================================
 * manipulation_chaines.c
 * Test des fonctions du module util_string.
 * ============================================================================= */

/* =============================================================================
 * Importations
 * ============================================================================= */

#include "util_string.h"

#include <stdio.h>
#include <stdlib.h>
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
 * Tests - calcLength
 * ============================================================================= */

/**
 *	Teste calcLength avec differents cas.
 */
static void test_calcLength(void) {
	int ok1 = (calcLength("hello") == 5);
	int ok2 = (calcLength("") == 0);
	int ok3 = (calcLength(NULL) == 0);
	int ok4 = (calcLength("a") == 1);

	afficher_resultat("calcLength chaine normale", ok1);
	afficher_resultat("calcLength chaine vide", ok2);
	afficher_resultat("calcLength NULL", ok3);
	afficher_resultat("calcLength un caractere", ok4);
}

/* =============================================================================
 * Tests - copieFinChaine / copieDebutChaine
 * ============================================================================= */

/**
 *	Teste copieFinChaine (c1 + c2).
 */
static void test_copieFinChaine(void) {
	char *resultat = copieFinChaine("abc", "def");
	int ok = (strcmp(resultat, "abcdef") == 0);
	printf("  -> copieFinChaine(\"abc\", \"def\") = \"%s\"\n", resultat);
	afficher_resultat("copieFinChaine concatenation", ok);
	free(resultat);
}

/**
 *	Teste copieDebutChaine (c2 + c1).
 */
static void test_copieDebutChaine(void) {
	char *resultat = copieDebutChaine("abc", "def");
	int ok = (strcmp(resultat, "defabc") == 0);
	printf("  -> copieDebutChaine(\"abc\", \"def\") = \"%s\"\n", resultat);
	afficher_resultat("copieDebutChaine concatenation inversee", ok);
	free(resultat);
}

/* =============================================================================
 * Tests - coupeStr
 * ============================================================================= */

/**
 *	Teste coupeStr avec differents cas.
 */
static void test_coupeStr(void) {
	char *r1 = coupeStr("abcdefgh", 0, 3);
	char *r2 = coupeStr("abcdefgh", 2, 5);
	char *r3 = coupeStr("abcdefgh", 0, 100);
	char *r4 = coupeStr("abcdefgh", -1, 3);

	int ok1 = (r1 && strcmp(r1, "abc") == 0);
	int ok2 = (r2 && strcmp(r2, "cde") == 0);
	int ok3 = (r3 && strcmp(r3, "abcdefgh") == 0);
	int ok4 = (r4 == NULL);

	printf("  -> coupeStr(\"abcdefgh\", 0, 3) = \"%s\"\n", r1 ? r1 : "NULL");
	afficher_resultat("coupeStr debut de chaine", ok1);
	afficher_resultat("coupeStr milieu de chaine", ok2);
	afficher_resultat("coupeStr fin depasse", ok3);
	afficher_resultat("coupeStr indice negatif", ok4);

	free(r1);
	free(r2);
	free(r3);
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(void) {
	printf("\n=== Tests util_string ===\n\n");

	test_calcLength();
	printf("\n");
	test_copieFinChaine();
	test_copieDebutChaine();
	printf("\n");
	test_coupeStr();

	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
