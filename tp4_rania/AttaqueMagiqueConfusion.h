//
//  AttaqueMagiqueConfusion.h
//  tp4
//
//  Created by Rania Abid on 2019-05-31.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef AttaqueMagiqueConfusion_h
#define AttaqueMagiqueConfusion_h
#include <iostream>
#include <string>
#include <vector>
#include "AttaqueMagique.h"
#include "Creature.h"

class AttaqueMagiqueConfusion:public AttaqueMagique

{
public:
    AttaqueMagiqueConfusion();
    AttaqueMagiqueConfusion(int duree);
    virtual ~AttaqueMagiqueConfusion();
    std::string obtenirTypeAttaque() const override;
    void appliquerAttaque(Creature & creature) override;
    bool estFini() override;
    
    
};
#endif /* AttaqueMagiqueConfusion_h */
