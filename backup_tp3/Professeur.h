#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Dresseur.h"
#include "OutilScientifique.h"
using namespace std;

class Professeur : public Dresseur
{
public:
	//Constructeur parametre
	Professeur(const string& nom, const string& equipe);

	//Constructeur par copie
	Professeur(const Professeur& prof);

	//Destructeur
	~Professeur();

	//La méthode de modification de l’attribut outil
	void modifierOutilScientifique(OutilScientifique* outil);

	//Methode soigner 
	void soigner(Creature& creature) const;

	//Operator surcharge = 
	Professeur& operator=(const Professeur& prof);

	//Methode utiliserOutil 
	void utiliserOutil(Creature& creature) const;


private:

	OutilScientifique* outilScientifique_;

};

#endif