# Utilitaires C - Fichiers et Chaînes

## Description

Bibliothèque d'utilitaires en C pour la gestion de fichiers et la manipulation de chaînes de caractères. Le module io_utils fournit des fonctions d'ouverture/fermeture de fichiers et de récupération d'arguments CLI. Le module util_string propose des fonctions de calcul de longueur, affichage, concaténation et extraction de sous-chaînes. Chaque fonction inclut une gestion d'erreurs et utilise l'allocation dynamique.

## Technologies

| Technologie | Version |
|-------------|---------|
| Langage | C99 |
| Compilateur | GCC 14.2.0 |
| Bibliothèques | stdio.h, stdlib.h, string.h |
| Build | Make |

## Lancement

Compiler tous les programmes :
```
make compile
```

Exécuter tous les tests :
```
make run
```

Nettoyer les fichiers objets :
```
make clean
```

## Fonctionnalités

### Module io_utils

| Fonction | Description | Commande |
|----------|-------------|----------|
| ouvrir_fichier | Ouvre un fichier avec gestion d'erreur | - |
| fermer_fichier | Ferme un fichier avec gestion d'erreur | - |
| verif_et_recup_arg | Valide et récupère un argument CLI | - |

Tests : `bin/ouverture_fichier.exe`, `bin/lecture_fichier.exe`, `bin/ecriture_stdin.exe`

### Module util_string

| Fonction | Description | Commande |
|----------|-------------|----------|
| calcLength | Calcule la longueur d'une chaîne | - |
| aff | Affiche une chaîne sur stdout | - |
| copieFinChaine | Concatène c1 + c2 | - |
| copieDebutChaine | Concatène c2 + c1 | - |
| coupeStr | Extrait une sous-chaîne | - |

Tests : `bin/manipulation_chaines.exe`
