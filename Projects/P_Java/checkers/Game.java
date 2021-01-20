package checkers;

public class Game {
    private Board b = new Board();

    public static void clearScreen() {
        System.out.print("\033[H\033[2J\n");
        System.out.flush();
    }

    public void play() {
        while (b.returnAlive(0) != 0 && b.returnAlive(1) != 0) {
            b.drawBoard();
            try {
                b.movePiece();
                b.swapPlayer();
                clearScreen();
            } catch (OutOfBounds | NotYourPiece | AlreadyOccupied | BadMove | NoTake | NumberFormatException | WrongInput e) {
                clearScreen();
                System.out.print("Wrong move!\n");
                System.out.println(e.getMessage());
            }
        }
        if (b.returnAlive(0) != 0)
            System.out.print("White won!\n");
        else
            System.out.print("Black won!\n");
    }

    public void menu() {
        System.out.print("Here are some rules of the game:\n");
        System.out.print(
                "- Movements must be provided by indicating the start position and the direction of the end position. This means that if a pawn moving from A4 to B3 encounters an obstacle on B3, it will automatically move to C2, but the input only valid input will be A4 B3.\n");
        System.out.print("- The queen can move and take in both directions, pawns according to her polarity.\n");
        System.out.print("- Each move is one take or one square move.\n");
        System.out.print("- If both players are ready, please type \"start\": ");

        String start = b.scan.nextLine();
        while (!start.equals("start")) {
            System.out.print("If both players are ready, please type \"start\": ");
            start = b.scan.nextLine();
        }

        clearScreen();
        play();
        b.scan.close();
    }

    public static void main(String[] args) {
        Game g = new Game();
        g.menu();
    }
}