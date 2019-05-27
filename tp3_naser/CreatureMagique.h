#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature {

public :

	//Constructeur par parametre
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus);

	//Constructeur par copy
	CreatureMagique(const CreatureMagique& creature);

	//operateur = surcharge 
	CreatureMagique& operator=(const CreatureMagique& creature);

	/* Methode attaquer 
	Param Pouvoir& pouvoir, Creature& creature */
	void attaquer(const Pouvoir& pouvoir, Creature& creature);

	/* operateur << surcharger 
	Param ostream& os, CreatureMagique& creature */
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature);

private :

	int bonus_;

};

#endif
