#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe, OutilScientifique* outil) : Dresseur(nom, equipe), ptrOutilScientifique_(outil) 
{}

Professeur::Professeur(const Professeur& prof) {
	nom_ = prof.nom_;
	equipe_ = prof.equipe_;
	ptrOutilScientifique_ = prof.ptrOutilScientifique_;
	creatures_ = prof.creatures_;
}

Professeur::~Professeur() {
	delete ptrOutilScientifique_;
}

void Professeur::modifierOutilScientifique(OutilScientifique* outil) {
	ptrOutilScientifique_ = outil;
}

void Professeur::soigner(Creature& creature) {
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	creature.modifierEnergie(creature.obtenirEnergieTotale());
}

Professeur& Professeur::operator=(const Professeur& prof) {

	if (this != &prof) {
		nom_ = prof.nom_;
		equipe_ = prof.equipe_;
		ptrOutilScientifique_ = ptrOutilScientifique_;
	}

	return *this;

}

void Professeur::utiliserOutil(Creature& creature) {
	ptrOutilScientifique_->utiliser(creature);
}

