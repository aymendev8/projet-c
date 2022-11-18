#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_texte_enrichi.h"

t_mode mon_mode = NORMAL;
int compteur = 0;

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
        printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - compteur; i++)
        printf("-");
    printf("+");
    if (compteur != 0) {
        printf("|");
    }
    compteur += 2;
    printf("\n");
}
void fermer_bloc(){
    compteur -= 2;
    if (compteur != 0) {
        printf("|");
    }
    printf("+");
    for (int i = 0; i < 79 - compteur; i++)
        printf("-");
    printf("+");
    if (compteur != 0) {
        printf("|");
    }
    printf("\n");
}
void ecrire_mot(const char* mot){
    printf("|");
    printf("%s", mot);
    for (int i ; i < 79 - strlen(mot); i++){
        printf(" ");
    }
    printf("|");
    printf("\n");
}