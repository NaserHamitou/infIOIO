#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	Pouvoir(const Pouvoir& pouvoir);
	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	unsigned int obtenirManaNecessaire() const;
	string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const string& nom);

	Pouvoir operator=(const Pouvoir& pouvoir);

	bool operator==(const Pouvoir& pouvoir);

	friend ostream& operator<<(ostream& os, const Pouvoir& pouvoir);

	//________TP2________

private:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
	unsigned int manaNecessaire_;

};

#endif