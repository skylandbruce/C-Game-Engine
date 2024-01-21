/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "tissue_manager.h"

void TissuesManager::updatePortion(int *new_portion){
    if(!portion.empty()) portion.clear();
    for(int i=0; i<tissuesNPC->getMaxDepth(); i++){
        portion.push_back(new_portion[i]);
    }
}

int TissuesManager::updateTissues(list<DnaNPC*>* Cell){
    for(auto tissue: *tissuesNPC->getTissues()){
        if(Cell->empty() == true) break;
        for(int i=0; i<portion[i]; i++){
            DnaNPC* dna = Cell->front();
            Cell->pop_front();
            tissue->push_back(dna);
        }
    }
    return 0;
}

int TissuesManager::initPortion(){
    if(!portion.empty()) portion.clear();
    for(int i=0; i<tissuesNPC->getMaxDepth(); i++){
        portion.push_back(PORTION_DEFAULT);
    }
    return 0;
}
int TissuesManager::reserveTissues(){
    return 0;
}

void TissuesManager::addTissues(int depth_tissues){
    tissuesNPC->addTissues(depth_tissues);
}

int TissuesManager::manualProcess(string name, int depth){
    DnaNPC* dna = nullptr;
    for(int i=0; i < portion[depth]; i++){
        dna = tissuesNPC->borrowDna(name);
        if(dna == nullptr) return -1;
        dna->getPosition()->setAttribute("z", depth);
        tissuesNPC->pushDna(dna, depth);               
    }
    return 0;
}

int TissuesManager::process(){
    for(auto cell : *dnaNPCBuffer->getCells()){
        int depth = 0;
        for(auto tissue: *tissuesNPC->getTissues()){
            if(manualProcess(cell.first, depth) == -1) break;
            depth++;
        }
    }
    return 0;
}