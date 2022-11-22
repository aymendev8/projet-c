#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_texte_enrichi.h"

t_mode mon_mode = NORMAL;
int compteur = 0;
int compteur_pipe = 0;
int compteur_espaces = 0;
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

void desindenter(int n)
{
    compteur_espaces -= n;
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

    for (int i = 0; i <= 80 - (compteur + compteur_mots); i++)
        printf(" ");

    if (compteur != 0)
    {
        for (int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("\n");
    compteur_mots = 0;
}

void ecrire_mot(const char *mot)
{

    if (!est_au_debut_de_ligne())
    {
        printf(" ");
    }
    compteur_mots += strlen(mot);
    printf("%s", mot);
}