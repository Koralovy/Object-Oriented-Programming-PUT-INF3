#include "Game.h"

void Game::play() {
    while (b.returnGraveyard()[0].size() != b.returnNSize() || b.returnGraveyard()[1].size() != b.returnNSize()) {
        b.drawBoard();
        try {
            b.movePiece();
            b.swapPlayer();
            clearScreen();
        } catch (const exception &e) {
            clearScreen();
            cout << "Wrong move!\n";
            cout << e.what() << "\n";
        }
    }
    (b.returnGraveyard()[0].size() != b.returnNSize()) ? cout << "White won!\n" : cout << "Black won!\n";
}

void Game::menu() {
    string start;
    cout << "Here are some rules of the game:\n";
    cout << "- Movements must be provided by indicating the start position and the direction of the end position. This means that if a pawn moving from A4 to B3 encounters an obstacle on B3, it will automatically move to C2, but the input only valid input will be A4 B3.\n";
    cout << "- The queen can move and take in both directions, pawns according to her polarity.\n";
    cout << "- Each move is one take or one square move.\n";
    cout << "- If both players are ready, please type \"start\": ";
    cin >> start;
    while (start != "start") {
        cout << "If both players are ready, please type \"start\": ";
        cin >> start;
    }
    clearScreen();
    play();
}

void Game::clearScreen() {
    cout << "\033[2J\033[1;1H\n" << flush;
}