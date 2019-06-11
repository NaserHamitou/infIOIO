#include"CreatureMagique.h"

CreatureMagique::CreatureMagique() : Creature(), bonus_(0), attaqueMagique_(nullptr) {
}

CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus) : Creature(creature), 
bonus_(bonus), attaqueMagique_(nullptr) {}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique) : Creature(creatureMagique) {

	nom_ = creatureMagique.nom_;
	attaque_ = creatureMagique.attaque_;
	defense_ = creatureMagique.defense_;
	pointDeVie_ = creatureMagique.pointDeVie_;
	pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
	energie_ = creatureMagique.energie_;
	energieTotal_ = creatureMagique.energieTotal_;
	experience_ = creatureMagique.experience_;
	experienceNecessaire_ = creatureMagique.experienceNecessaire_;
	niveau_ = creatureMagique.niveau_;
	bonus_ = creatureMagique.bonus_;

	if (dynamic_cast<AttaqueMagiqueConfusion*>(creatureMagique.attaqueMagique_))
		attaqueMagique_ = new AttaqueMagiqueConfusion(*dynamic_cast<AttaqueMagiqueConfusion*>(creatureMagique.attaqueMagique_));
	else
		attaqueMagique_ = new AttaqueMagiquePoison(*dynamic_cast<AttaqueMagiquePoison*>(creatureMagique.attaqueMagique_));

}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique) {
	if (this != &creatureMagique)
	{
		nom_ = creatureMagique.nom_;
		attaque_ = creatureMagique.attaque_;
		defense_ = creatureMagique.defense_;
		pointDeVie_ = creatureMagique.pointDeVie_;
		pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
		energie_ = creatureMagique.energie_;
		energieTotal_ = creatureMagique.energieTotal_;
		experience_ = creatureMagique.experience_;
		experienceNecessaire_ = creatureMagique.experienceNecessaire_;
		niveau_ = creatureMagique.niveau_;
		bonus_ = creatureMagique.bonus_;
		
		delete attaqueMagique_;
		if (dynamic_cast<AttaqueMagiqueConfusion*>(creatureMagique.attaqueMagique_))
			attaqueMagique_ = new AttaqueMagiqueConfusion(*dynamic_cast<AttaqueMagiqueConfusion*>(creatureMagique.attaqueMagique_));
		else
			attaqueMagique_ = new AttaqueMagiquePoison(*dynamic_cast<AttaqueMagiquePoison*>(creatureMagique.attaqueMagique_));

		while (pouvoirs_.size() != 0)
		{
			delete pouvoirs_.back();
			pouvoirs_.back() = nullptr;
			pouvoirs_.pop_back();
		}
		for (unsigned int i = 0; i < creatureMagique.pouvoirs_.size(); i++)
		{
			pouvoirs_.push_back(new Pouvoir(*creatureMagique.pouvoirs_[i]));
		}
	}
	return *this;
}

CreatureMagique::~CreatureMagique() {
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;

}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature) {
	
	if (pointDeVie_ + bonus_ <= pointDeVieTotal_)
		modifierPointDeVie(pointDeVie_ + bonus_);

	if (!attaqueMagique_->estFini())
		attaqueMagique_->appliquerAttaque(creature);

	Creature::attaquer(pouvoir, creature);


}

AttaqueMagique* CreatureMagique::obtenirAttaque() const
{
	return attaqueMagique_;
}

unsigned int CreatureMagique::obtenirBonus() const {
	return bonus_;
}

std::string CreatureMagique::obtenirTypeCreature() const
{
	return "Creature";
}

void CreatureMagique::modifierBonus(unsigned int bonus) {
	bonus_ = bonus;
}

void CreatureMagique::apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique) {
	//attaqueMagique_ = new AttaqueMagique(*attaqueMagique);                               //more dynamic cast stuff
}

void CreatureMagique::oublierAttaqueMagique(const AttaqueMagique* attaqueMagique)
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}



std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature) {
	os << static_cast<Creature>(creature);
	os << creature.attaqueMagique_;
	return os;
}
