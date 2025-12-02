#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "pixel.h"

using namespace std;

enum Direction { OUEST, EST, NORD, SUD, SOURCE, PUIT };

class Image
{
    private:

        Pixel* pixels;

        int hauteur;
        int largeur;

        float sigma;
        float alpha;

        int H; 

    public:
        // constructeur [string nom_fichier , flot sig , flot alp , flot h ] - ouvre une fichier nom_fochier de type png et le recopie dans la
        //structure Image  
        Image(const string& fichier, float sig, float alp, int h = 100);

        //destructeur - delete l`image de memoire
        ~Image();
        
        // fonctions get [] - return les valeurs prives de class Image
        int get_hauteur() const { return hauteur; }
        int get_largeur() const { return largeur; }
        int get_taille() const { return hauteur * largeur; }
        
        // fonction indice[entiers i ,j ] - convertir les coordonnes 2D en 1D 
        int indice(int i, int j) const { return i * largeur + j; }

        //fonction get_ligne [entier idx]  - return la ligne de coordonnes 
        int get_ligne(int idx) const { return idx / largeur; }

        //fonction get_colonne [entier idx]  - return la colonne de coordonnes 
        int get_colonne(int idx) const { return idx % largeur; }
        
        // fonctions get_pixel [entier inx] / [entiers i , j] - return le pixel depuis les coordonnes 1D / les coordonnes 2D
        Pixel& get_pixel(int idx) { return pixels[idx]; }
        Pixel& get_pixel(int i, int j) { return pixels[indice(i, j)]; }
        
        // fonctions a_voisin_[*] [entier idx] - return true s`il existe un voisin de pixel du coordonnes idx false sinon
        bool a_voisin_nord(int idx) const { return idx >= largeur; }
        bool a_voisin_sud(int idx) const { return idx < (hauteur - 1) * largeur; }
        bool a_voisin_ouest(int idx) const { return (idx % largeur) != 0; }
        bool a_voisin_est(int idx) const { return ((idx + 1) % largeur) != 0; }
        
        // fonctions voisin_[*] [ entier idx] - return les coordonnes de voisin [*]
        int voisin_nord(int idx) const;
        int voisin_sud(int idx) const;
        int voisin_ouest(int idx) const;
        int voisin_est(int idx) const;
        
        //fonction direction_opposee [direction d] - prend en parametres la direction et reteurn celle qui l`oppose [nord->sud , est->ouest ...]
        Direction direction_opposee(Direction d) const;
        
        // procedure calculer_capacites [] - calcule les capacites de pixels sur image par rapport de ses couleurs
        void calculer_capacites();

        //fonction capacite_entre_pixel [pixel idx1 idx2] - prend en parametres deux pixels et return la capacite entre eux
        unsigned int capacite_entre_pixels(int idx1, int idx2) const;

        //fonctions capacite_vers_[*] [entier idx] - calcule et return la capacite entre pixel et [*]
        unsigned int capacite_vers_source(int idx) const;
        unsigned int capacite_vers_puit(int idx) const;
        
        // procedure augmenter_flot [lien vers entier , lien vers direction , entier] - recherche le capacite minimale restant sur
        // l`image et augmonte la capacite des pixels a cette valeur
        void augmenter_flot(int* predecesseur, Direction* dir_pred, int idx_puit);

        // fonction chercher_chemin_ameliorant [lie vers entier pred , lien vers  direction dir_pred ] - return indexe de puit si la fontion est termine avec succes
        //cherche le chemain de src vers puit en ajoutant les coordonnes de pixexls avec asses de capacite dans predecesseur
        int chercher_chemin_ameliorant(int* predecesseur, Direction* dir_pred);

        //procedure calculer_flot_maximal [] - recherche les chemains et trouve le flot max
        void calculer_flot_maximal();
        
        // procedure binariser [] - binarise l`image - recherche tout les pixels qui sont axessibles depuis le src et change les coulers de pixels en noir(0) ou blanc(255) 
        void binariser();
        
        // procedure afficher [] - affiche l`image
        void afficher() const;

        //procedure sauvegarder [string nom_fichier] - lis la structure image et recopie les donnes dans image png
        void sauvegarder(const string& fichier) const;
        
        //constantes pour les indexel src et puit 
        static const int SOURCE_IDX = -1;
        static const int PUIT_IDX = -2;

        // procedure afficher_capacites [] - affiche les capacites de pixels de l`image
        void afficher_capacites() const;         
};

#endif