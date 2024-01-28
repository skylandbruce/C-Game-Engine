/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "balloon.h"

void Balloon::initName(){
    setName("balloon");
}


void Balloon::initPosition(){
    setAttribute("x", x);
    setAttribute("y", y);
    setAttribute("z", z);
}

DnaNPC* Balloon::clone() const{
    Balloon* newCell = new Balloon();
    return newCell;
}

void Balloon::changeName(string name){
    mutantName(name);
}