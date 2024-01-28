/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "dna_buffer.h"

DnaNPC* DnaNPCBuffer::popDna(string name){
    Cell = getCell(name);
    if(Cell->empty()) return nullptr;

    DnaNPC* dna = Cell->front();
    Cell->pop_front();
    return dna;
} 

int DnaNPCBuffer::pushDna(DnaNPC* dna){
    // before push back to buffer, must initiate position
    dna->initPosition(); 
    Cells[dna->getName()]->push_back(dna);
    return 0;
}


void DnaNPCBuffer::printBuffer(){
    cout<<"---Remained Buffer---"<<endl;
    for(auto cell:Cells){
        int count = 0;
        cout<<"<"<<cell.first<<">"<<endl;  // for debug
        for(auto dna:*Cells.at(cell.first)){
            count++;
        }
        cout<<"count: "<< count << endl;
    }
}

int DnaNPCBuffer::reserveCell(DnaNPC* prototype, int count){
    DnaNPC* dna;
    Cells[prototype->getName()] = new list<DnaNPC*>;
    for( int i=0; i < count; i++){
        dna = prototype->clone();
        if(prototype->isMutant()) dna->mutantName(prototype->getName());      
        else dna->initName();
        dna->initPosition();

        try{
            Cells.at(prototype->getName())->push_back(dna);
        } 
        catch (const out_of_range& e) {
            cout<<"out of map key!!!"<<endl;
            return -1;
        }
    }
    return 0;
}