#include "p_texte_enrichi.c"
#include "p_texte_enrichi.h"

int main()
{
    ouvrir_bloc();
    ecrire_mot("MEMOIRE");
    ouvrir_bloc();
    ecrire_mot("INTRODUCTION");
    ecrire_mot(" * Un peu de TEXTE.");
    fermer_bloc();
    ouvrir_bloc();
    ecrire_mot("ANNEXES");
    ouvrir_bloc();
    ecrire_mot("TABLE DES MATIERES");
    fermer_bloc();
    ouvrir_bloc();
    ecrire_mot("TABLE DES MATIERES");
    fermer_bloc();
    fermer_bloc();
    fermer_bloc();
    
    return 0;
}