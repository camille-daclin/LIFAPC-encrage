================================================================================
**Projet TP9 - Encrage d'image en noir et blanc**
============================================================================

Binôme : KUDRENKO Pavlo & DACLIN Camille
 3 Décembre 2025 - LIFAPC

================================================================================
But du projet :
================================================================================

On transforme une image en niveaux de gris en noir et blanc. Pour ça onn utilise un algorithme de flot maximal sur un graphe
pour que l'algo tienne compte du contexte local de chaque pixel.

En gros : un pixel gris sera noir ou blanc selon ce qu'il y a autour de lui,
pas juste selon sa valeur absolue.

================================================================================
COMMENT COMPILER
================================================================================

    make            # Compile tout
    make clean      # Vire les .o

================================================================================
COMMENT UTILISER
================================================================================

Soit on utilise la commande de base :

    ./bin/encrage test.ascii.pgm resultat_test.pgm 30 2.0 100

    ./bin/encrage baboon.reduced.pgm resultat_baboon.pgm  5 400 100

Soit avec "make"  :

    make test       # Test rapide sur petite image (4x4 pixels)
    make baboon     # Test sur baboon (128x128)


Paramètres :
  - contraste local 
  - pondération source/puit
  - discrétisation (on y laisse à 100)

================================================================================
CE QU'ON A OBTENU
================================================================================

test.pgm (4x4) :
  - 9 itérations
  - < 1 seconde

baboon.reduced.pgm (128x128) :
  - 18 054 itérations
  - quelques secondes


Note : Le sujet parle d'un nombre d'itérations plus élevé mais c'est pour une image plus
grande. Avec l'image baboon.pgm qu'on a ça marche bien.

================================================================================
ORGANISATION :
================================================================================

src/
  pixel.h / pixel.cpp     : Gère un pixel 
  image.h / image.cpp     : Charge l'image, fait les calculs, algo de flot
  main.cpp                : Lance tout

bin/                      : Là où ça compile (fichiers .o)

Makefile                  : Pour compiler

test.ascii.pgm            : Petite image test
baboon.reduced.pgm        : Image baboon

================================================================================
COMMENT ÇA MARCHE
================================================================================

1. On charge l'image en PGM
2. On transforme chaque pixel en nœud d'un graphe
3. On calcule des "capacités" entre les pixels selon leur ressemblance
4. On fait passer un "flot" de la source (encre noire) au puit (poubelle)
5. On cherche le flot maximum avec Ford-Fulkerson 
6. À la fin, les pixels connectés à la source → noir, les autres → blanc

================================================================================
LES POINTS PLUS COMPLIQUES :
================================================================================

- Comprendre la gestion de l'excédent quand on augmente le flot (arc retour)
- Les pixels sur les bords ont moins de voisins → faut vérifier avant d'accéder
- Le format PGM c'est largeur PUIS hauteur (on s'est fait avoir)
- Débugger avec 16384 pixels c'est long

================================================================================
AMÉLIORATIONS POSSIBLES :
================================================================================

- Paralléliser les calculs
- Faire une interface pour voir le flot en direct
- Support du PGM binaire (on a fait que ASCII)

================================================================================
TESTÉ AVEC :
================================================================================

Machine personelle
Linux (salles TP), g++
Pas de bibliothèques externes

================================================================================