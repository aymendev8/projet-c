#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_texte_enrichi.h"

t_mode mon_mode = NORMAL;
int compteur = 0;
int compteur_pipe = 0;  

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
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - (compteur); i++)
        printf("-");
    printf("+");
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    compteur += 2;
    compteur_pipe++;
    printf("\n");
}
void fermer_bloc(){
    compteur -= 2;
    compteur_pipe--;
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - compteur; i++)
        printf("-");
    printf("+");
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("\n");
}
void ecrire_mot(const char* mot){
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("%s", mot);
    for (int i = 0; i <= 80 - (compteur + strlen(mot)); i++)
        printf(" ");
    if (compteur != 0) {
        for(int z = 0; z < compteur_pipe; z++)
            printf("|");
    }
    printf("\n");
}