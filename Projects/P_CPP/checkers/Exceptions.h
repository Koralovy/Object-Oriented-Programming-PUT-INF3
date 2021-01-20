#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__
#include <exception>

class BoardException : public exception {
   public:
    BoardException(){};
    virtual const char* what() const noexcept override {
        return "Board exception!\n";
    }
};

class OutOfBounds : public BoardException {
   public:
    OutOfBounds(){};
    virtual const char* what() const noexcept override {
        return "Entered locations are outside the board boundaries!\n";
    }
};

class NotYourPiece : public BoardException {
   public:
    NotYourPiece(){};
    virtual const char* what() const noexcept override {
        return "This piece does not belong to you or first position is empty!\n";
    }
};

class AlreadyOccupied : public BoardException {
   public:
    AlreadyOccupied(){};
    virtual const char* what() const noexcept override {
        return "You cannot enter the field you have already occupied!\n";
    }
};

class BadMove : public BoardException {
   public:
    BadMove(){};
    virtual const char* what() const noexcept override {
        return "Move not accepted!\n";
    }
};

class NoTake : public BoardException {
   public:
    NoTake(){};
    virtual const char* what() const noexcept override {
        return "Space behind piece is occupied. Can't take!\n";
    }
};

#endif  // __EXCEPTIONS_H__