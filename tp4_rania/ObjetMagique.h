/*
 Fichier: CreatureMagique.h
 Auteur(s): Philippe Troclet
 Date de creation: 30 septembre 2016
 RÈvision: Maude Carrier (11 octobre 2016)
 Description: Les creatures magiques peuvent bÈnificier d'une attaque magique
 */
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H

#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"

class CreatureMagique : public Creature
{
public:
    CreatureMagique();
    CreatureMagique(const Creature& creature, unsigned int bonus);
    
    CreatureMagique(const CreatureMagique& creatureMagique);
    CreatureMagique& operator=(const CreatureMagique& creatureMagique);
    
    ~CreatureMagique(); // ¿ MODIFIER (si nÈcessaire...)
    
    void attaquer(const Pouvoir& pouvoir, Creature& creature); // ¿ MODIFIER (si nÈcessaire...)
    
    friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature); // ¿ MODIFIER (si nÈcessaire...)
    
    AttaqueMagique* obtenirAttaque();
    unsigned int obtenirBonus();
    void modifierBonus(unsigned int bonus);
    
    void apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique);
    void oublierAttaqueMagique(const AttaqueMagique* attaqueMagique);
    
private:
    unsigned int bonus_;
    AttaqueMagique* attaqueMagique_;
};

#endif
