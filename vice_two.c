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

    


    
    all_init();
    print_board();
    U64 playbitboard = 0ULL;
    playbitboard |= (1ULL << SQ64(D2));
    printf("D2 Added! \n \n");
    print_bit_board(playbitboard);
    playbitboard |= (1ULL << SQ64(G2));
    printf("G2 Added! \n \n");
    print_bit_board(playbitboard);
    
    return 0;
}