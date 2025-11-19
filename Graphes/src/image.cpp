#include <iosteam>
#include <cmath>
#include "image.h"

Image::Image(const *string im){

}

Graph::Graph(Image im, float a, float b){
    int indice;
    image = new Image (im);
    p = new pixel[im.hauteur * im.largeur];
    for (int i=0, i< im.hauteur, i++){
        for (int j = 0, j< im.largeur, j++){
            indice =
        }
    }
}

//Destructeur on enlève tout les pixels chargés dans le graphe
Graph::~Graph(){
    delete pixel;
}

int Graph::get_valuation(pixel *p, pixel *q){
    float a,b;
    a = pow(p->capacite - q->capacite,2);
    b = 2 * pow(p->ndg,2);
    return a + b;   
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

void Graph::afficher(){

}