#include "pouvoirHallucinogene.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire) {
	type_ = TypeEtat_confus;
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) {
	type_ = TypeEtat_confus;
}

<<<<<<< HEAD
void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie) const {
	creatureEnnemie.modifierEtat(new EtatConfus("confus", duree_));
=======
void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie) {
	creatureEnnemie.modifierEtat(new EtatCreature("confus", duree_));
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
}

std::ostream& operator<<(std::ostream& os, const PouvoirHallucinogene& hallucinogene) {

	os << static_cast<Pouvoir>(hallucinogene);
	os << " il peut rendre confus la cible" << std::endl;
	/*os << hallucinogene.nom_ << " possede un nombre de dégat de " << hallucinogene.nombreDeDegat_ <<
		" et une energie necessaire de " << hallucinogene.energieNecessaire_ << std::endl;*/
	return os;

}