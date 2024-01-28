/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/

#include "main.h"

int main(){
    ServiceNPC* serviceNPC = new ServiceNPC();
    serviceNPC->initService();
    serviceNPC->start();

    delete serviceNPC;
    return 0;
 }