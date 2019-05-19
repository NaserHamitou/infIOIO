#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (dresseurs_.size() >= MAX_DRESSEURS)
		return false;
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (*dresseurs_[i] == *dresseur)
			return false;
	}
	dresseurs_.push_back(dresseur);
	cout << *dresseur << " a bien �t� ajout� !" << endl;
	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if (creatures_.size() >= MAX_CREATURES)
		return false;

	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == creature.obtenirNom())
			return false;
	}
	creatures_.push_back(new Creature(creature));
	cout << creature << " a bien �t� ajout� !" << endl;
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
	if (dresseurs_.size() > 0) 
    {
		unsigned int indice = rand() % dresseurs_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature* creature) // A MODIF (si necessaire) /* ????? */
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

ostream& operator<<(ostream& os, const PolyLand& poly) {

	for (int i = 0; i < poly.dresseurs_.size(); i++)
		os << poly.dresseurs_[i];
	return os;
}

void PolyLand::infoDresseur(const string& nom) const // A MODIFIER... (si necessaire)
{
	Dresseur* dresseur = nullptr;
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (dresseurs_[i]->obtenirNom() == nom)
		{
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr)
	{
		cout << "Informations sur le dresseur: " << endl;
		dresseur->affichage();
		for (unsigned int i = 0; i < dresseur->obtenirNombreCreatures(); i++)
		{
			cout << "- " << i + 1 << " - ";
			dresseur->obtenirCreatures()[i]->information();
		}
	}
	else
	{
		cout << "Dresseur introuvable!" << endl;
	}
}
