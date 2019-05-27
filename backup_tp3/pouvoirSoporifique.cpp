#include "pouvoirSoporifique.h"

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) : Pouvoir(nom, nombreDeDegat, energieNecessaire) { type_ = TypeEtat_endormi; }

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree) : Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree) { type_ = TypeEtat_endormi; }

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie) {

	creatureEnnemie.modifierEtat(new EtatEndormi("endormie", duree_));

}

 std::ostream& operator<<(std::ostream& os, const PouvoirSoporifique& soporifique) {
 
	 os << static_cast<Pouvoir>(soporifique);
	 os << " il peut endormir la cible" << std::endl;
	 /*os << soporifique.nom_ << " possede un nombre de dégat de " << soporifique.nombreDeDegat_ <<
		 " et une energie necessaire de " << soporifique.energieNecessaire_ << std::endl;*/
	 return os;

 }