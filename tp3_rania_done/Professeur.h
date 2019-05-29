//
//  Professeur.h
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef Professeur_h
#define Professeur_h
#include "Dresseur.h"
#include "OutilScientifique.h"
#include <iostream>
#include <string>


class Professeur : public Dresseur
{
public:
    
    Professeur(const std::string& nom, const std::string& equipe);
    Professeur(const Professeur& professeur);
    ~Professeur();
    OutilScientifique* obtenirOutilScientifique()const;
    void modifierOutilScientifique(OutilScientifique* outilScientifique);
    void soigner(Creature& creature) const;
    Professeur& operator=(const Professeur& professeur);
    void utiliserOutil(Creature& creature);
    
private:
    OutilScientifique* outilScientifique_;
};

#endif /* Professeur_h */
