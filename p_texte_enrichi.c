#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "p_texte_enrichi.h"

t_mode mon_mode = NORMAL;
/*compteur de bloc */
int compteur = 0;
/*compteur pour mettre les pipes au début et en fin de ligne  */
int compteur_pipe = 0;
/*compteur pour les fonctions indenter et desindenter  */
int compteur_espaces = 0;
/*compteur pour compter les mots par ligne */
int compteur_mots = 0;

void changer_mode(t_mode mode)
{
    mon_mode = mode;
}

t_mode mode()
{
    return mon_mode;
}

void ouvrir_bloc()
{
    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - (compteur); i++)
        printf("-");
    printf("+");
    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    compteur += 2;
    compteur_pipe++;
    printf("\n");
}
void fermer_bloc()
{
    compteur -= 2;
    compteur_pipe--;
    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - compteur; i++)
        printf("-");
    printf("+");
    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("\n");
}

void indenter(int n)
{
    compteur_espaces += n;
}

void desindenter()
{
    compteur_espaces -= compteur_espaces;
}

int est_en_fin_de_ligne()
{
    if (compteur_mots == 80 - compteur_pipe * 2)
    {
        return 1;
    }
    return 0;
}

int est_au_debut_de_ligne()
{
    if (compteur_mots == compteur_pipe + compteur_espaces)
    {
        return 1;
    }
    return 0;
}

void entamer_ligne()
{
    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
        {
            compteur_mots++;
            printf("|");
        }
    }
    for (int i = 0; i < compteur_espaces; i++)
    {
        compteur_mots++;
        printf(" ");
    }
}

void terminer_ligne()
{

    for (int i = 0; i <= 80 - (compteur_mots + compteur_pipe); i++)
        printf(" ");

    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("\n");
    compteur_mots = 0;
}

void pucer(){
    printf("*");
    compteur_mots++;
}

void ecrire_mot(const char *mot)
{
    /* Verification que le mot ne dépasse pas de la ligne sinon création d'une nouvelle ligne */
    int taille_mot = strlen(mot);
    if (compteur_mots + taille_mot > 80 - compteur_pipe * 2){
        terminer_ligne();
        entamer_ligne();
        ecrire_mot(mot);
        terminer_ligne();
    }else{
        if (!est_au_debut_de_ligne())
        {
            printf(" ");
            compteur_mots++;
        }
        compteur_mots += strlen(mot);
        /* Ecrire le mot en fonction du mode choisis */
        for (int i = 0; i < taille_mot; i++)
        {
            if (mon_mode == MAJUSCULE)
            {
                printf("%c", toupper(mot[i]));
            }
            else if (mon_mode == MINUSCULE)
            {
                printf("%c", tolower(mot[i]));
            }
            else
            {
                printf("%c", mot[i]);
            }
        }
        
    }
}