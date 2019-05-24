#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom) : EtatCreature(nom) {
	type_ = TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree) {
	type_ = TypeEtat_empoisonne;
}

void EtatEmpoisonne::appliquerEtat(Creature& creature) {
	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	duree_--;
}

bool EtatEmpoisonne::estFini() {
	return(duree_ <= 0);
}

std::ostream& operator<<(std::ostream& os, const EtatEmpoisonne& empoisonne) {

	os << "La creature est dans une etat " << empoisonne.obtenirNom() << std::endl;

	return os;
}