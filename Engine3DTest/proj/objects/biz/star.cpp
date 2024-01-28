/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "star.h"

void Star::initName(){
    setName("star");
}

void Star::initPosition(){
        setAttribute("x", x);
        setAttribute("y", y);
        setAttribute("z", z);
}

DnaNPC* Star::clone() const{
    Star* newCell = new Star();

    return newCell;
}

void Star::changeName(string name){
    mutantName(name);
}
