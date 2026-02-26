# À faire

## 1. Compréhension rapide

-   `Test1.1.c` lit un fichier passé en argument, affiche chaque ligne et comptabilise le total avant de fermer proprement le flux.
-   `Test1.2.c` enregistre l’entrée standard dans `resultat.txt` jusqu’au mot-clé `FIN`, ce qui sert de petit utilitaire de saisie.
-   `Test1.c` vérifie juste la capacité à ouvrir un fichier de sauvegarde et sert de squelette minimal.
-   `Test2.c` expose des fonctions de manipulation de chaînes (calcul de longueur, concaténation, découpe) et une démonstration dans `main`.
-   `UtilString.c` double certaines de ces fonctions pour mutualiser la logique de calcul de longueur et d’affichage caractère par caractère.
-   Les fichiers `projet.txt`, `Sauvegarde.txt` et `resultat.txt` fournissent des données d’essai pour vérifier lecture/écriture.

## 2. Bugs à corriger

-   `Test2.c::copieFinChaine` et `copieDebutChaine` allouent `malloc((cmp1+cmp2)*sizeof(char))` puis écrivent un `\0` hors tampon ; prévoir `cmp1+cmp2+1` et vérifier le retour de `malloc` avant copie.
-   `Test2.c::coupeStr` écrit dans `c2` passé par adresse mais jamais alloué dans `main` (`char *c4;`/`*c5` restent `NULL`), d’où un segfault ; soit allouer côté appelant, soit laisser la fonction réalouer et retourner le nouveau pointeur.
-   `Test1.2.c` ignore la valeur de retour de `fgets` : en fin de flux `ligne_lue` garde l’ancien contenu et la boucle peut réécrire la dernière ligne indéfiniment ; il faut arrêter quand `fgets` renvoie `NULL`.
-   `Test2.c::verif_et_recup_arg` fait un `strcpy` vers `chaine` sans vérifier la taille réelle de l’argument, ce qui écrase facilement la pile pour des chemins longs ; utiliser `strncpy`/`snprintf` et limiter la longueur.

## 3. DRY en priorité

-   Les trois programmes `Test1.c`, `Test1.1.c` et `Test1.2.c` recopièrent la même séquence d’ouverture/fermeture de fichier et de messages d’erreur. Créer une fonction utilitaire `FILE *ouvrir(const char *nom, const char *mode)` partagée ou un header commun permettrait de factoriser ces blocs identiques.
-   Les boucles qui recalculent la longueur des chaînes dans `Test2.c` et `UtilString.c` dupliquent `calcLength`. Utiliser systématiquement `calcLength` (ou `strlen`) éviterait d’entretenir plusieurs implémentations de la même logique.

## 4. Sécurité

-   Toute la chaîne de lecture utilise `strcpy`, `printf` avec des chaînes issues de l’utilisateur et `malloc` sans vérification ; il faut systématiser des versions sûres (p. ex. `fgets` + vérification de taille, `snprintf`) pour éviter débordements et lectures indéfinies.
-   `Test1.2.c` écrit directement ce que l’utilisateur tape dans `resultat.txt` sans nettoyage, ce qui peut injecter des séquences de contrôle ; prévoir une étape d’échappement si le fichier est réinterprété ailleurs.
