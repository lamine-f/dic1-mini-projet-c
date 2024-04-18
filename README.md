# Analyse et Évaluation d'Expressions Arithmétiques

## Description

Le programme prend en entrée des expressions arithmétiques, vérifie leur syntaxe selon une grammaire définie et évalue leur résultat si la syntaxe est correcte. Il prend en charge les opérations d'addition, de soustraction, de multiplication et de division, ainsi que les parenthèses pour définir la priorité des opérations.

## Structure du Projet

Le projet est organisé selon la structure suivante :

- `bin/`: Contient les exécutables générés après la compilation du programme.
- `src/`: Contient les fichiers sources du programme écrits en langage C.
- `includes/`: Contient les fichiers d'en-tête (`.h`) nécessaires pour déclarer les prototypes de fonctions et les structures de données.

## Compilation et Exécution sous linux

Pour compiler le programme, vous pouvez utiliser un compilateur C tel que GCC en exécutant la commande suivante dans votre terminal :

```bash
gcc src/*.c -o bin/arithmetic-resolver
./bin/arithmetic-resolver
```
Ou bien utiliser l'utilitaire make:

```bash
make
```