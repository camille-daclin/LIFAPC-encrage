#include<iostream>
#include"pixel.h"

using namespace std;


Pixel::Pixel()
{
    x = 1000;
    y = 1000;
    niveau_de_gris = 0;
    ouest = 1000;
    est = 1000;
    nord = 1000;
    sud = 1000;
}

Pixel::Pixel(unsigned int x1, unsigned int y1, unsigned char ndg)
{
    x = x1;
    y = y1;
    niveau_de_gris = ndg;
    this->remplir_voisins_pixel();
}

Pixel::~Pixel()
{
    //pas de pointeurs sur tas donc destr. ne fait rien
}



void Pixel::remplir_couleur_pixel(unsigned char ndg)
{
    niveau_de_gris = ndg;
}


void Pixel::remplir_voisins_pixel()
{
    if(x != 1000 && y != 1000)
    {
        ouest = x - 1;
        est = x + 1;
        nord = y - 1;
        sud = y + 1;     
    }
}


void Pixel::remplir_coordonnes(unsigned int x1 , unsigned int y1)
{
    x = x1; 
    y = y1;
    this->remplir_voisins_pixel();
}


void Pixel::refair_pixel(unsigned char ndg, unsigned int x1 , unsigned int y1)
{
    niveau_de_gris = ndg;
    this->remplir_coordonnes(x1, y1);
    this->remplir_voisins_pixel();
}

void Pixel::operator =(Pixel pix)
{
    niveau_de_gris = pix.niveau_de_gris;
    x = pix.x;
    y = pix.y;
    this->remplir_voisins_pixel();
}

bool Pixel::operator ==(Pixel pix)
{
    if(niveau_de_gris == pix.niveau_de_gris && x == pix.x && y == pix.y)
    {
        return true;
    }else
    {
        return false;
    }
}

bool Pixel::verifier_voisines(Pixel pix)
{
    if((x = pix.x && nord == pix.y) || (x = pix.x && sud == pix.y) || (ouest = pix.x && y == pix.y) || (est = pix.x && y == pix.y))
    {
        return true;
    }
    return false;
}


void Pixel::changer_capacite_ouest(unsigned int cap_ou)
{
    capacite_ouest = cap_ou;
}

void Pixel::changer_capacite_est(unsigned int cap_es)
{
    capacite_est = cap_es;
}

void Pixel::changer_capacite_nord(unsigned int cap_no)
{
    capacite_nord = cap_no;
}

void Pixel::changer_capacite_sud(unsigned int cap_su)
{
    capacite_sud = cap_su;
}




void Pixel::changer_flot_ouest(unsigned int flot_ou)
{
    flot_ouest = flot_ou;
}

void Pixel::changer_flot_est(unsigned int flot_es)
{
    flot_est = flot_es;
}

void Pixel::changer_flot_nord(unsigned int flot_no)
{
    flot_nord = flot_no;
}

void Pixel::changer_flot_sud(unsigned int flot_su)
{
    flot_sud = flot_su;
}


void Pixel::afficher_donnes_pixel()
{
    cout << "couleur: " << niveau_de_gris << "; x: " << x << "; y: "<< y << " voisins: ";
    cout <<"Nord(" << nord << "," << y <<") ";
    cout <<"Sud(" << sud << "," << y <<") ";
    cout <<"Est(" << x << "," << est <<") ";
    cout <<"Ouest(" << x << "," << ouest <<") "<<endl; 
}




void Pixel::test_fonctionement_pixel()
{
    Pixel p1;
    Pixel p2(10,11,124);
    p1.afficher_donnes_pixel();
    p2.afficher_donnes_pixel();

    p1.remplir_couleur_pixel(224);
    p1.afficher_donnes_pixel();
    p1.remplir_coordonnes(10,12);
    p1.afficher_donnes_pixel();

    p1.refair_pixel(44,43,11);
    p1.afficher_donnes_pixel();

    Pixel p3;
    p3 = p2;
    if(p3 == p2)
    {
        p3.afficher_donnes_pixel();
    }
    if(p1.verifier_voisines(p2))
    {
        cout << "p1 et p2 voisins";
    }
}
