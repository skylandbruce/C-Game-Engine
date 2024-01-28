/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include <iostream>
#include <random>
#include <set>
#include <map>
#include "..\..\..\manager\core\tissue_npc.h"

using namespace std;

#pragma once
#define OUT_BOUND -1
#define IN_BOUND 0

class Stream{
    private:
        set<int> influence;        
        map<string, pair<int, int>> ScatterRange;
        map<string, pair<int, int>> Boundary;

        TissuesNPC* tissuesNPC = nullptr;
    
        int generateRandomInt(int min, int max);

        int getFactor(pair<int, int> scatter);

        int checkBoundary(string axis, int amount);

        int infectDNA(DnaNPC* dna);

    protected:
        void addInfluence(int depth);

        void deleteInfluence(int depth);

        void setScatterRangeAttribute(string name, int min, int max);

        pair<int, int> getScatterRangeAttribute(string name);

        void setBoundary(string name, int minBound, int maxBound);

    public:
        Stream(){}
        ~Stream(){
            influence.clear();
            ScatterRange.clear();
            Boundary.clear();
        }

        virtual void initInfluence(){}
        
        virtual void initScatterRange(){}
        // must called for init axis "z" depth
        virtual void initBoundary(){
            setBoundary("z", 0, tissuesNPC->getMaxDepth());
        }

        void setTissueNPC(TissuesNPC* tissuesNPC){
            this->tissuesNPC = tissuesNPC;
        }
        
        virtual int action();

};