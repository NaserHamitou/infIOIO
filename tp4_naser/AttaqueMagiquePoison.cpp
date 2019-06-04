#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison() {
	duree_ = 2;
}

AttaqueMagiquePoison::AttaqueMagiquePoison(int duree) {
	duree_ = duree;
}

AttaqueMagiquePoison::~AttaqueMagiquePoison() {}

std::string AttaqueMagiquePoison::obtenirTypeAttaque() const {
	return "AttaqueMagiquePoison";
}

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature) {
	if (duree_ > 0 && creature.obtenirPointDeVie() >= 5)
	{
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		if (rand() % 3 == 0)
		{
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() {
	return (duree_ == 0);
}