/**
 * @brief Il s'agit d'une bibliothèque permettant d'écrire du texte de facon plus claire et plus lisible.
 *
 * @author Aymen Kadri & Roméo Froger
 * @date novembre 2022
 */

#ifndef P_TEXTE_ENRICHI
#define P_TEXTE_ENRICHI

typedef enum e_mode
{
    NORMAL,
    MAJUSCULE,
    MINUSCULE
} t_mode;

/**
 * @brief Cette fonction permet de changer le mode d'affichage du texte.
 * IL y a trois modes possibles : NORMAL, MAJUSCULE, MINUSCULE.
 *
 *
 * @param mode
 */
void changer_mode(t_mode mode);

/**
 * @brief Cette fonction permet de retourner le mode actuel.
 *
 */
t_mode mode();

/**
 * @brief Cette fonction permet d'ouvrir un bloc.
 *
 *
 */
void ouvrir_bloc();

/**
 * @brief Cette fonction permet de fermer un bloc.
 *
 *
 */
void fermer_bloc();

/**
 * @brief Cette fonction permet d'indenter une ligne de nombre_d_espaces espaces.
 *
 *
 * @param nombre_d_espaces
 */
void indenter(int nombre_d_espaces);

/**
 * @brief Cette fonction permet desindenter une ligne.
 *
 *
 *
 */
void desindenter();

/**
 * @brief Cette fonction permet de savoir si on est en fin de ligne.
 *
 *
 * @return int
 */
int est_en_fin_de_ligne();

/**
 * @brief Cette fonction permet de savoir si on est au début de ligne.
 *
 *
 * @return int
 */
int est_au_debut_de_ligne();

/**
 * @brief Cette fonction permet d'entamer une ligne.
 *
 *
 */
void entamer_ligne();

/**
 * @brief Cette fonction permet de terminer une ligne.
 *
 */
void terminer_ligne();

/**
 * @brief Cette fonction de mettre une *.
 *
 *
 *
 */
void pucer();

/**
 * @brief Cette fonction permet d'écrire un mot.
 *
 *
 * @param mot
 */
void ecrire_mot(const char *mot);

// le nombre de d'espace manquant et retourne oui ou non si on peux ecrire ou pas
int peut_ecrire(int nb_caracteres);

#endif