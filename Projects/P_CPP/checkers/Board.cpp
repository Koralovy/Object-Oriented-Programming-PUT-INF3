#include "Board.h"

Board::Board() {
    for (int i = 1; i < Nsize; i += 2) {
        board[0][i] = new BlackPiece;
        board[1][i - 1] = new BlackPiece;
        board[Nsize - 1][i - 1] = new WhitePiece;
        board[Nsize - 2][i] = new WhitePiece;
    }
}

Board::~Board() {
}
void Board::drawBoard() {
    cout << "/ ";
    for (int i = 0; Nsize > i; i++) {
        cout << " " << alphabet[i] << "  ";
    }
    cout << "\\\n";

    for (int i = 0; Nsize > i; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; Nsize > j; j++) {
            if (board[i][j] == nullptr)
                ((j + i) % 2) ? cout << " +  " : cout << " -  ";
            else
                cout << board[i][j]->returnGraphics() << "  ";
        }
        cout << i + 1;

        if (i == 1)
            cout << showLastMove(1);
        else if (i == 3)
            cout << showGraveyard(0);
        else if (i == 4)
            cout << showGraveyard(1);
        else if (i == 6)
            cout << showLastMove(0);

        cout << "\n";
    }
    cout << "\\ ";
    for (int i = 0; Nsize > i; i++) {
        cout << " " << alphabet[i] << "  ";
    }
    cout << "/\n\n";
}

void Board::movePiece() {
    cout << returnPlayer();
    string move1, move2;
    cout << "Please provide the move: ";
    cin >> move1 >> move2;
    checkIfMoveIsValidAndPrepare(move1, move2);
}

void Board::checkIfMoveIsValidAndPrepare(string _m1, string _m2) {
    string l1 = _m1, l2 = _m2;
    int x1 = _m1[0] - 'A', x2 = _m2[0] - 'A';
    _m1.erase(0, 1);
    _m2.erase(0, 1);
    int y1 = stoi(_m1) - 1, y2 = stoi(_m2) - 1;
    if (!(y1 >= 0 && y1 <= Nsize && y2 >= 0 && y2 <= Nsize))  //move in board //(j + i) % 2
        throw OutOfBounds();

    if (board[y1][x1] == nullptr || board[y1][x1]->returnColor() != this->player)  //is it this player piece
        throw NotYourPiece();

    if (board[y2][x2] != nullptr && board[y2][x2]->returnColor() == this->player)  //your piece already on 2nd poz
        throw AlreadyOccupied();
    //logic for standard movement
    if ((board[y1][x1]->isQueen() || !board[y1][x1]->returnColor()) && y2 + 1 == y1 && abs(x1 - x2) == 1) {  //is supported for white or queen
        takePieceAndFinishMove(x1, y1, x2, y2);

    }                                                                                                            //destroy if anything is present
    else if ((board[y1][x1]->isQueen() || board[y1][x1]->returnColor()) && y1 + 1 == y2 && abs(x1 - x2) == 1) {  //is supported for black or queen
        takePieceAndFinishMove(x1, y1, x2, y2);                                                                  //destroy if anything is present
    } else
        throw BadMove();  //move prohibited

    last_move[player] = {l1, l2};
}

void Board::takePieceAndFinishMove(int x1, int y1, int x2, int y2) {
    if (board[y2][x2] != nullptr) {
        int x3 = (x2 - x1 > 0) ? x2 + 1 : x2 - 1;
        int y3 = (y2 - y1 > 0) ? y2 + 1 : y2 - 1;
        if (board[y3][x3] != nullptr)
            throw NoTake();
        else
            graveyard[board[y2][x2]->returnColor()].push_back(board[y2][x2]);
        board[y3][x3] = board[y1][x1];
        board[y2][x2] = nullptr;
        if (!board[y1][x1]->returnColor() && y3 == 0)
            board[y3][x3]->makeQueen();
        else if (board[y1][x1]->returnColor() && y3 == 7)
            board[y3][x3]->makeQueen();
    } else {
        board[y2][x2] = board[y1][x1];
        if (!board[y1][x1]->returnColor() && y2 == 0)
            board[y2][x2]->makeQueen();
        else if (board[y1][x1]->returnColor() && y2 == 7)
            board[y2][x2]->makeQueen();
    }

    board[y1][x1] = nullptr;
}

string Board::returnPlayer() {
    return (!this->player) ? "White turn!\n" : "Black turn!\n";
};
void Board::swapPlayer() {
    this->player = !this->player;
};

vector<vector<Piece *>> Board::returnGraveyard() {
    return this->graveyard;
}

int Board::returnNSize() {
    return this->Nsize;
}

string Board::showGraveyard(int p) {
    string out = "\t";
    for (int i = 0; graveyard[p].size() > i; i++)
        out += graveyard[p][i]->returnGraphics() + " ";
    return out;
}

string Board::showLastMove(int p) {
    return "\t" + last_move[p].first + " " + last_move[p].second;
}