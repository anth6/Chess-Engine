#include "stdio.h"
#include "def.h"


void print_bit_board(U64 bb){
    U64 shift_me = 1ULL;
    int rank = 0;
    int file = 0;
    int sq = 0;
    int sq64 = 0;

    printf("\n");
    for(rank = RANK_8; rank >= RANK_1; rank--){
        for(file= FILE_A; file <= FILE_H; file++){
            sq = FR2SQ(file, rank); // 120-based index
            sq64 = SQ64(sq); // 64-based index
            
            if((shift_me << sq64) & bb){ // shift 64 bit number by sq64 (value between 0-63) and AND it with bb. If pawn is in sq64 location then it will return a non-zero value.
                printf("X");
            } else // no pawn in that position
                printf("-");  
        }
        printf("\n");
    }
    printf("\n");
}