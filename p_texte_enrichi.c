#include <stdio.h>
#include "p_texte_enrichi.h"


t_mode mon_mode = NORMAL;

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
    
}