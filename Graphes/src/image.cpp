#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <algorithm>
#include "image.h"


using namespace std;

Image::Image(const string& fichier, float sig, float alp, int h) : sigma(sig), alpha(alp), H(h)
{
    ifstream file(fichier);
    if (!file.is_open())
    {
        cerr << "Erreur: impossible d'ouvrir " << fichier << endl;
        hauteur = 0;
        largeur = 0;
        pixels = nullptr;
        return;
    }
    
    string format;
    int max_val;
    
    file >> format;
    
    char c = file.peek();
    while (c == '#' || c == '\n' || c == ' ')
    {
        if (c == '#')
        {
            string ligne;
            getline(file, ligne);
        } else
        {
            file.get();
        }
        c = file.peek();
    }
    
    file >> largeur >> hauteur >> max_val;
    
    cout << "Chargement image: " << largeur << "x" << hauteur << endl;
    
    pixels = new Pixel[hauteur * largeur];
    
    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            int valeur;
            file >> valeur;
            int idx = indice(i, j);
            pixels[idx] = Pixel(i, j, (unsigned char)valeur);
        }
    }
    
    file.close();
    
    calculer_capacites();
}

Image::~Image()
{
    if (pixels != nullptr)
    {
        delete[] pixels;
    }
}


int Image::voisin_nord(int idx) const
{
    if (a_voisin_nord(idx)) 
    {
        return idx - largeur;
    }    

    return -1;
}


int Image::voisin_sud(int idx) const
{
    if (a_voisin_sud(idx))
    {
        return idx + largeur;
    }
    return -1;
}


int Image::voisin_ouest(int idx) const
{
    if (a_voisin_ouest(idx))
    {
        return idx - 1;
    }
    return -1;
}

int Image::voisin_est(int idx) const
{
    if (a_voisin_est(idx))
    {
        return idx + 1;
    }
    return -1;
}

Direction Image::direction_opposee(Direction d) const
{
    switch(d)
    {
        case OUEST: return EST;
        case EST: return OUEST;
        case NORD: return SUD;
        case SUD: return NORD;
        case SOURCE: return PUIT;
        case PUIT: return SOURCE;
    }

    return OUEST;
}


unsigned int Image::capacite_entre_pixels(int idx1, int idx2) const
{
    int diff = pixels[idx1].get_niveau_gris() - pixels[idx2].get_niveau_gris();

    double exposant = -(diff * diff) / (2.0 * sigma * sigma);
    double valeur = H * exp(exposant);

    return (unsigned int)lround(valeur);
}


unsigned int Image::capacite_vers_source(int idx) const
{
    double intensite = pixels[idx].get_niveau_gris();
    double valeur = -alpha * log((255.0000000001 - intensite) / 255.0000000002);

    return (unsigned int)lround(valeur);
}


unsigned int Image::capacite_vers_puit(int idx) const
{
    double intensite = pixels[idx].get_niveau_gris();
    double valeur = -alpha * log((0.0000000001 + intensite) / 255.0000000002);

    return (unsigned int)lround(valeur);
}


void Image::calculer_capacites()
{
    for (int idx = 0; idx < hauteur * largeur; idx++)
    {
        if (a_voisin_ouest(idx))
        {
            int voisin = voisin_ouest(idx);

            unsigned int cap = capacite_entre_pixels(idx, voisin);

            pixels[idx].set_capacite_ouest(cap);
        }
        
        if (a_voisin_est(idx))
        {
            int voisin = voisin_est(idx);

            unsigned int cap = capacite_entre_pixels(idx, voisin);

            pixels[idx].set_capacite_est(cap);
        }
        
        if (a_voisin_nord(idx))
        {
            int voisin = voisin_nord(idx);

            unsigned int cap = capacite_entre_pixels(idx, voisin);

            pixels[idx].set_capacite_nord(cap);
        }
        
        if (a_voisin_sud(idx))
        {
            int voisin = voisin_sud(idx);

            unsigned int cap = capacite_entre_pixels(idx, voisin);

            pixels[idx].set_capacite_sud(cap);
        }
        
        pixels[idx].set_capacite_source(capacite_vers_source(idx));
        pixels[idx].set_capacite_puit(capacite_vers_puit(idx));
    }
}



int Image::chercher_chemin_ameliorant(int* predecesseur, Direction* dir_pred)
{
    int taille_totale = hauteur * largeur + 2;

    bool* visite = new bool[taille_totale];
    
    for (int i = 0; i < taille_totale; i++)
    {
        visite[i] = false;
        predecesseur[i] = -3;
    }
    
    queue<int> file;

    int idx_source = hauteur * largeur;
    int idx_puit = hauteur * largeur + 1;
    
    file.push(idx_source);
    visite[idx_source] = true;
    
    bool puit_atteint = false;
    
    while (!file.empty() && !puit_atteint)
    {
        int courant = file.front();
        file.pop();
        // si dans souce 
        if (courant == idx_source)
        {
            for (int idx = 0; idx < hauteur * largeur; idx++)
            {
                unsigned int cap = pixels[idx].get_capacite_source();
                unsigned int flot = pixels[idx].get_flot_source();
                
                if (!visite[idx] && flot < cap)
                {
                    visite[idx] = true;
                    predecesseur[idx] = idx_source;
                    dir_pred[idx] = SOURCE;
                    file.push(idx);
                }
            }
        }
        // si sur pixel 
        else if (courant < hauteur * largeur) {
            
            unsigned int cap_puit = pixels[courant].get_capacite_puit();
            unsigned int flot_puit = pixels[courant].get_flot_puit();
            
            if (flot_puit < cap_puit) {
                predecesseur[idx_puit] = courant;
                dir_pred[idx_puit] = PUIT;
                puit_atteint = true;
                break;
            }
            
            // verification des voisins
            int voisins[4] = {voisin_nord(courant), voisin_sud(courant), voisin_est(courant), voisin_ouest(courant)};
            Direction dirs[4] = {NORD, SUD, EST, OUEST};

            unsigned int caps[4] = {pixels[courant].get_capacite_nord(), pixels[courant].get_capacite_sud(), pixels[courant].get_capacite_est(), pixels[courant].get_capacite_ouest()};
            unsigned int flots[4] = {pixels[courant].get_flot_nord(), pixels[courant].get_flot_sud(), pixels[courant].get_flot_est(), pixels[courant].get_flot_ouest()};
            
            for (int i = 0; i < 4; i++)
            {
                int voisin = voisins[i];
                if (voisin != -1 && !visite[voisin])
                {
                    unsigned int flot_retour = 0;
                    Direction dir_opp = direction_opposee(dirs[i]);
                    
                    switch(dir_opp)
                    {
                        case NORD: 
                            flot_retour = pixels[voisin].get_flot_nord(); 
                            break;

                        case SUD: 
                            flot_retour = pixels[voisin].get_flot_sud(); 
                            break;

                        case EST: 
                            flot_retour = pixels[voisin].get_flot_est(); 
                            break;

                        case OUEST: 
                            flot_retour = pixels[voisin].get_flot_ouest(); 
                            break;

                        default: 
                            break;
                    }
                    
                    unsigned int cap_residuelle = caps[i] - flots[i] + flot_retour;
                    
                    if (cap_residuelle > 0)
                    {
                        visite[voisin] = true;
                        predecesseur[voisin] = courant;
                        dir_pred[voisin] = dirs[i];
                        file.push(voisin);
                    }
                }
            }
        }
    }
    
    delete[] visite;
    
    return puit_atteint ? idx_puit : -1;
}



void Image::augmenter_flot(int* predecesseur, Direction* dir_pred, int idx_puit)
{
    // cherche flot min sur chemain
    unsigned int flot_min = 999999;
    int courant = idx_puit;
    int idx_source = hauteur * largeur;
    
    while (courant != idx_source)
    {
        int pred = predecesseur[courant];
        Direction dir = dir_pred[courant];
        
        unsigned int cap_residuelle = 0;
        
        if (pred == idx_source)
        {
            //src a pixel
            cap_residuelle = pixels[courant].get_capacite_source() - pixels[courant].get_flot_source();
        }
        else if (courant == idx_puit)
        {
            // pixel a puit
            cap_residuelle = pixels[pred].get_capacite_puit() -  pixels[pred].get_flot_puit();
        }
        else
        {
            // pixel a pixel
            unsigned int cap = 0, flot = 0, flot_retour = 0;
            
            switch(dir)
            {
                case NORD:
                    cap = pixels[pred].get_capacite_nord();
                    flot = pixels[pred].get_flot_nord();
                    flot_retour = pixels[courant].get_flot_sud();
                    break;

                case SUD:
                    cap = pixels[pred].get_capacite_sud();
                    flot = pixels[pred].get_flot_sud();
                    flot_retour = pixels[courant].get_flot_nord();
                    break;
                case EST:
                    cap = pixels[pred].get_capacite_est();
                    flot = pixels[pred].get_flot_est();
                    flot_retour = pixels[courant].get_flot_ouest();
                    break;

                case OUEST:
                    cap = pixels[pred].get_capacite_ouest();
                    flot = pixels[pred].get_flot_ouest();
                    flot_retour = pixels[courant].get_flot_est();
                    break;

                default:
                    break;
            }
            
            cap_residuelle = cap - flot + flot_retour;
        }
        
        flot_min = min(flot_min, cap_residuelle);
        courant = pred;
    }
    
    courant = idx_puit;
    
    while (courant != idx_source)
    {
        int pred = predecesseur[courant];
        Direction dir = dir_pred[courant];
        
        if (pred == idx_source)
        {
            // src a pixel
            pixels[courant].set_flot_source(pixels[courant].get_flot_source() + flot_min);
        }
        else if (courant == idx_puit)
        {
            // pixel a puit
            pixels[pred].set_flot_puit(pixels[pred].get_flot_puit() + flot_min);
        }
        else
        {
            // pixel a pixel
            unsigned int cap = 0, flot = 0;
            
            switch(dir)
            {
                case NORD:
                    cap = pixels[pred].get_capacite_nord();
                    flot = pixels[pred].get_flot_nord();
                    break;
                case SUD:
                    cap = pixels[pred].get_capacite_sud();
                    flot = pixels[pred].get_flot_sud();
                    break;
                case EST:
                    cap = pixels[pred].get_capacite_est();
                    flot = pixels[pred].get_flot_est();
                    break;
                case OUEST:
                    cap = pixels[pred].get_capacite_ouest();
                    flot = pixels[pred].get_flot_ouest();
                    break;
                default:
                    break;
            }
            
            unsigned int nouveau_flot = flot + flot_min;
            unsigned int excedent = 0;
            
            if (nouveau_flot > cap)
            {
                excedent = nouveau_flot - cap;
                nouveau_flot = cap;
            }
            
            // mis a jout les flot
            switch(dir)
            {
                case NORD:
                    pixels[pred].set_flot_nord(nouveau_flot);
                    
                    if (excedent > 0)
                    {
                        pixels[courant].set_flot_sud(pixels[courant].get_flot_sud() - excedent);
                    } 

                    break;
                case SUD:
                    pixels[pred].set_flot_sud(nouveau_flot);

                    if (excedent > 0)
                    {
                        pixels[courant].set_flot_nord(pixels[courant].get_flot_nord() - excedent);
                    }

                    break;
                case EST:
                    pixels[pred].set_flot_est(nouveau_flot);

                    if (excedent > 0)
                    {
                        pixels[courant].set_flot_ouest(pixels[courant].get_flot_ouest() - excedent);
                    }

                    break;
                case OUEST:
                    pixels[pred].set_flot_ouest(nouveau_flot);

                    if (excedent > 0)
                    {
                        pixels[courant].set_flot_est(pixels[courant].get_flot_est() - excedent);
                    }

                    break;
                default:
                    break;
            }
        }
        
        courant = pred;
    }
}



void Image::calculer_flot_maximal()
{
    int taille_totale = hauteur * largeur + 2;
    int* predecesseur = new int[taille_totale];

    Direction* dir_pred = new Direction[taille_totale];
    
    int nb_iterations = 0;
    int idx_puit;
        
    while ((idx_puit = chercher_chemin_ameliorant(predecesseur, dir_pred)) != -1)
    {
        augmenter_flot(predecesseur, dir_pred, idx_puit);
        nb_iterations++;
        
        if (nb_iterations % 1000 == 0)
        {
            cout << "Iteration " << nb_iterations << endl;
        }
    }
    
    cout << "Flot maximal atteint en " << nb_iterations << " iterations" << endl;
    
    delete[] predecesseur;
    delete[] dir_pred;
}




void Image::binariser()
{
    //parcours depuis le source
    int taille_totale = hauteur * largeur + 2;

    bool* connecte_source = new bool[taille_totale];
    
    for (int i = 0; i < taille_totale; i++)
    {
        connecte_source[i] = false;
    }
    
    queue<int> file;
    int idx_source = hauteur * largeur;
    
    file.push(idx_source);
    connecte_source[idx_source] = true;
    
    while (!file.empty()) 
    {
        int courant = file.front();
        file.pop();
        
        if (courant == idx_source)
        {
            // exploration de tous les pixels depuis src
            for (int idx = 0; idx < hauteur * largeur; idx++)
            {
                unsigned int cap = pixels[idx].get_capacite_source();
                unsigned int flot = pixels[idx].get_flot_source();
                
                if (!connecte_source[idx] && flot < cap)
                {
                    connecte_source[idx] = true;
                    file.push(idx);
                }
            }
        }
        else
        {
            // explorer les voisins
            int voisins[4] = {voisin_nord(courant), voisin_sud(courant), voisin_est(courant), voisin_ouest(courant)};

            unsigned int caps[4] = {pixels[courant].get_capacite_nord(), pixels[courant].get_capacite_sud(), pixels[courant].get_capacite_est(), pixels[courant].get_capacite_ouest()};
            unsigned int flots[4] = {pixels[courant].get_flot_nord(), pixels[courant].get_flot_sud(), pixels[courant].get_flot_est(), pixels[courant].get_flot_ouest()};
            
            for (int i = 0; i < 4; i++)
            {
                int voisin = voisins[i];

                if (voisin != -1 && !connecte_source[voisin] && flots[i] < caps[i])
                {
                    connecte_source[voisin] = true;
                    file.push(voisin);
                }
            }
        }
    }
    
    // cinariser l`image
    for (int idx = 0; idx < hauteur * largeur; idx++)
    {
        if (connecte_source[idx])
        {
            pixels[idx].set_niveau_gris(0);  // en noir
        } 
        else
        {
            pixels[idx].set_niveau_gris(255);  // en blanc
        }
    }
    
    delete[] connecte_source;
}



void Image::afficher() const
{
    cout << "Image " << largeur << "x" << hauteur << endl;
    for (int i = 0; i < min(5, hauteur); i++)
    {
        for (int j = 0; j < min(10, largeur); j++)
        {
            cout << (int)pixels[indice(i, j)].get_niveau_gris() << " ";
        }
        cout << endl;
    }
}

void Image::sauvegarder(const string& fichier) const
{
    ofstream file(fichier);
    if (!file.is_open())
    {
        cerr << "Erreur: impossible de sauvegarder " << fichier << endl;
        return;
    }
    
    file << "P2" << endl;
    file << largeur << " " << hauteur << endl;  
    file << "255" << endl;
    
    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            file << (int)pixels[indice(i, j)].get_niveau_gris();
            if (j < largeur - 1) file << " ";
        }
        file << endl;
    }
    
    file.close();
    cout << "Image sauvegardee dans " << fichier << endl;
}



void Image::afficher_capacites() const
{
    cout << largeur << " " << hauteur << endl;

    int total_pixels = largeur * hauteur;

    cout << total_pixels << endl;
    
    for (int idx = 0; idx < total_pixels; idx++)
    {
        cout << pixels[idx].get_capacite_source() << " ";
        cout << pixels[idx].get_capacite_puit() << " ";
        cout << pixels[idx].get_capacite_nord() << " ";
        cout << pixels[idx].get_capacite_sud() << " ";
        cout << pixels[idx].get_capacite_est() << " ";
        cout << pixels[idx].get_capacite_ouest();
        
        cout << endl;
    }
}