/*
Fichier: CreatureMagique.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
R�vision: Maude Carrier (11 octobre 2016)
Description: Les creatures magiques peuvent b�nificier d'une attaque magique
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

    ~CreatureMagique(); // � MODIFIER (si n�cessaire...)

    void attaquer(const Pouvoir& pouvoir, Creature& creature); // � MODIFIER (si n�cessaire...)

    friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature); // � MODIFIER (si n�cessaire...)
	
	AttaqueMagique* obtenirAttaque() const;
	unsigned int obtenirBonus() const;

	std::string obtenirTypeCreature() const;

	void modifierBonus(unsigned int bonus);

	void apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique);
	void oublierAttaqueMagique(const AttaqueMagique* attaqueMagique);

private:
    unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;
};

#endif