#include "stdio.h"
#include "def.h"


void print_board(){

    int index = 0;
    for(index = 0; index < BRD_SQ_NUM; index++){
        if (index % 10 == 0){
            printf("\n");
        }
        printf("%5d", sq120_to_sq64[index]);
    }

    printf("\n");
    printf("\n");

    for(index=0; index < 64; index++){
        if(index % 8 == 0){
            printf("\n");
        }
        printf("%5d", sq64_to_sq120[index]);
    }
    printf("\n");
}

int main(){
    int num  = 2;
    int nuts = 4;
    ASSERT(num == nuts);


    
    all_init();
    // print_board();
    

    
    return 0;
}