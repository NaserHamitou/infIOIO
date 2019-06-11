//
//  AttaqueMagiquePoison.h
//  tp4
//
//  Created by Rania Abid on 2019-05-31.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef AttaqueMagiquePoison_h
#define AttaqueMagiquePoison_h
#include <string>
#include <vector>
#include <iostream>
#include "AttaqueMagique.h"
#include "Creature.h"

class AttaqueMagiquePoison:public AttaqueMagique

{
public:
    
    AttaqueMagiquePoison();
    AttaqueMagiquePoison(int duree);
    virtual ~AttaqueMagiquePoison();
    std::string obtenirtypeAttaque() const override;
    void appliquerAttaque(Creature & creature) override;
    bool estFini() override;
    
    
};

#endif /* AttaqueMagiquePoison_h */

