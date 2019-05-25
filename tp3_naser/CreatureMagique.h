#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

class CreatureMagique : public Creature {

public :

<<<<<<< HEAD
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
=======
	CreatureMagique(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus);

	CreatureMagique(const Creature& creature);

	CreatureMagique& operator=(const CreatureMagique& creature);

	void attaquer(const Pouvoir& pouvoir, Creature& creature);

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature);

private :

	int bonus_;

};

#endif
