//
//  pouvoirHallucinogene.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "pouvoirHallucinogene.h"


pouvoirHallucinogene::pouvoirHallucinogene(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire):Pouvoir(nom,nombreDeDegat,energieNecessaire)
{
    type_=TypeEtat_confus;
}
pouvoirHallucinogene::pouvoirHallucinogene(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):Pouvoir(nom,nombreDeDegat,energieNecessaire)
{
    type_=TypeEtat_confus;
    duree_=duree;
}

std::ostream& operator<<(std::ostream& os, const pouvoirHallucinogene& pouvoirHallucinogene)
{
    os<<static_cast<Pouvoir>(pouvoirHallucinogene);
    return os;
    
}
void pouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie)
{
    creatureEnnemie.modifierEtat(new EtatConfus("confus", duree_));
    
}
