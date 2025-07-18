#include "stdio.h"
#include "def.h"


const int bit_table[64] = {
   63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
   51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
   26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
   58, 20, 37, 17, 36, 8
};

// PART 9
/* Takes first bit starting at least sig. bit in bb and returns the index the bit was set at and then resets that bit to zero.*/
int pop_bit( U64 *bb){
    U64 b = *bb ^ (*bb - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *bb &= (*bb - 1);
    return bit_table[(fold * 0x783a9b23) >> 26]; // compute hash value to index into bit_table
}

/*Counts and returns the number of bits set in a 64 bit unsigned int*/
int count_bits(U64 b){
    int r;
    for(r=0; b; r++, b &= b -1); // b != 0 is cond. (truthy)
    return r;
}








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