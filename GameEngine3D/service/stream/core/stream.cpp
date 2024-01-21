/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "stream.h"

// private
int Stream::generateRandomInt(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

int Stream::getFactor(pair<int, int> scatter){
    int hFactor = generateRandomInt(scatter.first, scatter.second);
    return hFactor;
}

int Stream::checkBoundary(string axis, int sign){
    return (Boundary[axis].first <= sign && sign < Boundary[axis].second)? IN_BOUND : OUT_BOUND;  
}
int Stream::infectDNA(DnaNPC* dna){
    AttributesPosition<int>* attributesPosition = dna->getPosition();
    int sign = 0;
    int bound = IN_BOUND;
    for(auto axis: ScatterRange){
        sign = attributesPosition->infect(axis.first, getFactor(axis.second));
        bound = checkBoundary(axis.first, sign); 
        if(bound == OUT_BOUND){
            // For Debug
            cout<<"************"<<endl;
            cout<<"OUT_BOUND  "<< dna->getName() <<"=>"<< "axis: "<<axis.first<<" = "<< sign <<endl;
            break;
        }
    }
    return bound;
}

// protected
void Stream::addInfluence(int depth){
    influence.insert(depth);
}
void Stream::deleteInfluence(int depth){
    auto it = influence.find(depth);

    if (it != influence.end()) {
        influence.erase(it);
    }
    else{
        cout << " cannot found influence " << endl;
    }
}

void Stream::setScatterRangeAttribute(string name, int min, int max){
    ScatterRange[name] = make_pair(min, max);
}

pair<int, int> Stream::getScatterRangeAttribute(string name){
    return ScatterRange.at(name);
}

void Stream::setBoundary(string name, int minBound, int maxBound){
    Boundary[name] = make_pair(minBound, maxBound);
}

// public
int Stream::action(){
    int amount = 0;
    int bound = IN_BOUND;
    int currentDepth = 0;
    AttributesPosition<int>* attributesPosition;
    list<DnaNPC*>* Tissue;
    for(auto depth: influence){
        Tissue = tissuesNPC->getTissue(depth);

        for (auto dna = Tissue->begin(); dna != Tissue->end();) {
            // For Debug
            // if(*dna == nullptr) 
            //     return -1;

            if(infectDNA(*dna) == OUT_BOUND){
                tissuesNPC->returnDna(*dna);
                dna = Tissue->erase(dna);
            }                 
            else{
                attributesPosition = (*dna)->getPosition();
                currentDepth = attributesPosition->getAttribute("z");
                // depth 에 변화가 일어나, 소속될 tissue로의 transition 
                if (depth != currentDepth){
                    tissuesNPC->pushDna(*dna, currentDepth);
                    // iterator dna를 증가시키지 않음
                    dna = Tissue->erase(dna);
                } 
                else{
                    // 조건에 맞지 않으면 dna를 증가시킴
                    ++dna;
                }

            }
        }
    }
    return 0;
}
