#include "PotionMagique.h"

PotionMagique::PotionMagique() : ObjetMagique() {}

PotionMagique::PotionMagique(const std::string &nom, int bonus) : ObjetMagique(nom, bonus) {}

void PotionMagique::utiliserSur(Creature& creature) const {

	if((creature.obtenirPointDeVie() + bonus_) <= creature.obtenirPointDeVieTotal())
		creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
	else
	{
		creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	}
}

std::ostream& operator<<(std::ostream& os, const PotionMagique& potion) {
	os << "l'objet " << potion.nom_ << "fournit un bonus de " << potion.bonus_ << std::endl;
	return os;
}