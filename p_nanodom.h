#ifndef P_NANODOM_H
#define P_NANODOM_H

typedef enum e_token
{
    DOCUMENT = 0,
    ANNEXE = 1,
    SECTION = 2,
    TITRE = 3,
    LISTE = 4,
    ITEM = 5,
    IMPORTANT = 6,
    RETOUR_A_LA_LIGNE = 7,
    MOT = 8
} t_token;

const char *t_token_image(t_token ceci);

typedef enum e_parente
{
    PERE = 0,
    PREMIER_FILS = 1,
    DERNIER_FILS = 2,
    GRAND_FRERE = 3,
    PETIT_FRERE = 4,
    NB_PARENTES = 5
} t_parente;

const char *t_parente_image(t_parente ceci);

typedef struct s_noeud
{
    t_token l_etiquette;
    const char *le_contenu;
    struct s_noeud *les_parentes[NB_PARENTES];
} t_noeud;
typedef t_noeud *p_noeud;
typedef p_noeud t_arbre_nanodom;

void creer_noeud(
    p_noeud *ceci,
    t_token etiquette,
    const char *contenu,
    p_noeud pere,
    p_noeud premier_fils,
    p_noeud dernier_fils,
    p_noeud grand_frere,
    p_noeud petit_frere);

void detruire_noeud(p_noeud *ceci);

void modifier_etiquette_noeud(p_noeud ceci, t_token nouvelle_etiquette);

void modifier_contenu_noeud(p_noeud ceci, char *nouveau_contenu);

void modifier_parente_noeud(p_noeud ceci, t_parente lien_de_parente, p_noeud nouveau_parent);

void debugger_noeud(p_noeud ceci);

// orphelin va devenir le fils de ceci
void inserer_aine(p_noeud ceci, p_noeud orphelin);

void inserer_cadet(p_noeud ceci, p_noeud orphelin);

// gerer l'insertion entre les freres
void inserer_apres(p_noeud ceci, p_noeud orphelin);

void inserer_avant(p_noeud ceci, p_noeud orphelin);

// extraire le noeud de l'arbre (retirer tout ses freres ect)
void extraire(p_noeud ceci);

// afficher en mode uml
void afficher_elabore(t_arbre_nanodom ceci);

// afficher en mode texte_enrichi
void afficher_enrichi(t_arbre_nanodom ceci);

// afficher_elabore dans un fichier texte
void sauvegarder_enrichi(t_arbre_nanodom ceci, FILE *fichier);

void detruire_nanodom(t_arbre_nanodom *ceci);

#endif