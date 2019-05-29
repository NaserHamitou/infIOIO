//
//  pouvoirPoison.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-27.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "pouvoirPoison.h"

pouvoirPoison ::pouvoirPoison(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire):Pouvoir(nom,nombreDeDegat,energieNecessaire)
{
  type_=TypeEtat_empoisonne;
}

pouvoirPoison :: pouvoirPoison(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):Pouvoir(nom,nombreDeDegat,energieNecessaire)
{
    duree_=duree;
    type_=TypeEtat_empoisonne;

}

std::ostream& operator<<(std::ostream& os, const pouvoirPoison& pouvoirpoison)
{
    os<<static_cast<Pouvoir>(pouvoirpoison)<<std::endl<<" il peut empoisonner la cible " <<std::endl;
    return os;
}

void pouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie)
{
    creatureEnnemie.modifierEtat(new EtatEmpoisonne("poison",duree_)); 
    
}
