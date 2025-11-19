#include <iosteam>
#include "image.h"

Image::Image
//Destructeur on enlève tout les pixels chargés dans le graphe
Graph::~Graph(){
    delete pixel;
}

int Graph::get_global(){
    
}

int Graph::get_nord(int i){
    if (i < image->largeur)
        return -1;
    return i - image->largeur;
}

int Graph::get_sud(int i){
    if (i>image->largeur *(image->hauteur-1)-1)
        return -1;
    return i+image->largeur;
}

int Graph::get_est(int i){
    if (((i+1) % image->largeur)==0)
        return -1;
    return i+1;
}

int Graph::get_ouest(int i){
    if ((i+image->largeur) % image->largeur == 0)
        return -1
    return i-1;
}
