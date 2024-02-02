#include <stdio.h>
#include <stdlib.h>
#include "Project0.h"

void string_parse(char* str, inst_t* inst){
    int commacount=0;
    int i=0;
    char* tempstr=str;
    while (commacount<4){
   *(tempstr+i*(sizeof(char))) = *(str+i*(sizeof(char)));
   
    if (*(tempstr+i*(sizeof(char))) == ',') {
        *(tempstr+i*(sizeof(char)))=' ';
        
    }

    i++;  
   
    } 
    sscanf(tempstr, "%s %d %d %d",&(inst->type), &(inst->reg), &(inst->reg2imm), &(inst->reg3imm) );
    return;
}

void emitOutput(int icount, out_list_t* inst_list_out){
    char *filename = "out.txt";
    inst_count_t* count=&(inst_list_out->outlist[0]);
    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return;
    }
    // write to the text file
    for (int i = 0; i < icount; i++)
        fprintf(fp, "%0d,%0d,%0d,%0d,%0d\n", count->count1, count->count2, count->count3, count->count4, count->count5);
    count+=sizeof(inst_count_t);

    // close the file
    fclose(fp);
}

void initStructuresAndCounts(int* instcnt ,inst_list_t* inst_list_in, out_list_t* inst_list_out){

    

    inst_list_in=(inst_list_t*)malloc(sizeof(inst_list_t));
    inst_list_out=(out_list_t*)malloc(sizeof(out_list_t));
    //open file, copy contents of each line to array
    inst_t* inst=&(inst_list_in->list[0]);

    //int inst_num=0;

    FILE* ptr;
    char* str=NULL;
 
    // Opening file in reading mode
    ptr = fopen("test.in", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    
    while( fgets (str, 20, ptr)!=NULL ) {
      /* writing content to stdout */
      //parsestring
      string_parse(str, inst);
      inst+=(sizeof(inst_t));


   }
 
    
    
    fclose(ptr);
};
uint16_t WB(int* current_cycle){
    return *current_cycle;
};
uint16_t Mem(int* current_cycle){
    return *current_cycle;
};
uint16_t Execute(int* current_cycle){
    return *current_cycle;
};
uint16_t Decode(int* current_cycle, int completedInsts, inst_list_t* instructions_in){
    //check if using L, reg and now R, , ,reg
    //if true, borrow m-cycle value from last inst
    //set next cycle equal to that
    if(instructions_in->list[completedInsts].type=='R'){
        return *current_cycle;
    }
    else{
        //check if first of last register is last of current
        if(instructions_in->list[completedInsts].reg==instructions_in->list[completedInsts+1].reg3imm){
            *current_cycle+=1;
            return *current_cycle;
        }
        return *current_cycle;
    }
    return 0;

}; 
uint16_t Fetch(int* current_cycle){
    if(*current_cycle==0){
        return 00;
    }
    return *current_cycle;
    
};