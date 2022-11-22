#include "p_texte_enrichi.c"
#include "p_texte_enrichi.h"

int main()
{
    ouvrir_bloc();
    entamer_ligne();
    ecrire_mot("Bonjour");
    ecrire_mot("tout");
    ecrire_mot("le");
    ecrire_mot("monde");
    terminer_ligne();
    ouvrir_bloc();
    ouvrir_bloc();
    fermer_bloc();
    fermer_bloc();
    fermer_bloc();
    return 0;
}