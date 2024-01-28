/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include <map>
#include <string>

using namespace std;

#pragma once
enum TYPE_ATTR {
NONE,    
INT,
STRING,
TIME_T
};

template <typename T>
class AttributesPosition{
    private:    
        map<string, T> attributesMap;

    public:
        AttributesPosition(){}
        ~AttributesPosition(){
            attributesMap.clear();
        }

        map<string, T>* getAttributes(){
            return &attributesMap;
        }

        int setAttribute(string name, T value){
            attributesMap[name] = value;
            return 0;
        }

        T getAttribute(string name){
                return attributesMap.at(name);
        }

        T infect(string name, int scatter){
            attributesMap[name] += scatter;
            return attributesMap.at(name);
        }

};