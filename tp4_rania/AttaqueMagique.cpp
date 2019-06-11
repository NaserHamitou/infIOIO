//
//  AttaqueMagique.cpp
//  tp4
//
//  Created by Rania Abid on 2019-05-30.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique()
{}

AttaqueMagique::AttaqueMagique(int duree)
{
    duree_=duree;
}

AttaqueMagique::~AttaqueMagique()
{}

int AttaqueMagique::obtenirDuree() const

{
    return duree_;
    
}

void AttaqueMagique::modifierDuree(int duree)
{
    duree_=duree;
}




std::string AttaqueMagique::obtenirTypeAttaque()const
{
    return "AttaqueMagique";
}



/*void AttaqueMagique::appliquerAttaque(Creature & creature) //ici eske faut jst declare?
 

{
    if (duree_ > 0 && creature.obtenirPointDeVie() >= 5)
    {
        unsigned int pointDeVie = creature.obtenirPointDeVie();
        if (rand() % 3 == 0)
        {
            creature.modifierPointDeVie(pointDeVie - 2);
        }
        duree_--;
    }
}*/

bool AttaqueMagique::estFini()
{
    return true;
}


std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaqueMagique)
{
    os<<"cette créature de la classe CreatureMagique a aussi une attaque magique de type class"<< attaqueMagique.obtenirTypeAttaque() << " qui a une duree de " << attaqueMagique.duree_;
    return os;
}
