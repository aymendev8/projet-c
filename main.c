#include "p_texte_enrichi.c"
#include "p_texte_enrichi.h"

int main()
{
    ouvrir_bloc();
    ecrire_mot("test ovpzevjkzepofv");
    ecrire_mot("test paedjdpoedjdojddj");
    fermer_bloc();
    ouvrir_bloc();
    ouvrir_bloc();
    ecrire_mot("Bonjour");
    ecrire_mot("test paedjdpoedjdojddj");
    fermer_bloc();
    fermer_bloc();
    return 0;
}