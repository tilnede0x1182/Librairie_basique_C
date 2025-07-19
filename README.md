# Utilitaires C – Lecture/Écriture et Manipulation de Chaînes de charactère

## Description
Ce projet regroupe plusieurs petits programmes en C destinés à illustrer la lecture et l’écriture de fichiers, ainsi que des fonctions de manipulation de chaînes.
Chaque programme (`Test1.1.c`, `Test1.2.c`, `Test1.c`) montre un cas d’usage simple : compter et afficher les lignes d’un fichier, copier l’entrée standard dans un fichier de résultat, ou tester l’ouverture d’un fichier.
Un module de traitement de chaînes (`Test2.c`, `UtilString.c`) fournit des fonctions pour calculer la longueur, afficher, concaténer et extraire des sous-chaînes.
L’ensemble illustre des bases de la programmation systèmes en C, avec gestion d’erreurs et allocation dynamique.

## Technologies et environnements
- **Langage :** C (norme C99/C11 compatible)
- **Compilateur :** GCC ≥ 4.8 (ou tout compilateur compatible C99)
- **Bibliothèques :** standard C (`stdio.h`, `stdlib.h`, `string.h`)
- **Système de fichiers :** POSIX/ANSI C (ouverture, lecture, écriture et fermeture via `fopen`, `fgets`, `fputs`, `fclose`)

## Fonctionnalités
- **Test1.1.c**
  - Vérification du nombre d’arguments et affichage d’un message d’usage
  - Ouverture en lecture d’un fichier dont le nom est passé en argument
  - Lecture ligne par ligne, affichage sur la sortie standard et comptage des lignes
  - Fermeture sécurisée du fichier avec gestion d’erreur

- **Test1.2.c**
  - Ouverture en écriture de `resultat.txt` (crée ou écrase)
  - Lecture de l’entrée standard jusqu’à la ligne `FIN\n` et écriture progressive dans le fichier
  - Fermeture du fichier avec message de confirmation

- **Test1.c**
  - Démonstration minimale d’ouverture de fichier en mode lecture (fichier `Sauvegarde`)
  - Gestion basique d’erreur d’ouverture

- **Test2.c** et **UtilString.c**
  - `calcLength(char *)` : calcule la longueur d’une chaîne (équivalent à `strlen`)
  - `aff(char *)` : affiche caractère par caractère puis un saut de ligne
  - `verif_et_recup_arg(...)` : extrait un argument de ligne de commande après vérification
  - `copieFinChaine(c1, c2, dest)` : concatène `c1` puis `c2` dans une nouvelle zone allouée
  - `copieDebutChaine(c1, c2, dest)` : idem, ordre inversé
  - `coupeStr(src, dest, x, y)` : copie la sous-chaîne `src[x..y-1]` dans `dest`

Chaque composant inclut une gestion simple des erreurs (vérification de retour de `fopen`, `fclose`, `malloc`) et illustre les principes de base de la manipulation de flux et de chaînes en C.
