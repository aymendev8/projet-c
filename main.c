#include "p_texte_enrichi.c"

int main()
{
    ouvrir_bloc();
    entamer_ligne();
    ecrire_mot("Bonjour");
    ecrire_mot("tout");
    ecrire_mot("le");
    ecrire_mot("monde");
    ecrire_mot("anticonstitutionnellement");
    ecrire_mot("anticonstitutionnellement");
    ecrire_mot("anticonstitutionnellement");
    ouvrir_bloc();
    entamer_ligne();
    ecrire_mot("Bonjour");
    ecrire_mot("anticonstitutionnellement");
    ecrire_mot("anticonstitutionnellement");
    ecrire_mot("anticonstitutionnellement");
    fermer_bloc();
    fermer_bloc();
    return 0;
}