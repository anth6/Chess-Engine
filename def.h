#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"
#include "stdio.h"

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1); } 
#endif 





#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120 // board sqaure number
#define MAX_GAME_MOVES 2048
typedef unsigned long long U64; // U64 alias for new type.

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK }; // represents the pieces on board.
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE }; // columns
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE }; // rows
enum { WHITE, BLACK, BOTH };
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};
enum { FALSE, TRUE };

//               0 0 0 0
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8}; // to account for castling

typedef struct{
    int move;
    int castle_perm;
    int en_pas;
    int fifty_move;
    U64 position_key;
} UNDO_S;

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; // each 64 bit number represents the 8x8 board. A bit will be set if a pawn is on the particular square.
    int king_square[2];
    int side;
    int en_pas;
    int fifty_move;
    int play;
    int hist_play;
    int castle_perm;
    U64 position_key;
    int piece_number[13]; 
    int big_pieces[3]; // big pieces
    int maj_pieces[3]; // major pieces
    UNDO_S history[MAX_GAME_MOVES]; // an array of moves. Each element is an instance of a move about to be made and info associated with that particular move.

    //piece list -- to kep track of all pieces on board aside from pawns
    int piece_list[13][10]; // at most there can be 10 of any of the 13 piece types.
    
} BOARD_S;

/* MACROS */
#define FR2SQ(f,r) ( (21 +(f) ) + ( (r) * 10) ) // converts f,r to 120-based index
#define SQ64(sq120) sq120_to_sq64[sq120] // just so i don't have to type sq120_to64 each time. Shorter name.
#define POP(bb) pop_bit(bb)
#define COUNT(b) count_bits(b)


/* GLOBALS*/
extern int sq120_to_sq64[BRD_SQ_NUM];
extern int sq64_to_sq120[64];

/* FUNCTIONS */

/*init.c*/
void all_init();


/* bitboards.c*/
void print_bit_board(U64 bb);
int pop_bit( U64 *bb);
int count_bits(U64 b);

#endif
