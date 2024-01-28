/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "tissue_npc.h"
#include "..\..\buffer\dna_buffer.h"

using namespace std;

#pragma once

#define PORTION_DEFAULT 1

class TissuesManager{
    private:
        DnaNPCBuffer* dnaNPCBuffer;
        TissuesNPC* tissuesNPC;
        // distribute count for each depth 
        deque<int> portion;

    protected:
        void updatePortion(int *new_portion);

        deque<int>* getPorsion(){
            return &portion;
        }

        void addTissues(int depth_tissues);

        virtual int updateTissues(list<DnaNPC*>* Cell);

    public:
        TissuesManager(){
        }
        ~TissuesManager(){
            portion.clear();
        }

        void setTissueNPC(TissuesNPC* tissuesNPC){
            this->tissuesNPC = tissuesNPC;
            dnaNPCBuffer = tissuesNPC->getDnaBuffer();
        }
        TissuesNPC* getTissue(){
            return tissuesNPC;
        }

        virtual int reserveTissues();
        
        virtual int initPortion();

        virtual int manualProcess(string name, int depth);

        int process();

};
