/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\meta\metainfo.h"

using namespace std;

#pragma once

class DnaNPC {
private:
    bool mutant = false;
    string name;
    AttributesPosition<int> *attributesPosition = NULL;

protected:

    void setName(string name){
        this->name = name;
    }

    int setAttribute(string key_name, int value){
        attributesPosition->setAttribute(key_name, value);
        return 0; 
    }

    int getAttribute(string key_name){
        return attributesPosition->getAttribute(key_name);        
    } 
    
public:
    DnaNPC(){
        attributesPosition = new AttributesPosition<int>();
        // initName();
        // initPosition();
    }
    ~DnaNPC(){
        delete attributesPosition;
    }

    virtual void initName(){}

    void mutantName(string name){
        mutant = true;
        this->name = name;
    }

    bool isMutant(){
        return mutant;
    }

    virtual void initPosition(){}

    virtual DnaNPC* clone() const {
        return nullptr;
    }

    AttributesPosition<int>* getPosition(){
        return attributesPosition;
    }

    string getName(){
        return name;
    }

};