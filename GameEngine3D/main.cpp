#include "main.h"

int main(){
    ServiceNPC* serviceNPC = new ServiceNPC();
    serviceNPC->initService();
    serviceNPC->start();

    delete serviceNPC;
    return 0;
 }