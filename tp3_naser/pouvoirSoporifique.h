#ifndef POUVOIRSOPORIFIQUE_H
#define POUVOIRSOPORIFIQUE_H

#include "Pouvoir.h"

class PouvoirSoporifique : public Pouvoir {

public :

	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	void appliquerEffetOffensif(Creature& creatureEnnemie);

	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& soporifique);

private : 
	
	int duree_;
};

#endif