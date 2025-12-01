#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "pixel.h"

using namespace std;

enum Direction { OUEST, EST, NORD, SUD, SOURCE, PUIT };

class Image {
private:
    Pixel* pixels;
    int hauteur;
    int largeur;
    float sigma;
    float alpha;
    int H; // Paramètre pour discrétisation des capacités

public:
    // Constructeurs
    Image(const string& fichier, float sig, float alp, int h = 100);
    ~Image();
    
    // Accesseurs
    int get_hauteur() const { return hauteur; }
    int get_largeur() const { return largeur; }
    int get_taille() const { return hauteur * largeur; }
    
    // Conversion coordonnées <-> indice
    int indice(int i, int j) const { return i * largeur + j; }
    int get_ligne(int idx) const { return idx / largeur; }
    int get_colonne(int idx) const { return idx % largeur; }
    
    // Accès aux pixels
    Pixel& get_pixel(int idx) { return pixels[idx]; }
    Pixel& get_pixel(int i, int j) { return pixels[indice(i, j)]; }
    
    // Vérification des voisins
    bool a_voisin_nord(int idx) const { return idx >= largeur; }
    bool a_voisin_sud(int idx) const { return idx < (hauteur - 1) * largeur; }
    bool a_voisin_ouest(int idx) const { return (idx % largeur) != 0; }
    bool a_voisin_est(int idx) const { return ((idx + 1) % largeur) != 0; }
    
    // Obtenir les indices des voisins (-1 si inexistant)
    int voisin_nord(int idx) const;
    int voisin_sud(int idx) const;
    int voisin_ouest(int idx) const;
    int voisin_est(int idx) const;
    
    // Direction opposée
    Direction direction_opposee(Direction d) const;
    
    // Calcul des capacités
    void calculer_capacites();
    unsigned int capacite_entre_pixels(int idx1, int idx2) const;
    unsigned int capacite_vers_source(int idx) const;
    unsigned int capacite_vers_puit(int idx) const;
    
    // Gestion du flot
    void augmenter_flot(int* predecesseur, Direction* dir_pred, int idx_puit);
    int chercher_chemin_ameliorant(int* predecesseur, Direction* dir_pred);
    void calculer_flot_maximal();
    
    // Binarisation finale
    void binariser();
    
    // Affichage et sauvegarde
    void afficher() const;
    void sauvegarder(const string& fichier) const;
    
    // Constantes pour la source et le puit
    static const int SOURCE_IDX = -1;
    static const int PUIT_IDX = -2;

    // Affichage des capacités (pour debug/vérification)
    void afficher_capacites() const;         
};

#endif