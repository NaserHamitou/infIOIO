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
	Creature(string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir);
	~Creature();
	
	string obtenirNom();
	unsigned int obtenirDefense();
	unsigned int obtenirPointDeVie();
	unsigned int obtenirPointDeVieTotal();
	unsigned int obtenirEnergie();
	unsigned int obtenirEnergieTotale();
	unsigned int obtenirExperience();
	unsigned int obtenirExperienceNecessaire();
	unsigned int obtenirNiveau();
	unsigned int obtenirAttaque();
	Pouvoir obtenirPouvoir();

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