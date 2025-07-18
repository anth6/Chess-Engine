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
    playbitboard |= (1ULL << SQ64(D3));
    playbitboard |= (1ULL << SQ64(D4));
    print_bit_board(playbitboard);
    int count = COUNT(playbitboard);
    printf("\n");
    printf("Count: %d\n", count);
    int index = POP(&playbitboard);
    printf("Index: %d\n", index);
    print_bit_board(playbitboard);
    count = COUNT(playbitboard);
    printf("\n");
    printf("Count: %d\n", count);
    
    return 0;
}