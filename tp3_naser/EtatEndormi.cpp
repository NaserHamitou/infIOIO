#include"EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string& nom) : EtatCreature(nom) {
	type_ = TypeEtat_endormi;
}


EtatEndormi::EtatEndormi(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree) {
	type_ = TypeEtat_endormi;
}

bool EtatEndormi::peutAttaquer() const {
	return false;
}

void EtatEndormi::appliquerEtat(Creature& creature) {
	if (duree_ > 0)
		duree_--;
}

bool EtatEndormi::estFini() {
	return (duree_ <= 0);
}

std::ostream& operator<<(std::ostream& os, const EtatEndormi& endormi) {

	os << "La creature est dans une etat " << endormi.obtenirNom() << std::endl;

	return os;
}