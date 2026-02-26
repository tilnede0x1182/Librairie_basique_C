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
 * Tests - calcLength cas banal
 * ============================================================================= */

/**
 *	Teste calcLength avec chaine normale.
 */
static void test_calcLength_normal(void) {
	int ok = (calcLength("hello") == 5);
	afficher_resultat("calcLength chaine normale", ok);
}

/* =============================================================================
 * Tests - calcLength cas limites
 * ============================================================================= */

/**
 *	Teste calcLength avec chaine vide.
 */
static void test_calcLength_vide(void) {
	int ok = (calcLength("") == 0);
	afficher_resultat("calcLength chaine vide", ok);
}

/**
 *	Teste calcLength avec NULL.
 */
static void test_calcLength_null(void) {
	int ok = (calcLength(NULL) == 0);
	afficher_resultat("calcLength NULL", ok);
}

/**
 *	Teste calcLength avec un seul caractere.
 */
static void test_calcLength_un_char(void) {
	int ok = (calcLength("a") == 1);
	afficher_resultat("calcLength un caractere", ok);
}

/**
 *	Teste calcLength avec caracteres speciaux.
 */
static void test_calcLength_speciaux(void) {
	int ok = (calcLength("é") >= 1);
	printf("  -> calcLength(\"e\") = %zu\n", calcLength("é"));
	afficher_resultat("calcLength caractere accentue", ok);
}

/* =============================================================================
 * Tests - copieFinChaine / copieDebutChaine cas banal
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
 * Tests - copieFinChaine cas limites
 * ============================================================================= */

/**
 *	Teste copieFinChaine avec chaine vide.
 */
static void test_copieFinChaine_vide(void) {
	char *r1 = copieFinChaine("", "abc");
	char *r2 = copieFinChaine("abc", "");
	int ok = (strcmp(r1, "abc") == 0) && (strcmp(r2, "abc") == 0);
	afficher_resultat("copieFinChaine avec chaine vide", ok);
	free(r1);
	free(r2);
}

/* =============================================================================
 * Tests - coupeStr cas banal
 * ============================================================================= */

/**
 *	Teste coupeStr debut de chaine.
 */
static void test_coupeStr_debut(void) {
	char *resultat = coupeStr("abcdefgh", 0, 3);
	int ok = (resultat && strcmp(resultat, "abc") == 0);
	printf("  -> coupeStr(\"abcdefgh\", 0, 3) = \"%s\"\n", resultat ? resultat : "NULL");
	afficher_resultat("coupeStr debut de chaine", ok);
	free(resultat);
}

/**
 *	Teste coupeStr milieu de chaine.
 */
static void test_coupeStr_milieu(void) {
	char *resultat = coupeStr("abcdefgh", 2, 5);
	int ok = (resultat && strcmp(resultat, "cde") == 0);
	afficher_resultat("coupeStr milieu de chaine", ok);
	free(resultat);
}

/* =============================================================================
 * Tests - coupeStr cas limites
 * ============================================================================= */

/**
 *	Teste coupeStr avec fin qui depasse.
 */
static void test_coupeStr_depasse(void) {
	char *resultat = coupeStr("abcdefgh", 0, 100);
	int ok = (resultat && strcmp(resultat, "abcdefgh") == 0);
	afficher_resultat("coupeStr fin depasse", ok);
	free(resultat);
}

/**
 *	Teste coupeStr avec indice negatif.
 */
static void test_coupeStr_negatif(void) {
	char *resultat = coupeStr("abcdefgh", -1, 3);
	int ok = (resultat == NULL);
	afficher_resultat("coupeStr indice negatif -> NULL", ok);
}

/**
 *	Teste coupeStr avec NULL.
 */
static void test_coupeStr_null(void) {
	char *resultat = coupeStr(NULL, 0, 3);
	int ok = (resultat == NULL);
	afficher_resultat("coupeStr(NULL) -> NULL", ok);
}

/**
 *	Teste coupeStr avec debut = fin (chaine vide).
 */
static void test_coupeStr_debut_egal_fin(void) {
	char *resultat = coupeStr("abcdefgh", 3, 3);
	int ok = (resultat && strcmp(resultat, "") == 0);
	afficher_resultat("coupeStr debut=fin -> chaine vide", ok);
	free(resultat);
}

/**
 *	Teste coupeStr avec chaine source vide.
 */
static void test_coupeStr_source_vide(void) {
	char *resultat = coupeStr("", 0, 0);
	int ok = (resultat && strcmp(resultat, "") == 0);
	afficher_resultat("coupeStr chaine source vide", ok);
	free(resultat);
}

/* =============================================================================
 * Fonctions de regroupement des tests
 * ============================================================================= */

/**
 *	Execute tous les tests de calcLength.
 */
static void executer_tests_calcLength(void) {
	printf("--- calcLength cas banal ---\n");
	test_calcLength_normal();
	printf("\n--- calcLength cas limites ---\n");
	test_calcLength_vide();
	test_calcLength_null();
	test_calcLength_un_char();
	test_calcLength_speciaux();
}

/**
 *	Execute tous les tests de copie.
 */
static void executer_tests_copie(void) {
	printf("\n--- copie cas banal ---\n");
	test_copieFinChaine();
	test_copieDebutChaine();
	printf("\n--- copie cas limites ---\n");
	test_copieFinChaine_vide();
}

/**
 *	Execute tous les tests de coupeStr.
 */
static void executer_tests_coupeStr(void) {
	printf("\n--- coupeStr cas banal ---\n");
	test_coupeStr_debut();
	test_coupeStr_milieu();
	printf("\n--- coupeStr cas limites ---\n");
	test_coupeStr_depasse();
	test_coupeStr_negatif();
	test_coupeStr_null();
	test_coupeStr_debut_egal_fin();
	test_coupeStr_source_vide();
}

/* =============================================================================
 * Main
 * ============================================================================= */

int main(void) {
	printf("\n=== Tests util_string ===\n\n");
	executer_tests_calcLength();
	executer_tests_copie();
	executer_tests_coupeStr();
	printf("\n=== Resultat : %d/%d tests reussis ===\n\n", tests_reussis, tests_total);
	return (tests_reussis == tests_total) ? 0 : 1;
}
