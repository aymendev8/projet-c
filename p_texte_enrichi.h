#ifndef P_TEXTE_ENRICHI
#define P_TEXTE_ENRICHI

typedef enum e_mode{NORMAL, MAJUSCULE, MINUSCULE} t_mode;

//oui
void changer_mode(t_mode mode);
//oui
t_mode mode();
//oui
void ouvrir_bloc();
//oui
void fermer_bloc();
//oui
void indenter();
//oui
void desindenter();
//oui
int est_en_fin_de_ligne();
//oui
int est_au_debut_de_ligne();
//oui
void entamer_ligne();
//oui
void terminer_ligne();
//oui
void pucer();
//oui
void ecrire_mot(const char* mot);
//non
int peut_ecrire(int nb_caracteres);

#endif