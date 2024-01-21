/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "streamUPL.h"

void StreamUpL::initInfluence(){
    addInfluence(4);
    addInfluence(5);
    addInfluence(6);
}
void StreamUpL::initScatterRange(){
    setScatterRangeAttribute("x", -10, 2);
    setScatterRangeAttribute("y", -1, 10);
    setScatterRangeAttribute("z", -1, 1);
}

void StreamUpL::initBoundary(){
    Stream::initBoundary();
    setBoundary("x", 0, 100);
    setBoundary("y", 0, 100);
}