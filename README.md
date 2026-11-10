# my_ls

Ce projet a été codé entièrement à la main, sans aucun outil d'intelligence artificielle.
Ce README a en revanche été rédigé avec l'aide d'une intelligence artificielle.

## Le projet en quelques mots

my_ls est une reprise de la commande `ls` des systèmes Unix, écrite en langage C dans le cadre de ma formation à Epitech. Comme l'originale, elle affiche le contenu d'un ou plusieurs dossiers : lancée sans argument, elle liste le dossier courant, et quand on lui donne plusieurs chemins, elle affiche chaque dossier précédé de son nom. Si un chemin n'existe pas, elle écrit un message d'erreur et renvoie le code 84, tout en continuant avec les autres chemins.

Le programme lit les dossiers avec `opendir` et `readdir`, et utilise `stat` pour savoir si un chemin est un fichier ou un dossier. Toutes les fonctions d'affichage et de manipulation de chaînes (afficher un texte, un nombre, copier ou comparer des chaînes) sont recodées à la main dans le dossier `src/lib`, sans passer par `printf` ni par les fonctions de `string.h`.

Le code est réparti entre `main.c`, qui lance le programme, `flags.c`, qui lit les options passées en argument, `get_files.c`, qui récupère le contenu des dossiers, et `display_dir.c`, qui s'occupe de l'affichage. Les signatures des fonctions sont regroupées dans `include/my.h`, et la compilation passe par un Makefile.

## Options

• `-a` : affiche aussi les fichiers cachés, ceux dont le nom commence par un point
• `-R` : parcourt les sous dossiers les uns après les autres, en affichant le chemin de chacun
• `-d` : affiche le dossier lui même au lieu de son contenu

Les options peuvent être combinées, par exemple `-aR`.

## Comment le lancer

Il faut un compilateur C. Le Makefile utilise clang.

1. Récupérer le dépôt :

```bash
git clone https://github.com/PetitJump/my_ls.git
```

2. Compiler le projet :

```bash
cd my_ls && make
```

3. Lancer le programme :

```bash
./my_ls -a src
```

Le Makefile propose aussi `make clean` pour supprimer les fichiers intermédiaires, `make fclean` pour tout nettoyer y compris l'exécutable, et `make re` pour recompiler entièrement.
