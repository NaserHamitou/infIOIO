#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include "Pouvoir.h"
#include "EtatEmpoisonne.h"

class PouvoirPoison : public Pouvoir {

public :

	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	
	PouvoirPoison(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

<<<<<<< HEAD
	void appliquerEffetOffensif(Creature& creatureEnnemie) const;
=======
	void appliquerEffetOffensif(Creature& creatureEnnemie);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df

	friend std::ostream& operator<<(std::ostream& os, const PouvoirPoison& poison);

	

private :

	int duree_;

};

#endif