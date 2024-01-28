/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\stream\core\stream.h"
#include "..\..\manager\core\tissue_manager.h"
#include "..\..\instantiate\core\instantiate.h"
#include <iostream>
#include <list>

using namespace std;

#define SUPPLY_PERIOD 5
#define PROCESS_COUNT 100

class Service{
    private:
        Instantiate* instantiate = NULL;
        TissuesNPC* tissuesNPC = NULL;
        TissuesManager *manager = NULL;
        list<Stream*> Streams;

        int supplyPeriod = 1;
        int processCount = 10;

    protected:
        void setInstantiate(Instantiate* instantiate){
            this->instantiate = instantiate;
        }

        void setManager(TissuesManager* manager){
            this->manager = manager;
        }

        TissuesManager* getManager(){
            return manager;
        }

        int pushStream(Stream* stream);

        void setSupplyPeriod(int value){
            supplyPeriod = value;
        }

        void setProcessCount(int value){
            processCount = value;
        }

    public:
        Service(){
            tissuesNPC = new TissuesNPC();
        }
        virtual ~Service(){
            for(auto stream : Streams){
                delete stream;
            }
            Streams.clear();
            delete instantiate;
            delete tissuesNPC;
            delete manager;
        }
        
        virtual void initService();

        // start service
        virtual int start();

};