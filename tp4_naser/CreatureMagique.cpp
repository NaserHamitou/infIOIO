#include"CreatureMagique.h"

CreatureMagique::CreatureMagique() : Creature(), bonus_(0), attaqueMagique_(nullptr) {
}

CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus) : Creature(creature), 
bonus_(bonus), attaqueMagique_(nullptr) {}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique) : Creature(creatureMagique) {

	bonus_ = creatureMagique.bonus_;
	attaqueMagique_ = creatureMagique.attaqueMagique_; // A CHANGER -> DEEP COPY -> UTILISER DYNAMIC CAST

}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique) {
	if (this != &creatureMagique)
	{
		nom_ = creatureMagique.nom_;
		attaque_ = creatureMagique.attaque_;
		defense_ = creatureMagique.defense_;
		pointDeVie_ = creatureMagique.pointDeVie_;
		energie_ = creatureMagique.energie_;
		experience_ = creatureMagique.experience_;
		niveau_ = creatureMagique.niveau_;
		bonus_ = creatureMagique.bonus_;
		
		delete attaqueMagique_;
		attaqueMagique_ = new AttaqueMagique(*creatureMagique.attaqueMagique_);  //Use Dynamic cast to fix problem ?? maybe

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
	Creature::~Creature();
	delete attaqueMagique_;
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
