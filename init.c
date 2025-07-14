#include "def.h"

int sq120_to_sq64[BRD_SQ_NUM]; 
int sq64_to_sq120[64];


void init_sq120_to_64(){
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;

    // used to set out-of-bound values for squares on 120-square board.
    for(index = 0; index < BRD_SQ_NUM; ++index){
        sq120_to_sq64[index] = 65;
    }
    
    for(index = 0; index < 64; ++index){
        sq64_to_sq120[index] = 120;
    }


    /* This for loop initializes the index conversion between the 64 and 120 square board
    representations. Using 8 files, 8 rank enumeration, it converts file and rank to the 120-square board index
    then uses that index to match it to the corresponding 64-square board index. */
    for(rank = RANK_1; rank <= RANK_8; ++rank){
        for(file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file,rank); // Macro defined in def.h
            sq64_to_sq120[sq64] = sq;
            sq120_to_sq64[sq] = sq64;
            sq64++;
        }
    }

}

/* function initializes all values of the board properly before program begins.*/
void all_init(){
    init_sq120_to_64();
}