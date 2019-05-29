//
//  CreatureMagique.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,unsigned int defense, unsigned int pointDeVie, unsigned int energie) :Creature(nom,attaque,defense,pointDeVie,energie)
{
}
//constructeur pae copie
CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique): Creature(creatureMagique)
{
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    if (this!=&creatureMagique)
    {
        nom_=creatureMagique.nom_;
        attaque_=creatureMagique.attaque_;
        defense_=creatureMagique.defense_;
        pointDeVie_=creatureMagique.pointDeVie_;
        energie_=creatureMagique.energie_;
    }
    return *this;
    
}
std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique)
{
    os<<static_cast<Creature>(creatureMagique);
    return os;
    
}
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
    
}
