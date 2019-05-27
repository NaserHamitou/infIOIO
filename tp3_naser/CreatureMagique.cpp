#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus) : Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus) {

	pointDeVieTotal_ = pointDeVie;
	energieTotal_ = energie;
	experience_ = 0;
	experienceNecessaire_ = 100;
	etat_ = new EtatCreature("normal");

}


CreatureMagique::CreatureMagique(const CreatureMagique& creature) : Creature(creature) {   /* a ete modifier */
	bonus_ = creature.bonus_;
}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) {

	Creature::attaquer(pouvoir, creature);

	if ((this->obtenirPointDeVie() + bonus_) <= this->obtenirPointDeVieTotal())
		this->modifierPointDeVie(this->obtenirPointDeVie() + bonus_);
	else {
		this->modifierPointDeVie(this->obtenirPointDeVieTotal());
	}

}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creature) {
	
	if (this != &creature) {

		nom_ = creature.nom_;
		attaque_ = creature.attaque_;
		defense_ = creature.defense_;
		pointDeVie_ = creature.pointDeVie_;
		pointDeVieTotal_ = pointDeVieTotal_;
		energie_ = creature.energie_;
		energieTotal_ = creature.energieTotal_;
		experience_ = creature.experience_;
		experienceNecessaire_ = creature.experienceNecessaire_;
		niveau_ = creature.niveau_;
		pouvoirs_ = creature.pouvoirs_;
		delete etat_;
		if (creature.etat_ == nullptr)
			etat_ = new EtatCreature("normal");
		else
		{
			etat_ = new EtatCreature(*(creature.obtenirEtat()));
		}

		bonus_ = creature.bonus_;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature) {

	os << "La creature Magique " << static_cast<Creature>(creature);
	return os;
}


