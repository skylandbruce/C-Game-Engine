/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\..\include3D\objects\core\dna_npc.h" 
// #include "..\core\dna_npc.h" 

#pragma once
class Balloon : DnaNPC {
    private:
        int x=50;
        int y=2;
        int z=3;

    protected:
        virtual void initName() override;

        virtual void initPosition() override;

    public:
        Balloon(){}
        ~Balloon(){}

        // Business Object Duplacate
        virtual DnaNPC* clone() const override;

        // Business Object Change name
        void changeName(string name);

};