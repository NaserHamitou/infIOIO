#include "pouvoirPoison.h"

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire) {
	type_ = TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) {
	type_ = TypeEtat_empoisonne;
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie) {

	creatureEnnemie.modifierEtat(new EtatCreature("poison", duree_));     	         /*!! not sure !!*/

}

std::ostream& operator<<(std::ostream& os, const PouvoirPoison& poison) {

	os << static_cast<Pouvoir>(poison);
	os << " il peut empoisonner la cible " << std::endl;
	/*os << poison.nom_ << " possede un nombre de dégat de " << poison.nombreDeDegat_ <<
		" et une energie necessaire de " << poison.energieNecessaire_ << std::endl;*/
	return os;

}
