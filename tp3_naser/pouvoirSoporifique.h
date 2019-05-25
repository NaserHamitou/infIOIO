#ifndef POUVOIRSOPORIFIQUE_H
#define POUVOIRSOPORIFIQUE_H

#include "Pouvoir.h"
#include "EtatEndormi.h"

class PouvoirSoporifique : public Pouvoir {

public :

	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	PouvoirSoporifique(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

<<<<<<< HEAD
	void appliquerEffetOffensif(Creature& creatureEnnemie) const;
=======
	void appliquerEffetOffensif(Creature& creatureEnnemie);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df

	friend std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& soporifique);

private : 
	
	int duree_;
};

#endif