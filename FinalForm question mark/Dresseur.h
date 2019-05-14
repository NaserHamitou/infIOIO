/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 07 mai 2019 (David Dratwa)
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include<iostream>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur();
	Dresseur(const string& nom);
	~Dresseur();

	string obtenirNom() const ;
	void modifierNom(const string& nom);
	
	ObjetMagique obtenirObjetMagique() const ;
	void modifierObjetMagique(ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);


	unsigned int obtenirNombreCreatures() const;

	Creature** obtenirCreatures() const;
	void modifierCreature(Creature** creatures);
	
	bool ajouterCreature(Creature& creature);
	bool retirerCreature(const string& nom);

	void affichage();

private:
	string nom_;
	Creature** creatures_;
	unsigned int nombreCreatures_;
	unsigned int nombreCreaturesMax_;
	ObjetMagique objetMagique_;

};

#endif