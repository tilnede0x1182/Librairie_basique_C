~/code/tilnede0x1182/Personnel/2025/Entrainement/projet_fac/Analyseur-syntaxique-2013 ^ main
% tree
.
├── A_faire.md
├── bin
│   ├── ecriture_stdin.exe
│   ├── lecture_fichier.exe
│   ├── manipulation_chaines.exe
│   └── ouverture_fichier.exe
├── build
├── claude.md
├── Makefile
├── Projet.txt
├── README.md
├── Sauvegarde.txt
├── src
│   ├── C
│   │   ├── ecriture_stdin.c
│   │   ├── lecture_fichier.c
│   │   ├── manipulation_chaines.c
│   │   ├── ouverture_fichier.c
│   │   └── Utilitaire
│   │       ├── io_utils.c
│   │       └── UtilString.c
│   └── Headers
│       └── Utilitaire
│           ├── io_utils.h
│           └── util_string.h
└── test_ecriture.txt

8 directories, 19 files

A faire :

faire en sorte que le compileaiotn ztle simpr suivez la jovelle sutcure du repo

il avant de faire quoi que c esoit il faut detmerin ce que font le sifhcir et si ce sont des version succs uves dun me truc ou de sutc diffrenbte, aussi les tets js ne sont pas des vria test -> faudra sans doute ld smodifie qu'u pur qile tes vraoment des truc, mais je les gards (le test js) parc equ'il
est uune liste posienteillement de truc peritnent à tester -> à vierfier

1. Makefile : La cible run doit compiler puis exécuter chaque exercice dans l'ordre :
- ouverture_fichier
- lecture_fichier
- ecriture_stdin
- manipulation_chaines
2. Refactor des exercices : Chaque fichier exercice devient un test qui :
- Teste chaque fonction du module utilisé
- Affiche les résultats en console (pass/fail ou valeurs)
- Résultat : make run = suite de tests complète
3. Refactor section 36 sur tous les fichiers C et H :
- src/C/Utilitaire/io_utils.c
- src/C/Utilitaire/UtilString.c
- src/Headers/Utilitaire/io_utils.h
- src/Headers/Utilitaire/util_string.h
- src/C/ouverture_fichier.c
- src/C/lecture_fichier.c
- src/C/ecriture_stdin.c
- src/C/manipulation_chaines.c

Contraintes section 36 :
- Sections avec séparateurs ==== et ----
- Fonctions ≤ 15 lignes
- Javadoc AVANT chaque fonction
- Noms variables ≥ 2 caractères
- Tabulations uniquement
- Sous-sections tous les ~50 lignes
