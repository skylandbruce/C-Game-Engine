/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\objects\core\dna_npc.h"

#include <list>
#include <map>
#include <iostream>

using namespace std;

#pragma once
class DnaNPCBuffer{
    private:
        map<string, list<DnaNPC*>*> Cells;
        list<DnaNPC*>* Cell;
    protected:

    public:
        DnaNPCBuffer(){}
        ~DnaNPCBuffer(){    
            for(auto cell : Cells){
                for(auto dna : *cell.second){
                    delete dna;
                }
                delete cell.second;
            }
            Cells.clear();
        }
        
        int reserveCell(DnaNPC* dnaNPC, int count);

        list<DnaNPC*>* getCell(string name){
            return Cells.find(name)->second;
        }
        map<string, list<DnaNPC*>*>* getCells(){
            return &Cells;
        }

        DnaNPC* popDna(string name);

        int pushDna(DnaNPC* dna);

        void printBuffer();
};