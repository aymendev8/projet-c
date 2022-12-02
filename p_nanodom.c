#include <stdio.h>
#include <stdlib.h>
#include "p_nanodom.h"
#include "p_texte_enrichi.h"

const char *t_token_image(t_token ceci)
{
    switch (ceci)
    {
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

const char *t_parente_image(t_parente ceci)
{
    switch (ceci)
    {
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

void creer_noeud(p_noeud *ceci, t_token etiquette, const char *contenu, p_noeud pere, p_noeud premier_fils, p_noeud dernier_fils, p_noeud grand_frere, p_noeud petit_frere)
{
    *ceci = malloc(sizeof(t_noeud));
    (*ceci)->l_etiquette = etiquette;
    (*ceci)->le_contenu = contenu;
    (*ceci)->les_parentes[PERE] = pere;
    (*ceci)->les_parentes[PREMIER_FILS] = premier_fils;
    (*ceci)->les_parentes[DERNIER_FILS] = dernier_fils;
    (*ceci)->les_parentes[GRAND_FRERE] = grand_frere;
    (*ceci)->les_parentes[PETIT_FRERE] = petit_frere;
}

void detruire_noeud(p_noeud *ceci)
{
    free(*ceci);
    *ceci = NULL;
}

void modifier_etiquette_noeud(p_noeud ceci, t_token nouvelle_etiquette)
{
    ceci->l_etiquette = nouvelle_etiquette;
}

void modifier_contenu_noeud(p_noeud ceci, char *nouveau_contenu)
{
    ceci->le_contenu = nouveau_contenu;
}

void modifier_parente_noeud(p_noeud ceci, t_parente lien_de_parente, p_noeud nouveau_parent)
{
    ceci->les_parentes[lien_de_parente] = nouveau_parent;
}

void debugger_noeud(p_noeud ceci){
    printf("Noeud range a l'adresse %p \n", ceci);
    printf("    -Etiquette : %s \n", t_token_image(ceci->l_etiquette));
    printf("    -Contenu : %s \n", ceci->le_contenu);
    printf("    -Pere : %p \n", ceci->les_parentes[PERE]);
    printf("    -Premier fils : %p \n", ceci->les_parentes[PREMIER_FILS]);
    printf("    -Dernier fils : %p \n", ceci->les_parentes[DERNIER_FILS]);
    printf("    -Grand frere : %p \n", ceci->les_parentes[GRAND_FRERE]);
    printf("    -Petit frere : %p \n", ceci->les_parentes[PETIT_FRERE]);
}

void inserer_aine(p_noeud ceci, p_noeud orphelin)
{
    if(ceci->les_parentes[PREMIER_FILS] == NULL){
        modifier_parente_noeud(ceci,PREMIER_FILS,orphelin);
        modifier_parente_noeud(ceci,DERNIER_FILS,orphelin);
        modifier_parente_noeud(ceci->les_parentes[PREMIER_FILS],PERE,ceci);
    }else if (ceci->les_parentes[PREMIER_FILS] != NULL) {
        modifier_parente_noeud(orphelin,PETIT_FRERE,ceci->les_parentes[PREMIER_FILS]);
        modifier_parente_noeud(ceci->les_parentes[PREMIER_FILS],GRAND_FRERE,orphelin);
        modifier_parente_noeud(ceci,PREMIER_FILS,orphelin);
        modifier_parente_noeud(ceci->les_parentes[PREMIER_FILS],PERE,ceci);
    }
}

void inserer_cadet(p_noeud ceci, p_noeud orphelin)
{
    if(ceci->les_parentes[DERNIER_FILS] == NULL){
        modifier_parente_noeud(ceci,PREMIER_FILS,orphelin);
        modifier_parente_noeud(ceci,DERNIER_FILS,orphelin);
        modifier_parente_noeud(ceci->les_parentes[DERNIER_FILS],PERE,ceci);
    }else if (ceci->les_parentes[DERNIER_FILS] != NULL) {
        modifier_parente_noeud(orphelin,GRAND_FRERE,ceci->les_parentes[DERNIER_FILS]);
        modifier_parente_noeud(ceci->les_parentes[DERNIER_FILS],PETIT_FRERE,orphelin);
        modifier_parente_noeud(ceci,DERNIER_FILS,orphelin);
        modifier_parente_noeud(ceci->les_parentes[DERNIER_FILS],PERE,ceci);
    }
}


void inserer_avant(p_noeud ceci, p_noeud orphelin)
{
   if(ceci->les_parentes[GRAND_FRERE] == NULL){
        inserer_aine(ceci->les_parentes[PERE], orphelin);
   }else{
        modifier_parente_noeud(orphelin, PERE, ceci->les_parentes[PERE]);
        modifier_parente_noeud(ceci->les_parentes[GRAND_FRERE], PETIT_FRERE, orphelin);
        modifier_parente_noeud(orphelin, GRAND_FRERE, ceci->les_parentes[GRAND_FRERE]);
        modifier_parente_noeud(orphelin, PETIT_FRERE, ceci);
        modifier_parente_noeud(ceci, GRAND_FRERE, orphelin);     
   }
}

void inserer_apres(p_noeud ceci, p_noeud orphelin)
{
    if(ceci->les_parentes[PETIT_FRERE] == NULL){
        inserer_cadet(ceci->les_parentes[PERE], orphelin);
    } else{
        modifier_parente_noeud(orphelin, PERE, ceci->les_parentes[PERE]);
        modifier_parente_noeud(ceci->les_parentes[PETIT_FRERE], GRAND_FRERE, orphelin);
        modifier_parente_noeud(orphelin, PETIT_FRERE, ceci->les_parentes[PETIT_FRERE]);
        modifier_parente_noeud(orphelin, GRAND_FRERE, ceci);
        modifier_parente_noeud(ceci, PETIT_FRERE, orphelin);
    }
    
}

void extraire(p_noeud ceci){
    if (ceci->les_parentes[PREMIER_FILS] != NULL)
    {
        ceci->les_parentes[PREMIER_FILS]->les_parentes[PERE] = NULL;
        ceci->les_parentes[PREMIER_FILS] = NULL;
    }
    if (ceci->les_parentes[DERNIER_FILS] != NULL)
    {
        ceci->les_parentes[DERNIER_FILS]->les_parentes[PERE] = NULL;
        ceci->les_parentes[DERNIER_FILS] = NULL;
    }
    if (ceci->les_parentes[GRAND_FRERE] != NULL)
    {
        ceci->les_parentes[GRAND_FRERE]->les_parentes[PETIT_FRERE] = NULL;
        ceci->les_parentes[GRAND_FRERE] = NULL;
    }
    if (ceci->les_parentes[PETIT_FRERE] != NULL)
    {
        ceci->les_parentes[PETIT_FRERE]->les_parentes[GRAND_FRERE] = NULL;
        ceci->les_parentes[PETIT_FRERE] = NULL;
    }
    if (ceci->les_parentes[PERE] != NULL)
    {
        if (ceci->les_parentes[PERE]->les_parentes[PREMIER_FILS] == ceci)
        {
            ceci->les_parentes[PERE]->les_parentes[PREMIER_FILS] = NULL;
        }
        if (ceci->les_parentes[PERE]->les_parentes[DERNIER_FILS] == ceci)
        {
            ceci->les_parentes[PERE]->les_parentes[DERNIER_FILS] = NULL;
        }
        ceci->les_parentes[PERE] = NULL;
    }
}


void afficher_enrichi(t_arbre_nanodom ceci){
    if (ceci != NULL){
       if (t_token_image(ceci->l_etiquette) == "DOCUMENT"){
            ouvrir_bloc();
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
            fermer_bloc();
       }
       if(t_token_image(ceci->l_etiquette) == "SECTION"){
            ouvrir_bloc();
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
            fermer_bloc();
       }
       if(t_token_image(ceci->l_etiquette) == "TITRE"){
            changer_mode(MAJUSCULE);
            entamer_ligne();
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
            terminer_ligne();
            changer_mode(NORMAL);
       }
       if(t_token_image(ceci->l_etiquette) == "LISTE"){
            entamer_ligne();
            indenter(10);
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
       }
       if(t_token_image(ceci->l_etiquette) == "ITEM"){
            pucer();
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
            desindenter();
            terminer_ligne();
       }
       if (t_token_image(ceci->l_etiquette) == "IMPORTANT"){
           changer_mode(MAJUSCULE);
            afficher_enrichi(ceci->les_parentes[PREMIER_FILS]);
            changer_mode(NORMAL);
       }

       if(t_token_image(ceci->l_etiquette) == "MOT"){
            if((ceci->les_parentes[GRAND_FRERE] != NULL) && (ceci->les_parentes[GRAND_FRERE]->l_etiquette!=MOT) && (ceci->les_parentes[GRAND_FRERE]->l_etiquette!=IMPORTANT)){
                entamer_ligne();
            }
            ecrire_mot(ceci->le_contenu);
            if((ceci->les_parentes[PETIT_FRERE] != NULL) && (ceci->les_parentes[PETIT_FRERE]->l_etiquette!=MOT) && (ceci->les_parentes[PETIT_FRERE]->l_etiquette!=IMPORTANT)){
                terminer_ligne();
            }
       }
       afficher_enrichi(ceci->les_parentes[PETIT_FRERE]);
    }
}

void afficher_elabore(t_arbre_nanodom ceci){
    
}


void detruire_nanodom(t_arbre_nanodom *ceci){
    if (*ceci != NULL){
        detruire_nanodom(&(*ceci)->les_parentes[PREMIER_FILS]);
        detruire_nanodom(&(*ceci)->les_parentes[DERNIER_FILS]);
        detruire_nanodom(&(*ceci)->les_parentes[GRAND_FRERE]);
        detruire_nanodom(&(*ceci)->les_parentes[PETIT_FRERE]);
        detruire_nanodom(&(*ceci)->les_parentes[PERE]);
        detruire_noeud(ceci);
    }
}
