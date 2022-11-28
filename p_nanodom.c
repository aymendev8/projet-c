#include <stdio.h>
#include <stdlib.h>
#include "p_nanodom.h"

const char* t_token_image(t_token ceci){
    switch(ceci){
        case DOCUMENT:
            return "DOCUMENT";
        case ANNEXE:
            return "ANNEXE";
        case SECTION:
            return "SECTION";
        case TITRE:
            return "TITRE";
        case LISTE:
            return "LISTE";
        case ITEM:
            return "ITEM";
        case IMPORTANT:
            return "IMPORTANT";
        case RETOUR_A_LA_LIGNE:
            return "RETOUR_A_LA_LIGNE";
        case MOT:
            return "MOT";
    }
}

const char* t_parente_image(t_parente ceci){
    switch(ceci){
        case PERE:
            return "PERE";
        case PREMIER_FILS:
            return "PREMIER_FILS";
        case DERNIER_FILS:
            return "DERNIER_FILS";
        case GRAND_FRERE:
            return "GRAND_FRERE";
        case PETIT_FRERE:
            return "PETIT_FRERE";
    }
}

void creer_noeud(p_noeud* ceci,t_token etiquette,const char* contenu,p_noeud pere,p_noeud premier_fils,p_noeud dernier_fils,p_noeud grand_frere,p_noeud petit_frere){
    *ceci=malloc(sizeof(t_noeud));
    (*ceci)->l_etiquette=etiquette;
    (*ceci)->le_contenu=contenu;
    (*ceci)->les_parentes[PERE]=pere;
    (*ceci)->les_parentes[PREMIER_FILS]=premier_fils;
    (*ceci)->les_parentes[DERNIER_FILS]=dernier_fils;
    (*ceci)->les_parentes[GRAND_FRERE]=grand_frere;
    (*ceci)->les_parentes[PETIT_FRERE]=petit_frere;
}

void detruire_noeud(p_noeud* ceci){
    free(*ceci);
    *ceci=NULL;
}

void modifier_etiquette_noeud(p_noeud ceci, t_token nouvelle_etiquette){
    ceci->l_etiquette=nouvelle_etiquette;
}

void modifier_contenu_noeud(p_noeud ceci, char* nouveau_contenu){
    ceci->le_contenu=nouveau_contenu;
}

