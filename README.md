# Projet LIFAPC :  Encrage d'images en noir et blanc

[Enoncé du Projet](https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAPC/tp09Encrage.pdf)

**👨‍💻KUDRENKO Pavlo & DACLIN Camille**  
*3 Décembre 2025 - LIFAPC*

---

## 🎯 Objectif du projet

On transforme une image en niveaux de gris en noir et blanc. Pour ça onn utilise un algorithme de flot maximal sur un graphe
pour que l'algo tienne compte du contexte local de chaque pixel.

Pour faire simple : un pixel gris sera noir ou blanc selon ce qu'il y a autour de lui,
pas juste selon sa valeur absolue.

---

## 🚀 Compilation & Installation

`make`           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; : Compile tout  
`make clean `     &nbsp;:  Supprime les fichiers objets (.o)


---

## ⚙️ Utilisation

### Ligne de commande

`./bin/encrage test.ascii.pgm resultat_test.pgm 30 2.0 100`       
`./bin/encrage baboon.reduced.pgm resultat_baboon.pgm 5 400 100`


### Avec Make

`make test` : Test rapide (4x4 pixels)   
`make baboon` : Test sur baboon (128x128)


### Paramètres



- contraste local 
- pondération source/puit
- discrétisation (on y laisse toujours à 100)
---

## 📈 Performances obtenues

- test.pgm (4x4) :  
  - 9 itérations    
  - < 1 seconde


- baboon.reduced.pgm (128x128) :   
  - 18 054 itérations   
  - quelques secondes



**Note : Le sujet parle d'un nombre d'itérations plus élevé mais c'est pour une image plus
grande. Avec l'image baboon.pgm qu'on a ça marche bien.**
****
---

## 📁 Organisation du projet

 
src/   
  pixel.h / pixel.cpp     &nbsp;&nbsp;&nbsp;&nbsp;: Gère un pixel    
  image.h / image.cpp     : Charge l'image, fait les calculs, algo de flot    
  main.cpp               &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; : Lance tout


bin/                      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Là où ça compile (fichiers .o)


Makefile                  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Pour compiler


test.ascii.pgm            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Petite image test   
baboon.reduced.pgm        : Image baboon



---

## 🔬 Comment ça marche

1. Chargement de l’image en format PGM ASCII 
2. Transformation de chaque pixel en un nœud dans un graphe
3. Calcul des capacités des arcs selon la ressemblance locale des pixels
4. Passage d’un flot maximal de la source (noir) vers le puits (blanc)
5. Calcul du flot maximal avec l’algorithme Ford-Fulkerson
6. Conclusion : pixels connectés à la source → noir, pixels restants → blanc


---

## ⚠️ Points techniques délicats

- Gestion des arcs retour et excédents lors de l’augmentation du flot
- Traitement spécial pour les pixels en bord de l’image (car ils ont moins de voisins)
- Le debug sur grandes images est long

---

## 🚀 Améliorations possibles

- Parallélisation pour accélérer les calculs
- Interface graphique pour visualiser le flot en temps réel
- Support du format PGM binaire (seulement ASCII pour l’instant)

---

## 🖥️ Environnement de test

- Machine personnelle  
- Sous Linux
- Compilateur g++ (sans bibliothèques externes)

---

**👨‍💻 Pavlo KUDRENKO & Camille DACLIN**  
*Projet TP9 - LIFAPC 2025*
