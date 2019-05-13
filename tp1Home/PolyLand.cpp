#include "PolyLand.h"

PolyLand::PolyLand() {

	//Initialisations des tableaux pour les creatures et les dresseurs
	dresseurs_ = new Dresseur*[MAX_DRESSEURS];
	for (unsigned i = 0; i < MAX_DRESSEURS; i++)
		dresseurs_[i] = nullptr;
	nombreDresseurs_ = 0;

	creatures_ = new Creature*[MAX_CREATURES];
	for (unsigned i = 0; i < MAX_CREATURES; i++)
		creatures_[i] = nullptr;
	nombreCreatures_ = 0;
}

PolyLand::~PolyLand() {
	for (unsigned i = 0; i < nombreDresseurs_; i++) {
		delete dresseurs_[i];
	}
	delete[] dresseurs_;
	dresseurs_ = nullptr;

	for (unsigned i = 0; i < nombreCreatures_; i++) {
		delete creatures_[i];
	}
	delete[] creatures_;
	creatures_ = nullptr;
}

bool PolyLand::ajouterDresseur(Dresseur* dresseur){
	
	if (nombreDresseurs_ != 0) {
		for (int i = 0; i < nombreDresseurs_; i++) {
			if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) {
				cout << "ne peux par etre ajouter !" << endl;
				return false;
			}
		}
	}

	if (nombreDresseurs_ == MAX_DRESSEURS)
		return false;

	dresseurs_[nombreDresseurs_] = dresseur;
	nombreDresseurs_++;
	cout << dresseur->obtenirNom() << " a bien ete ajoute !" << endl;
	return true;
}


bool PolyLand::ajouterCreature(Creature& creature) {       /* pk il faut copier creature ?? */

	if (nombreCreatures_ != 0) {
		for (unsigned i = 0; i < nombreCreatures_; i++) {
			if (creatures_[i]->obtenirNom() == creature.obtenirNom())
				return false;
		}
	}

	if (nombreCreatures_ == MAX_CREATURES) 
		return false;

	creatures_[nombreCreatures_] = &creature;
	nombreCreatures_++;
	cout << creature.obtenirNom() << " a bien ete ajoute !" << endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom) {									
	for (unsigned i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			delete dresseurs_[i];
			return true;
		}
		else {
			return false;
		}
	}
}

bool PolyLand::retirerCreature(const string& nom) {
	for (unsigned i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			delete creatures_[i];
			return true;
		}
		else{
			return false;
		}
	}
}

Dresseur* PolyLand::choisirDresseurAleatoire() {
	srand(time(NULL));
	return dresseurs_[rand() % nombreDresseurs_];
}

Creature* PolyLand::choisirCreatureAleatoire() {
	srand(time(NULL));
	return creatures_[rand() % nombreCreatures_];
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature& creature) {
	
	if (dresseur->ajouterCreature(creature))
		return true;
	else
	{
		return false;
	}
}

bool PolyLand::relacherCreature(Dresseur* dresseur, Creature& creature) {

	if (dresseur->retirerCreature(creature.obtenirNom()))
		return true;
	else
	{
		return false;
	}

}

void PolyLand::infoDresseur(const string& nom) {
	cout << "Information sur le dresseur : " << endl;
	for (unsigned i = 0; i < nombreDresseurs_; i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i]->affichage();
			for (unsigned j = 0; j < dresseurs_[i]->obtenirNombreCreatures(); j++) {
				cout << "- " << j + 1 << " - ";
				dresseurs_[i]->obtenirCreatures()[j]->information();
				dresseurs_[i]->obtenirCreatures()[j]->obtenirPouvoir().description();
				cout << endl;
			}
		}
	}
}