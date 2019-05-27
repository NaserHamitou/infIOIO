 #ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRHALLUCINOGENE_H

#include "Pouvoir.h"
#include "EtatConfus.h"

class PouvoirHallucinogene : public Pouvoir {

public :

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
	friend std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& hallucinogene);

private:

	int duree_;
};

#endif
