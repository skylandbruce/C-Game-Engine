/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "npc_manager.h"

int NpcManager::initPortion(){
    updatePortion(portion);
    return 0;
}
int NpcManager::reserveTissues(){
    addTissues(DEPTH_DEFAULT);
    return 0;
}

int NpcManager::manualProcess(string name, int depth){
    TissuesManager::manualProcess(name, depth);
    return 0;    
}