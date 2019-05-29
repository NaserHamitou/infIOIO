//
//  GreenBull.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-26.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "GreenBull.h"
GreenBull::GreenBull():ObjetMagique()
{}

GreenBull::GreenBull(const std::string &nom, int bonus):ObjetMagique(nom,bonus)
{}

std::ostream& operator<<(std::ostream& o, const GreenBull& greenBull)
{
    o<<"l'objet "<<greenBull.nom_<<"fournit un bonus de "<<greenBull.bonus_<<std::endl;
    return o;
}

void GreenBull::utiliserSur(Creature& creature) const
{
    if(creature.obtenirEnergie()+bonus_< creature.obtenirEnergieTotale())
        creature.modifierEnergie(creature.obtenirEnergie()+bonus_);
    else
        creature.modifierEnergie(creature.obtenirEnergieTotale());
    
}
