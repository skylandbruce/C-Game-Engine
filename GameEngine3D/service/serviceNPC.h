/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "core\service.h"
#include "..\instantiate\instantiateNPC.h"
#include "..\manager\npc_manager.h"
#include "stream\biz\streamUPR.h"
#include "stream\biz\streamUPL.h"

class ServiceNPC:Service{
    private:

    protected:

    public:
    ServiceNPC(){
        setInstantiate((Instantiate*) new InstantiateNPC());
        setManager((TissuesManager*)new NpcManager());
        pushStream((Stream*)new StreamUpR());
        pushStream((Stream*)new StreamUpL());
    }
    ~ServiceNPC() override {
    }
    virtual void initService() override;

    virtual int start() override{
        Service::start();

        return 0;
    }


};
