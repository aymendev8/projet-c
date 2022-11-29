#include <stdlib.h>
#include <stdio.h>
#include "p_texte_enrichi.h"
#include "p_nanodom.h"

p_noeud mon_document;

p_noeud mon_titre_1;
p_noeud mon_titre_2;
p_noeud mon_titre_3;
p_noeud mon_titre_4;
p_noeud mon_titre_5;

p_noeud ma_section_1;
p_noeud ma_section_2;
p_noeud ma_section_3;
p_noeud ma_section_4;

p_noeud ma_liste_1;
p_noeud mon_item_1;
p_noeud mon_important_1;

p_noeud ma_feuille_1;
p_noeud ma_feuille_2;
p_noeud ma_feuille_3;
p_noeud ma_feuille_4;
p_noeud ma_feuille_5;
p_noeud ma_feuille_6;
p_noeud ma_feuille_7;
p_noeud ma_feuille_8;
p_noeud ma_feuille_9;
p_noeud ma_feuille_10;
p_noeud ma_feuille_11;
p_noeud ma_feuille_12;
p_noeud ma_feuille_13;

void creer()
{
    creer_noeud(&mon_document, DOCUMENT, NULL, NULL, NULL, NULL, NULL, NULL);

    creer_noeud(&mon_titre_1, TITRE, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&mon_titre_2, TITRE, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&mon_titre_3, TITRE, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&mon_titre_4, TITRE, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&mon_titre_5, TITRE, NULL, NULL, NULL, NULL, NULL, NULL);

    creer_noeud(&ma_section_1, SECTION, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_section_2, SECTION, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_section_3, SECTION, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_section_4, SECTION, NULL, NULL, NULL, NULL, NULL, NULL);

    creer_noeud(&ma_liste_1, LISTE, NULL, NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&mon_item_1, ITEM, NULL, NULL, NULL, NULL, NULL, NULL);

    creer_noeud(&mon_important_1, IMPORTANT, NULL, NULL, NULL, NULL, NULL, NULL);

    creer_noeud(&ma_feuille_1, MOT, "Memoire", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_2, MOT, "Introduction", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_3, MOT, "Bla bla", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_4, MOT, "Un", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_5, MOT, "Peu de", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_6, MOT, "texte.", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_7, MOT, "Annexes", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_8, MOT, "Table", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_9, MOT, "des", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_10, MOT, "Matieres", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_11, MOT, "Table", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_12, MOT, "des", NULL, NULL, NULL, NULL, NULL);
    creer_noeud(&ma_feuille_13, MOT, "figures", NULL, NULL, NULL, NULL, NULL);
}

void assembler()
{
    inserer_aine(mon_document, mon_titre_1);
    inserer_aine(mon_titre_1, ma_feuille_1); // mémoire

    inserer_cadet(mon_document, ma_section_1);

    inserer_aine(ma_section_1, mon_titre_2);

    inserer_aine(mon_titre_2, ma_feuille_2);  // Introduction
    inserer_apres(mon_titre_2, ma_feuille_3); // bla bla
    inserer_apres(ma_feuille_3, ma_liste_1);

    inserer_cadet(ma_liste_1, mon_item_1);

    inserer_aine(mon_item_1, ma_feuille_4);      // Un
    inserer_cadet(mon_item_1, ma_feuille_5);     // Peu de
    inserer_aine(mon_important_1, ma_feuille_6); // texte
    inserer_cadet(mon_item_1, mon_important_1);

    inserer_cadet(mon_document, ma_section_2);

    inserer_aine(ma_section_2, ma_section_4);
    inserer_avant(ma_section_4, ma_section_3);
    inserer_avant(ma_section_3, mon_titre_3);
    inserer_aine(mon_titre_3, ma_feuille_7); // Annexes

    inserer_aine(ma_section_3, mon_titre_4);
    inserer_cadet(mon_titre_4, ma_feuille_8);  // Table
    inserer_cadet(mon_titre_4, ma_feuille_9);  // des
    inserer_cadet(mon_titre_4, ma_feuille_10); // Matieres

    inserer_cadet(mon_titre_5, ma_feuille_11); // Table
    inserer_cadet(mon_titre_5, ma_feuille_12); // des
    inserer_cadet(mon_titre_5, ma_feuille_13); // Matieres

    inserer_cadet(ma_section_4, mon_titre_5);
}

void debugger()
{

    debugger_noeud(mon_document);
    debugger_noeud(mon_titre_1);
    debugger_noeud(mon_titre_2);
    debugger_noeud(mon_titre_3);
    debugger_noeud(mon_titre_4);
    debugger_noeud(mon_titre_5);
    debugger_noeud(ma_liste_1);
    debugger_noeud(mon_item_1);
    debugger_noeud(mon_important_1);
    debugger_noeud(ma_section_1);
    debugger_noeud(ma_section_2);
    debugger_noeud(ma_section_3);
    debugger_noeud(ma_section_4);
    debugger_noeud(ma_feuille_1);
    debugger_noeud(ma_feuille_2);
    debugger_noeud(ma_feuille_3);
    debugger_noeud(ma_feuille_4);
    debugger_noeud(ma_feuille_5);
    debugger_noeud(ma_feuille_6);
    debugger_noeud(ma_feuille_7);
    debugger_noeud(ma_feuille_8);
    debugger_noeud(ma_feuille_9);
    debugger_noeud(ma_feuille_10);
    debugger_noeud(ma_feuille_11);
    debugger_noeud(ma_feuille_12);
}

int main()
{
    debugger();
    creer();
    debugger();
    assembler();
    debugger();
    afficher_elabore(mon_document);
    afficher_enrichi(mon_document);
    detruire_nanodom(&mon_document);
    return 0;
}