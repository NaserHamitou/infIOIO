#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique() {}

AttaqueMagique::AttaqueMagique(int duree) : duree_(duree) {}

AttaqueMagique::~AttaqueMagique() {}

int AttaqueMagique::obtenirDuree() {
	return duree_;
}

void AttaqueMagique::modifierDuree(int duree) {
	duree_ = duree;
}

std::string AttaqueMagique::obtenirTypeAttaque() const {}

void AttaqueMagique::appliquerAttaque(Creature& creature) {}

bool AttaqueMagique::estFini() {
	return true;
}

std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaqueM) {
	os << "Cette creature de la classe CreatureMagique a aussi une attaque magique de type class "
		<< attaqueM.obtenirTypeAttaque() << " qui a une duree de " << attaqueM.duree_;
	return os;
}