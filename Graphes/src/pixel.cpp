#include <iostream>
#include "pixel.h"

using namespace std;

Pixel::Pixel()
{
    x = 0;
    y = 0;
    niveau_de_gris = 0;
    
    capacite_ouest = 0;
    capacite_est = 0;
    capacite_nord = 0;
    capacite_sud = 0;
    capacite_source = 0;
    capacite_puit = 0;
    
    flot_ouest = 0;
    flot_est = 0;
    flot_nord = 0;
    flot_sud = 0;
    flot_source = 0;
    flot_puit = 0;
}

Pixel::Pixel(unsigned int x1, unsigned int y1, unsigned char ndg)
{
    x = x1;
    y = y1;
    niveau_de_gris = ndg;
    
    capacite_ouest = 0;
    capacite_est = 0;
    capacite_nord = 0;
    capacite_sud = 0;
    capacite_source = 0;
    capacite_puit = 0;
    
    flot_ouest = 0;
    flot_est = 0;
    flot_nord = 0;
    flot_sud = 0;
    flot_source = 0;
    flot_puit = 0;
}

Pixel::~Pixel()
{
    // Rien à libérer
}

void Pixel::afficher_donnes_pixel()
{
    cout << "Pixel(" << x << "," << y << ") - niveau gris: " << (int)niveau_de_gris;
    cout << " Cap[O:" << capacite_ouest << " E:" << capacite_est;
    cout << " N:" << capacite_nord << " S:" << capacite_sud;
    cout << " Src:" << capacite_source << " Puit:" << capacite_puit << "]";
    cout << " Flot[O:" << flot_ouest << " E:" << flot_est;
    cout << " N:" << flot_nord << " S:" << flot_sud;
    cout << " Src:" << flot_source << " Puit:" << flot_puit << "]" << endl;
}