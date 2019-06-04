#include "AttaqueMagiqueConfusion.h"

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() {
	duree_ = 2;
}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(int duree) {
	duree_ = duree;
}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion() {}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const {
	return "AttaqueMagiqueConfusion";
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature) {
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

bool AttaqueMagiqueConfusion::estFini() {
	return (duree_ == 0);
}