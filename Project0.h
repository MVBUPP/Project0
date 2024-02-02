#ifndef PROJECT0_H_
#define PROJECT0_H_

#include <stdint.h>

typedef struct inst{
        char type;
        int reg;
        int reg2imm;
        int reg3imm;
    }inst_t;

typedef struct instcnt{
    int count1;
    int count2;
    int count3;
    int count4;
    int count5;
}inst_count_t;

typedef struct instlst{
    inst_t list[32];
}inst_list_t;

typedef struct outlst{
    inst_count_t outlist[32];
}out_list_t;

void initStructuresAndCounts(int* instcnt ,inst_list_t* inst_list_in, out_list_t* inst_list_out);
uint16_t WB(int* current_cycle);
uint16_t Mem(int* current_cycle);
uint16_t Execute(int* current_cycle);
uint16_t Decode(int* current_cycle, int completed, inst_list_t* instructions_in); 
uint16_t Fetch(int* current_cycle);
void emitOutput(int icount, out_list_t* inst_list_out);

#endif