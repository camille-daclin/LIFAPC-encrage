#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
    private:
        // Couleur du pixel
        unsigned char niveau_de_gris;
        
        // Coordonnées du pixel
        unsigned int x;
        unsigned int y;
        
        // Capacités vers les 4 voisins
        unsigned int capacite_ouest;
        unsigned int capacite_est;
        unsigned int capacite_nord;
        unsigned int capacite_sud;
        
        // Flots vers les 4 voisins
        unsigned int flot_ouest;
        unsigned int flot_est;
        unsigned int flot_nord;
        unsigned int flot_sud;
        
        // Capacités pour la source et le puit
        unsigned int capacite_source;
        unsigned int capacite_puit;
        // Capacités pour la source et le puit
        unsigned int flot_source;
        unsigned int flot_puit;

    public:
        // Constructeurs et destructeur
        Pixel();
        Pixel(unsigned int x1, unsigned int y1, unsigned char ndg);
        ~Pixel();
        
        //procedure get_niveau_gris [ne prend rien en parametre] et retourne le niveau de gris du pixel
        unsigned char get_niveau_gris() const 
        { 
            return niveau_de_gris; 
        }

        //procedure get [ne prend rien en parametre] et retourne les coordonnées horizontale x ou y du pixel
        unsigned int get_x() const 
        { 
            return x; 
        }
        unsigned int get_y() const 
        { 
            return y; 
        }
        

        //procedure get_capacite [rien en paramètre] zt retourne la capacité de l'arc vers le pixel ouest/est/nord/sud
        unsigned int get_capacite_ouest() const
        {
             return capacite_ouest; 
        }
        unsigned int get_capacite_est() const 
        {
             return capacite_est; 
        }
        unsigned int get_capacite_nord() const 
        {
             return capacite_nord; 
        }
        unsigned int get_capacite_sud() const 
        {
             return capacite_sud; 
        }

        //procedure get_capacite(source/puit) [rien en paramètre] et retourne la capacité de 
        //l'arc depuis la source (encre noire) ou le puit (blanc)
        unsigned int get_capacite_source() const 
        {
             return capacite_source; 
        }
        unsigned int get_capacite_puit() const 
        {
             return capacite_puit; 
        }

        //procedure get_flot [rien en paramètre] et retourne le flot actuel vers le pixel ouest/est/nord ou sud
        unsigned int get_flot_ouest() const 
        {
             return flot_ouest; 
        }
        unsigned int get_flot_est() const 
        {
             return flot_est; 
        }
        unsigned int get_flot_nord() const 
        {
             return flot_nord; 
        }
        unsigned int get_flot_sud() const 
        {
             return flot_sud; 
        }

        //procedure get_flot(source ou puit) [rien en paramètre] et retourne le flot reçu depuis la source ou le puit
        unsigned int get_flot_source() const 
        {
             return flot_source; 
        }
        unsigned int get_flot_puit() const 
        {
             return flot_puit; 
        }
 
        //procedure set_capacite [unsigned int cap] et fixe la capacité vers le pixel ouest/est/ nord ou sud
        void set_capacite_ouest(unsigned int cap) 
        { 
            capacite_ouest = cap; 
        }
        void set_capacite_est(unsigned int cap) 
        { 
            capacite_est = cap; 
        }
        void set_capacite_nord(unsigned int cap) 
        { 
            capacite_nord = cap; 
        }
        void set_capacite_sud(unsigned int cap) 
        { 
            capacite_sud = cap; 
        }

        //procedure set_capacite(source ou puit) [unsigned int cap] et fixe la capacité depuis la source/puit
        void set_capacite_source(unsigned int cap) 
        { 
            capacite_source = cap; 
        }
        void set_capacite_puit(unsigned int cap) 
        { 
            capacite_puit = cap; 
        }
        
        //procedure set_flot [unsigned int f] et met à jour le flot vers le pixel ouest/est/nord ou sud
        void set_flot_ouest(unsigned int f) 
        { 
            flot_ouest = f; 
        }
        void set_flot_est(unsigned int f) 
        {
             flot_est = f; 
        }
        void set_flot_nord(unsigned int f) 
        {
             flot_nord = f; 
        }
        void set_flot_sud(unsigned int f) 
        {
             flot_sud = f; 
        }

        //procedure set_flot [unsigned int f] et met à jour le flot envoyé à la source/puit
        void set_flot_source(unsigned int f) 
        { 
            flot_source = f; 
        }
        void set_flot_puit(unsigned int f) 
        {
             flot_puit = f; 
        }
        //procedure set_niveau_gris [unsigned char ndg] et change la couleur du pixel
        void set_niveau_gris(unsigned char ndg) 
        { 
            niveau_de_gris = ndg; 
        }
        //procedure afficher_donnes_pixel [rien en parametre] et affiche toutes les informations du pixel 
        void afficher_donnes_pixel();
};

#endif