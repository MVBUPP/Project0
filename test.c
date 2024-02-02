#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Project0.h>


int main()
{
    inst_list_t* instructions_in=NULL;
    out_list_t* instructions_out=NULL;
    
    int icount=0;
    int current_cycle=0;
    int completedInsts=0;

    initStructuresAndCounts(&icount, instructions_in, instructions_out); 
    inst_count_t* outcycle= &(instructions_out->outlist[0]);
    while(completedInsts<icount){
    outcycle->count1=Fetch(&current_cycle);
    outcycle->count2=Decode(&current_cycle, completedInsts, instructions_in);
    outcycle->count3=Execute(&current_cycle);
    outcycle->count4=Mem(&current_cycle);
    outcycle->count5=WB(&current_cycle);
    outcycle+=sizeof(inst_count_t);
    current_cycle=current_cycle-03; 
    completedInsts+=1;
  }
  emitOutput(icount, instructions_out); 
    free(instructions_out);
    free(instructions_in);

    
    return 0;
}
