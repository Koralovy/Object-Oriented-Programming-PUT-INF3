#ifndef __PIECE_H__
#define __PIECE_H__
#include <cstring>
using namespace std;
class Piece {
   private:
    bool queen = 0;

   public:
    Piece(){};
    virtual ~Piece(){};
    virtual bool returnColor() = 0;
    virtual string returnGraphics() = 0;
    void makeQueen() { this->queen = 1; };
    bool isQueen() { return this->queen; };
};

#endif  // __PIECE_H__