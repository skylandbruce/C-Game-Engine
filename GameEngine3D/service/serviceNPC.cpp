/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "serviceNPC.h"

void ServiceNPC::initService(){
    Service::initService();
    setSupplyPeriod(5);
    setProcessCount(5);
}
