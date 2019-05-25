<<<<<<< HEAD
 #ifndef POUVOIRHALLUCINOGENE_H
=======
#ifndef POUVOIRHALLUCINOGENE_H
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
#define POUVOIRHALLUCINOGENE_H

#include "Pouvoir.h"
#include "EtatConfus.h"

class PouvoirHallucinogene : public Pouvoir {

public :

<<<<<<< HEAD
	//Constructeur par parametre
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	//Constructeur par parametre
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	/*methode  appliquerEffetOffensif 
	Param Creature& creaturEnnemie */
	void appliquerEffetOffensif(Creature& creatureEnnemie) const;

	//operateur << surcharger 
=======
	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

	PouvoirHallucinogene(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);

	void appliquerEffetOffensif(Creature& creatureEnnemie);

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& hallucinogene);

private:

	int duree_;
};

#endif
