package checkers;

class BoardException extends Exception {
    BoardException() {
        super("Board exception!");
    }

    BoardException(String msg) {
        super(msg);
    }

}

class OutOfBounds extends BoardException {
    OutOfBounds() {
        super("Entered locations are outside the board boundaries!");
    }
}

class NotYourPiece extends BoardException {
    NotYourPiece() {
        super("This piece does not belong to you or first position is empty!");
    }
}

class AlreadyOccupied extends BoardException {
    AlreadyOccupied() {
        super("You cannot enter the field you have already occupied!");
    }
}

class BadMove extends BoardException {
    BadMove() {
        super("Move not accepted!\n");
    }
}

class NoTake extends BoardException {
    NoTake() {
        super("Space behind piece is occupied. Can't take!");
    }
}

class WrongInput extends BoardException {
    WrongInput() {
        super("Wrong input!");
    }
}
