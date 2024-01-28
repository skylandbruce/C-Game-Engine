/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\..\objects\core\dna_npc.h"
#include "..\..\buffer\dna_buffer.h"

#include <list>
#include <deque>
using namespace std;

#pragma once
class TissuesNPC{
    private:
        DnaNPCBuffer* dnaNPCBuffer;
        deque<list<DnaNPC*>*> Tissues;
        list<DnaNPC*>* Tissue;
        int depth_tissues = 0;

    protected:

    public:
        TissuesNPC(){}
        ~TissuesNPC(){
            for(auto tissue : Tissues){
                for(auto dna : *tissue){
                    delete dna;
                }
                tissue->clear();
                delete tissue;
            }
            Tissues.clear();
        }


        void setDnaBuffer(DnaNPCBuffer* dnaNPCBuffer){
            this->dnaNPCBuffer = dnaNPCBuffer;
        }
        DnaNPCBuffer* getDnaBuffer(){
            return dnaNPCBuffer;
        }

        int getMaxDepth(){
            return depth_tissues;
        }

        list<DnaNPC*>* getTissue(int depth){
            return Tissues[depth];
        }

        deque<list<DnaNPC*>*>* getTissues(){
            return &Tissues;
        }

        //////////////////////////////////
        //  Method Operator
        //////////////////////////////////
        int addTissues(int depth_tissues);

        int pushDna(DnaNPC* dna, int depth);

        DnaNPC* popDna(DnaNPC* dna, int depth);

        // Buffer에 instance를 반환
        int returnDna(DnaNPC* dna);
        // Buffer에서 instance를 차용
        DnaNPC* borrowDna(string name);

        void printTissues();
};