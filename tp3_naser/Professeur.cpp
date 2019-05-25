#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe) : Dresseur(nom, equipe)
{
	outilScientifique_ = nullptr;
}

Professeur::Professeur(const Professeur& prof) {
	nom_ = prof.nom_;
	equipe_ = prof.equipe_;
	outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
	creatures_ = prof.creatures_;
}

Professeur::~Professeur() {
		delete outilScientifique_;
		outilScientifique_ = nullptr;
}

void Professeur::modifierOutilScientifique(OutilScientifique* outil) {
	
	delete outilScientifique_;
	outilScientifique_ = nullptr;
	outilScientifique_ = new OutilScientifique(*outil);
}

void Professeur::soigner(Creature& creature) {
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	creature.modifierEnergie(creature.obtenirEnergieTotale());
}

Professeur& Professeur::operator=(const Professeur& prof) {

	if (this != &prof) {
		nom_ = prof.nom_;
		equipe_ = prof.equipe_;
		delete outilScientifique_;
		outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
	}

	return *this;

}

void Professeur::utiliserOutil(Creature& creature) {
	outilScientifique_->utiliser(creature);
}

