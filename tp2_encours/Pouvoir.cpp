#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir) {
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;
	manaNecessaire_ = pouvoir.manaNecessaire_;
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

unsigned int Pouvoir::obtenirManaNecessaire() const {
	return manaNecessaire_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir){
	return pouvoir;
}

bool Pouvoir::operator==(const Pouvoir& pouvoir) {
	return (nom_ == pouvoir.nom_ &&
			nombreDeDegat_ == pouvoir.nombreDeDegat_ &&
			energieNecessaire_ == pouvoir.energieNecessaire_ &&
			manaNecessaire_ == pouvoir.manaNecessaire_);
}

ostream& operator<<(ostream& os, const Pouvoir& pouvoir) {
	os << pouvoir.nom_ << " necessite " << pouvoir.energieNecessaire_ << " energie et inflige " << pouvoir.nombreDeDegat_ << " degats " << endl;
	return os;
}

