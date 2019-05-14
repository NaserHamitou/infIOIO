/*
Fichier: Creature.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 07 Mai 2019 (David Dratwa)
Description: Les creatures sont des etres destines au combat 
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>
#include "ObjetMagique.h"
#include "Pouvoir.h"

class Creature
{
public:
	Creature();
	Creature(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir);
	~Creature();
	
	string obtenirNom() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	unsigned int obtenirAttaque() const;
	Pouvoir obtenirPouvoir() const;

	void attaquer(Creature& creature);
	int experienceGagnee(Creature& creature);
	
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoir(Pouvoir pouvoir);

	void information() ;

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	Pouvoir pouvoir_;
	
};

#endif