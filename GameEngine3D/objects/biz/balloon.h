/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\core\dna_npc.h" 

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

        // Business Object 에서 DnaNPC를 복제하는 clone 함수의 재정의
        virtual DnaNPC* clone() const override;

        // Business Object 의 name만 변경한 Business Object 생성 용도 
        void changeName(string name);

};