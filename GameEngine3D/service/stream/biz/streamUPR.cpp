/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "streamUPR.h"

void StreamUpR::initInfluence(){
    addInfluence(0);
    addInfluence(1);
    addInfluence(2);
    addInfluence(3);
}
void StreamUpR::initScatterRange(){
    setScatterRangeAttribute("x", -2, 10);
    setScatterRangeAttribute("y", -1, 20);
    setScatterRangeAttribute("z", -1, 1);
}

void StreamUpR::initBoundary(){
    Stream::initBoundary();
    setBoundary("x", 0, 100);
    setBoundary("y", 0, 100);
}
