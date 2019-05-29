//
//  pouvoirSoporifique.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "pouvoirSoporifique.h"

pouvoirSoporifique::pouvoirSoporifique(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire):Pouvoir(nom, nombreDeDegat,energieNecessaire)
{
    type_=TypeEtat_endormi;
}

pouvoirSoporifique::pouvoirSoporifique(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire,int duree):Pouvoir(nom, nombreDeDegat,energieNecessaire)
{
    type_=TypeEtat_endormi;
    duree_=duree;
}

std::ostream& operator<<(std::ostream& os, const pouvoirSoporifique& pouvoirSoporifique)
{
    os<<static_cast<Pouvoir>(pouvoirSoporifique)<<std::endl<<"il peut endormir la cible "<<std::endl;
    return os;
}

void pouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie)
{
    creatureEnnemie.modifierEtat(new EtatEndormi("endormi",duree_));
}
