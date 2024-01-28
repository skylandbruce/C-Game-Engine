/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "instantiate.h"

int Instantiate::pushPrototype(DnaNPC* prototype){
    if(!prototype->isMutant())
        prototype->initName();
    prototype->initPosition();
    
    Prototypes.push_back(prototype);
    return 0;
}

int Instantiate::setBufferSize(string name, int size){
    MapBufferSize[name] = size;
    return 0;
}

int Instantiate::reserveBuffer(){
    int size = 0;
    for(auto prototype : Prototypes){
        auto proto_size = MapBufferSize.find(prototype->getName());
        if(proto_size != MapBufferSize.end()){    
            dnaNPCBuffer->reserveCell(prototype, proto_size->second);
        }
        else{
            cout<<"cannot find prototype size";
            return -1;
        }
    }
    return 0;
}