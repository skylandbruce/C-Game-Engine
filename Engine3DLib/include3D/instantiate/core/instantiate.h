/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\..\buffer\dna_buffer.h"
#include <set>

#pragma once
class Instantiate{
    private:
        list<DnaNPC*> Prototypes;  
        map<string, int> MapBufferSize;
        DnaNPCBuffer* dnaNPCBuffer = NULL;

    protected:
        int pushPrototype(DnaNPC* prototype);

        int setBufferSize(string name, int size);


    public:
        Instantiate(){
            dnaNPCBuffer = new DnaNPCBuffer();
        }
        
        virtual ~Instantiate(){
            delete dnaNPCBuffer;
            MapBufferSize.clear();
            for(auto protype : Prototypes){
                delete protype;
            }
            Prototypes.clear();
        } 
        
        virtual int registPrototype(){
            return 0;
        }

        virtual int initBufferSize(){
            return 0;
        }

        int reserveBuffer();

        DnaNPCBuffer* getBuffer(){
            return dnaNPCBuffer;
        }
};