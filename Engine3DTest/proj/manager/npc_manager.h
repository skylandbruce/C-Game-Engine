/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\include3D\manager\core\tissue_manager.h"
// #include "core\tissue_manager.h"

#define DEPTH_DEFAULT 7

class NpcManager:public TissuesManager{
    private:
    int *portion;

    protected:
        virtual int initPortion() override;

        virtual int reserveTissues() override;

    public:
        NpcManager(){
            portion = new int[DEPTH_DEFAULT]{1,1,1,1,2,2,2};
        }
        ~NpcManager(){
            delete portion;
        }

        virtual int manualProcess(string name, int depth);

};