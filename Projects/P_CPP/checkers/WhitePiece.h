#ifndef __WHITEPIECE_H__
#define __WHITEPIECE_H__
#include "Piece.h"
class WhitePiece : public Piece {
   private:
    string spawn = "wp";
    string squeen = "wq";

   public:
    bool returnColor() final { return 0; };
    string returnGraphics() final { return (this->isQueen()) ? this->squeen : this->spawn; };
};

#endif  // __WHITEPIECE_H__