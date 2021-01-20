#ifndef __BOARD_H__
#define __BOARD_H__
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "BlackPiece.h"
#include "Exceptions.h"
#include "Piece.h"
#include "WhitePiece.h"
using namespace std;

class Board {
   private:
    const int Nsize = 8;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<vector<Piece *>> board = vector<vector<Piece *>>(Nsize, vector<Piece *>(Nsize, nullptr));
    bool player = 0;  //0 - white, 1 - black
    vector<vector<Piece *>> graveyard = vector<vector<Piece *>>(2, vector<Piece *>(0, nullptr));
    vector<pair<string, string>> last_move = vector<pair<string, string>>(2, {"", ""});

   public:
    Board();
    ~Board();
    void drawBoard();
    void movePiece();
    void checkIfMoveIsValidAndPrepare(string, string);
    void takePieceAndFinishMove(int, int, int, int);
    string returnPlayer();
    void swapPlayer();
    vector<vector<Piece *>> returnGraveyard();
    int returnNSize();
    string showGraveyard(int);
    string showLastMove(int);
};

#endif  // __BOARD_H__