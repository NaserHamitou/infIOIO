//
//  EtatConfus.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "EtatConfus.h"
EtatConfus:: EtatConfus(const std::string& nom):EtatCreature(nom)
{
    
}
EtatConfus :: EtatConfus(const std::string& nom, unsigned int duree):EtatCreature(nom,duree)
{
    
}

std::ostream& operator<<(std::ostream& o, const EtatConfus& etatConfus)
{
o<<"état confus"<< std::endl;
    return o;
}
