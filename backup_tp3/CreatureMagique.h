#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature {

public :

	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus);

	CreatureMagique(const Creature& creature);

	CreatureMagique& operator=(const CreatureMagique& creature);

	void attaquer(const Pouvoir& pouvoir, Creature& creature);

	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature);

private :

	int bonus_;

};

#endif
