#include <stdio.h>
#include <stdlib.h>
#include "p_nanodom.h"

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
    printf("    -Pere : %p \n", &ceci->les_parentes[PERE]);
    printf("    -Premier fils : %p \n", &ceci->les_parentes[PREMIER_FILS]);
    printf("    -Dernier fils : %p \n", &ceci->les_parentes[DERNIER_FILS]);
    printf("    -Grand frere : %p \n", &ceci->les_parentes[GRAND_FRERE]);
    printf("    -Petit frere : %p \n", &ceci->les_parentes[PETIT_FRERE]);
}


void inserer_aine(p_noeud ceci, p_noeud orphelin)
{
    ceci->les_parentes[PREMIER_FILS] = orphelin;
    orphelin->les_parentes[PERE] = ceci;
}

void inserer_cadet(p_noeud ceci, p_noeud orphelin)
{
    ceci->les_parentes[DERNIER_FILS] = orphelin;
    orphelin->les_parentes[PERE] = ceci;
}

void inserer_apres(p_noeud ceci, p_noeud orphelin)
{
    if (ceci->les_parentes[DERNIER_FILS] != NULL)
    {
        inserer_cadet(ceci->les_parentes[PREMIER_FILS], orphelin);
    }
    else
    {
        inserer_aine(ceci, orphelin);
    }
}
void inseret_avant(p_noeud ceci, p_noeud orphelin)
{
    if (ceci->les_parentes[PREMIER_FILS] != NULL)
    {
        inserer_cadet(ceci->les_parentes[PREMIER_FILS], orphelin);
    }
    else
    {
        inserer_aine(ceci, orphelin);
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
}

