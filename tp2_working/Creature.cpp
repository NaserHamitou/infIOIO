#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
	
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::Creature(const Creature& creature) : attaque_(creature.attaque_), defense_(creature.defense_), pointDeVie_(creature.pointDeVie_),
pointDeVieTotal_(creature.pointDeVieTotal_), energie_(creature.energie_), energieTotal_(creature.energieTotal_), experience_(creature.experience_),
experienceNecessaire_(creature.experienceNecessaire_), niveau_(creature.niveau_), pouvoirs_(creature.pouvoirs_)
{}

Creature::~Creature() // A MODIFIER... (si necessaire)
{
	pouvoirs_.clear();
}

string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return pouvoirs_;					            	
}

void Creature::apprendrePouvoir(const Pouvoir& pouvoir) {

	pouvoirs_.push_back(new Pouvoir(pouvoir));
}

void Creature::oublierPouvoir(Pouvoir* pouvoir) {
	for (int i = 0; i < pouvoirs_.size(); i++) {
		if (*pouvoirs_[i] == *pouvoir) {
			pouvoirs_[i] = pouvoirs_[pouvoirs_.size() - 1];
			pouvoirs_.pop_back();
			cout << nom_ << " a oublie " << pouvoir->obtenirNom() << endl;
		}
		else
			cout << "Impossible : " << nom_ << " ne possedait pas ce pouvoir. " << endl;
	}
}

void Creature::attaquer(Pouvoir& pouvoir, Creature & creature)// A MODIFIER... (si necessaire)
{
	if (energie_ >= pouvoir.obtenirEnergieNecessaire()) 
    {
		if (creature.obtenirPointDeVie() >= 0) 
        {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir.obtenirEnergieNecessaire();
			}
			else {
				cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(const string& nom) 
{
	nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(const vector<Pouvoir*>& pouvoirs) // A MODIFIER... (si necessaire)
{
	pouvoirs_ = pouvoirs;
}

Creature& Creature::operator=(const Creature& creature) {
	if (this != &creature) {
		pouvoirs_ = creature.pouvoirs_;
		nom_ = creature.nom_;
		attaque_ = creature.attaque_;
		defense_ = creature.defense_;
		pointDeVie_ = creature.pointDeVie_;
		pointDeVieTotal_ = creature.pointDeVieTotal_;
		energie_ = creature.energie_;
		energieTotal_ = creature.energieTotal_;
		experience_ = creature.experience_;
		experienceNecessaire_ = creature.experienceNecessaire_;
		niveau_ = creature.niveau_;

	}

	return *this;
}

bool Creature::operator==(const Creature& creature) const{
	return(nom_ == creature.nom_ && attaque_ == creature.attaque_ && pointDeVie_ == creature.pointDeVie_ &&
		pointDeVieTotal_ == creature.pointDeVieTotal_ && energie_ == creature.energie_  && 
		energieTotal_ == creature.energieTotal_ && experience_ == creature.experience_ && 
		experienceNecessaire_ == creature.experienceNecessaire_ && niveau_ == creature.niveau_);
}

bool Creature::operator==(const string& nom) const {
	return (nom_ == nom);
}

bool operator==(const string& nom, const Creature& creature) {
	return (nom == creature.nom_);
}

ostream& operator<<(ostream& os, const Creature& creature) {

	os << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << "en defense, " << endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << endl
		<< "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << "d'XP" << endl
		<< "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau " << endl;
	os << "Pouvoirs : " << endl;
	if (creature.pouvoirs_.size() == 0)
		os << creature.nom_ << " ne connait aucun pouvoir" << endl;
	for (int i = 0; i < creature.pouvoirs_.size(); i++)
		os << *creature.pouvoirs_[i] << endl;
	os << endl;

	return os;
}


// _______TP2________
