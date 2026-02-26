# Utilitaires C - Fichiers et Chaines

## Description

Bibliotheque d'utilitaires en C pour la gestion de fichiers et la manipulation de chaines de caracteres. Le module io_utils fournit des fonctions d'ouverture/fermeture de fichiers et de recuperation d'arguments CLI. Le module util_string propose des fonctions de calcul de longueur, affichage, concatenation et extraction de sous-chaines. Chaque fonction inclut une gestion d'erreurs et utilise l'allocation dynamique.

## Technologies

| Technologie | Version |
|-------------|---------|
| Langage | C99 |
| Compilateur | GCC 14.2.0 |
| Bibliotheques | stdio.h, stdlib.h, string.h |
| Build | Make |

## Lancement

Compiler tous les programmes :
```
make compile
```

Executer tous les tests :
```
make run
```

Nettoyer les fichiers objets :
```
make clean
```

## Fonctionnalites

### Module io_utils

| Fonction | Description | Commande |
|----------|-------------|----------|
| ouvrir_fichier | Ouvre un fichier avec gestion d'erreur | - |
| fermer_fichier | Ferme un fichier avec gestion d'erreur | - |
| verif_et_recup_arg | Valide et recupere un argument CLI | - |

Tests : `bin/ouverture_fichier.exe`, `bin/lecture_fichier.exe`, `bin/ecriture_stdin.exe`

### Module util_string

| Fonction | Description | Commande |
|----------|-------------|----------|
| calcLength | Calcule la longueur d'une chaine | - |
| aff | Affiche une chaine sur stdout | - |
| copieFinChaine | Concatene c1 + c2 | - |
| copieDebutChaine | Concatene c2 + c1 | - |
| coupeStr | Extrait une sous-chaine | - |

Tests : `bin/manipulation_chaines.exe`
