#ifndef __GAME_H__
#define __GAME_H__
#include "Board.h"

class Game {
   private:
    Board b;

   public:
    Game(){};
    ~Game(){};
    void play();
    void menu();
    void clearScreen();
};

#endif  // __GAME_H__
