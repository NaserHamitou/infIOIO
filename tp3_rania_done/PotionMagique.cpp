//
//  PotionMagique.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "PotionMagique.h"


PotionMagique:: PotionMagique():ObjetMagique()
{}

PotionMagique::PotionMagique(const std::string &nom, int bonus):ObjetMagique(nom,bonus)
{}

std::ostream& operator<<(std::ostream& o, const PotionMagique& potionMagique)
{
    o<< "l'objet "<<std::endl<<potionMagique.obtenirNom()<<"fournit "<<std::endl;
    return o;
}


void PotionMagique::utiliserSur(Creature& creature) const
{
    if((creature.obtenirPointDeVie() + bonus_) <= creature.obtenirPointDeVieTotal())
        creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
    else
    {
        creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
    }
}


