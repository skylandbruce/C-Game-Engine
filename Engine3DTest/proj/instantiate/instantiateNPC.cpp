/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "instantiateNPC.h"


int InstantiateNPC::registPrototype(){
    balloon_boss->changeName("b_boss");
    star_boss->changeName("s_boss");

    pushPrototype((DnaNPC*)balloon); 
    pushPrototype((DnaNPC*)balloon_boss); 
    pushPrototype((DnaNPC*)star);
    pushPrototype((DnaNPC*)star_boss); 
    
    return 0;
}

int InstantiateNPC::initBufferSize(){
    setBufferSize("balloon", SIZE_NPC_BUFFER);
    setBufferSize("star", SIZE_NPC_BUFFER);  
    setBufferSize("b_boss", SIZE_BOSS_BUFFER);
    setBufferSize("s_boss", SIZE_BOSS_BUFFER);  
    
    return 0;
}
