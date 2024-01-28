/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "service.h"

int Service::pushStream(Stream* stream){
    Streams.push_back(stream);
    return 0;
}

void Service::initService(){
    instantiate->registPrototype();
    instantiate->initBufferSize();
    instantiate->reserveBuffer();

    tissuesNPC->setDnaBuffer(instantiate->getBuffer());

    manager->setTissueNPC(tissuesNPC);
    manager->reserveTissues();
    manager->initPortion();

    for(auto stream : Streams){
        stream->setTissueNPC(tissuesNPC);
        stream->initInfluence();
        stream->initScatterRange();
        stream->initBoundary();
    }
} 

int Service::start(){
    for(int i=0; i< processCount; i++){
        if(i%supplyPeriod == 0)
            manager->process(); 
        for(auto stream : Streams){
            stream->action();
        }
        
    // For Debug
    Service::getManager()->getTissue()->getDnaBuffer()->printBuffer(); 
    Service::getManager()->getTissue()->printTissues();
    }
    return 0;
}