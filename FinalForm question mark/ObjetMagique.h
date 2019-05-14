/*
Fichier: ObjetMagique.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 07 mai 2019 (David Dratwa)
Description: La classe ObjetMagique correspond aux differents objets utilisable
			par le dresseur sur ses creatures
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string obtenirNom();
	int obtenirBonus();

	void modifierNom(string& nom);
	void modifierBonus(int bonus);

	void affichage() ;

private:
	string nom_;
	int bonus_;
};

#endif
