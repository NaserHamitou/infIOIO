/*
Fichier: Pouvoir.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 07 Mai 2019 (David Dratwa)
Description: La classe Pouvoir correspond aux differents attaques 
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom, 
		unsigned int nombreDeDegat, unsigned int manaNecessaire);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat();
	unsigned int obtenirManaNecessaire();
	string obtenirNom();

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierManaNecessarie(unsigned int manaNecessaire);
	void modifierNom(string& nom);

	void description();

private:
	string nom_;
	unsigned int nombreDeDegat_;
	unsigned int manaNecessaire_;

};

#endif