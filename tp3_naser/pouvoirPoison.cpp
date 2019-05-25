#include "pouvoirPoison.h"

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire) {
	type_ = TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) {
	type_ = TypeEtat_empoisonne;
}

<<<<<<< HEAD
void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie) const {

	creatureEnnemie.modifierEtat(new EtatEmpoisonne("poison", duree_));     	         /*!! not sure !!*/
=======
void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie) {

	creatureEnnemie.modifierEtat(new EtatCreature("poison", duree_));     	         /*!! not sure !!*/
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df

}

std::ostream& operator<<(std::ostream& os, const PouvoirPoison& poison) {

	os << static_cast<Pouvoir>(poison);
	os << " il peut empoisonner la cible " << std::endl;
	/*os << poison.nom_ << " possede un nombre de dégat de " << poison.nombreDeDegat_ <<
		" et une energie necessaire de " << poison.energieNecessaire_ << std::endl;*/
	return os;

}
