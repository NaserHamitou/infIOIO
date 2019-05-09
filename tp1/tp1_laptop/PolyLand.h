/*
Fichier: PolyLand.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 07 mai 2019 (David Dratwa)
Description: Polyland represente le pays que l'on va explorer, il va contenir les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur);
	bool ajouterCreature(Creature& creature);

	bool retirerDresseur(string& nom);
	bool retirerCreature(string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature& creature);
	bool relacherCreature(Dresseur* dresseur, Creature& creature);
	
	void infoDresseur(string& nom) ;

private:
	Dresseur** dresseurs_;
	unsigned int nombreDresseurs_;
	Creature** creatures_;
	unsigned int nombreCreatures_;

};
#endif