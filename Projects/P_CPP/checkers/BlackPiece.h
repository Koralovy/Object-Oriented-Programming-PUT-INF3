#ifndef __BLACKPIECE_H__
#define __BLACKPIECE_H__
#include "Piece.h"
class BlackPiece : public Piece {
   private:
    string spawn = "bp";
    string squeen = "bq";

   public:
    bool returnColor() final { return 1; };
    string returnGraphics() final { return (this->isQueen()) ? this->squeen : this->spawn; };
};

#endif  // __BLACKPIECE_H__