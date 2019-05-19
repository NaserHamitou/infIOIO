#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{
	dresseurs_.clear();
	creatures_.clear();
}

vector<Creature*> PolyLand::getTab() const {
	return creatures_;
}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
		return false;
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (*dresseurs_[i] == *dresseur) {
			cout << dresseur->obtenirNom() << " a deja ete ajoutee " << endl;
			return false;
		}
	}
	dresseurs_.push_back(dresseur);
	cout << dresseur->obtenirNom() << " a bien ete ajoute !" << endl;
	return true;
}

bool PolyLand::ajouterCreature(Creature& creature) // A MODIFIER... (si necessaire)
{
	if (creatures_.size() >= MAX_CREATURES)
		return false;

	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == creature.obtenirNom())
			return false;
	}
	creatures_.push_back(&creature);
	cout << creature.obtenirNom() << " a bien ete ajoute !" << endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if ( *dresseurs_[i] == nom)
		{
			dresseurs_[i] = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}

bool PolyLand::retirerCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			creatures_[i] = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else 
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	srand(time(NULL));

	if (dresseurs_.size() > 0) 
    {	
		return creatures_[rand() % dresseurs_.size()];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) // A MODIF (si necessaire) /* ????? */
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

PolyLand& PolyLand::operator+=(Dresseur* dresseur){
	
	ajouterDresseur(dresseur);
	return *this;

}

PolyLand& PolyLand::operator-=(const Dresseur* dresseur) {

	retirerDresseur(dresseur->obtenirNom());
	return *this;

}

PolyLand& PolyLand::operator+=(Creature& creature) {
	ajouterCreature(creature);
	return *this;
}

PolyLand& PolyLand::operator-=(const Creature& creature) {
	retirerCreature(creature.obtenirNom());
	return *this;
}

ostream& operator<<(ostream& os, const PolyLand& poly) {
	if (poly.dresseurs_.size() == 0)
		os << "Dresseur introuvable " << endl;
	else {
		for (int i = 0; i < poly.dresseurs_.size(); i++)
			os << *poly.dresseurs_[i];
	}
	return os;
}

