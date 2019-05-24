#include "pouvoirHallucinogene.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire) {
	type_ = TypeEtat_confus;
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) {
	type_ = TypeEtat_confus;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie) {
	creatureEnnemie.modifierEtat(new EtatConfus("confus", duree_));
}

std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& hallucinogene) {

	os << hallucinogene.nom_ << " possede un nombre de dégat de " << hallucinogene.nombreDeDegat_ <<
		" et une energie necessaire de " << hallucinogene.energieNecessaire_ << std::endl;
	return os;

}