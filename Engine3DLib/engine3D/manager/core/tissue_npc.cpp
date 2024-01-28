/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "tissue_npc.h"

int TissuesNPC::addTissues(int depth_tissues){
    for(int i=0; i<depth_tissues; i++){
        Tissue = new list<DnaNPC*>;
        Tissues.push_back(Tissue);
    }
    this->depth_tissues += depth_tissues;
    return 0;
}

int TissuesNPC::pushDna(DnaNPC* dna, int depth){
    Tissues[depth]->push_back(dna);
    return 0;
}

DnaNPC* TissuesNPC::popDna(DnaNPC* dna, int depth){
    Tissue = getTissue(depth);

    if (!Tissue->empty()){
        auto it = find(Tissue->begin(), Tissue->end(), dna);

        if (it != Tissue->end()) {
            DnaNPC* foundDna = *it;
            Tissue->erase(it);
            return foundDna;
        } 
        else {
            cout << "DNA instance not found in the list." << endl;
            return nullptr;
        }
    }
    // 해당 tissue 가 empty
    cout<< "tissue["<<depth<<"]"<< "was Empty!!!";
    return nullptr;
}

// Buffer에 instance를 반환 
int TissuesNPC::returnDna(DnaNPC* dna){
    dnaNPCBuffer->pushDna(dna);
    return 0;
}
// Buffer에서 instance를 차용 
DnaNPC* TissuesNPC::borrowDna(string name){
    return dnaNPCBuffer->popDna(name);
}


void TissuesNPC::printTissues(){
    int depth=0;
    cout<<"---Status Tissues---"<<endl;
    for(auto tissue : Tissues){
        cout<<"<<<depth>>> : "<<depth<<endl;
        depth++;
        for(auto dna : *tissue ){
            cout<< dna->getName() <<"\t\t"\
            <<dna->getPosition()->getAttribute("x")<<" "\
            <<dna->getPosition()->getAttribute("y")<<" "    \
            <<dna->getPosition()->getAttribute("z")<<endl;
        }
    }
}
