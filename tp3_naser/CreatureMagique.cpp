#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, int bonus) : Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus) {}


CreatureMagique::CreatureMagique(const Creature& creature) {

	bonus_ = static_cast<CreatureMagique>(creature).bonus_;


}