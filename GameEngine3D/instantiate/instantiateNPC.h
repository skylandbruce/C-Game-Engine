/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "core\instantiate.h"
#include "..\objects\biz\balloon.h"
#include "..\objects\biz\star.h"

#pragma once

#define SIZE_NPC_BUFFER 40
#define SIZE_BOSS_BUFFER 30

class InstantiateNPC:Instantiate{
    
    private:
    Balloon* balloon;
    Balloon* balloon_boss;
    Star* star;
    Star* star_boss;

    protected:

    public:
    InstantiateNPC(){
        balloon = new Balloon();
        
        balloon_boss = new Balloon();
 
        star = new Star();

        star_boss = new Star();
    }
    ~InstantiateNPC(){}

    virtual int registPrototype() override;

    virtual int initBufferSize() override;

};