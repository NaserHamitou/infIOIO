#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus) : Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus) {

	pointDeVieTotal_ = pointDeVie;
	energieTotal_ = energie;
	experience_ = 0;
	experienceNecessaire_ = 100;
	etat_ = new EtatCreature("normal");

}


CreatureMagique::CreatureMagique(const Creature& creature) {

	CreatureMagique creaturemag = static_cast<CreatureMagique>(creature);

	nom_ = creaturemag.nom_;
	attaque_ = creaturemag.attaque_;
	defense_ = creaturemag.defense_;
	pointDeVie_ = creaturemag.pointDeVie_;
	pointDeVieTotal_ = pointDeVieTotal_;
	energie_ = creaturemag.energie_;
	energieTotal_ = creaturemag.energieTotal_;
	experience_ = creaturemag.experience_;
	experienceNecessaire_ = creaturemag.experienceNecessaire_;
	niveau_ = creaturemag.niveau_;
	pouvoirs_ = creaturemag.pouvoirs_;
	bonus_ = creaturemag.bonus_;

	if (creaturemag.etat_ != nullptr)
		etat_ = new EtatCreature(*creature.obtenirEtat());
	else
		etat_ = new EtatCreature("normal");

}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) {


	bool pouvoirEstDansVector = false;
	for (unsigned int i = 0; i < pouvoirs_.size(); i++) //S'assurer que votre créature a bien ce pouvoir.
	{
		if (*pouvoirs_[i] == pouvoir)
		{
			pouvoirEstDansVector = true;
		}
	}
	if (energie_ >= pouvoir.obtenirEnergieNecessaire() && pouvoirEstDansVector)
	{
		if (creature.obtenirPointDeVie() >= 0) {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = abs((int)((pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.obtenirDefense())));
			int peutAttaquer = rand() % 6;
			if (peutAttaquer) {
				std::cout << nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige " << degat
					<< " degat a " << creature.obtenirNom() << std::endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					std::cout << nom_ << " a gagné " << xp << " XP" << std::endl;
				}
				else {
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				}

				std::cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << std::endl;
				energie_ -= pouvoir.obtenirEnergieNecessaire();

				if ((this->obtenirPointDeVie() + bonus_) <= this->obtenirPointDeVieTotal())
					this->modifierPointDeVie(this->obtenirPointDeVie() + bonus_);
				else {
					this->modifierPointDeVie(this->obtenirPointDeVieTotal());
				}
			}
			else {
				std::cout << "La creature est dans " << *etat_ << std::endl;
				std::cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << std::endl;
			}
		}
		else {
			std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << std::endl;
		}
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


