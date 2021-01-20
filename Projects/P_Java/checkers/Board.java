package checkers;

import java.util.*;

public class Board {
    private int Nsize = 8;
    private char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
            'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    private Piece[][] board = new Piece[Nsize][Nsize];

    private boolean player = false;
    private int[] alive = { Nsize, Nsize };
    private Piece[][] graveyard = new Piece[2][Nsize];
    private String[][] last_move = { { "-", "-" }, { "-", "-" } };

    public static Scanner scan = new Scanner(System.in);
    Board() {
        for (int i = 1; i < this.Nsize; i += 2) {
            board[0][i] = new BlackPiece();
            board[1][i - 1] = new BlackPiece();
            board[this.Nsize - 1][i - 1] = new WhitePiece();
            board[this.Nsize - 2][i] = new WhitePiece();

        }
    }

    public void drawBoard() {
        System.out.print("/ ");
        for (int i = 0; Nsize > i; i++) {
            System.out.print(" " + alphabet[i] + "  ");
        }
        System.out.print("\\\n");

        for (int i = 0; Nsize > i; i++) {
            System.out.print(i + 1 + "  ");
            for (int j = 0; Nsize > j; j++) {
                if (board[i][j] == null)
                    if ((j + i) % 2 == 1)
                        System.out.print(" +  ");
                    else
                        System.out.print(" -  ");
                else
                    System.out.print(board[i][j].returnGraphics() + "  ");
            }
            System.out.print(i + 1);

            if (i == 1)
                System.out.print(this.showLastMove(1));
            else if (i == 3)
                System.out.print(this.showGraveyard(0));
            else if (i == 4)
                System.out.print(showGraveyard(1));
            else if (i == 6)
                System.out.print(showLastMove(0));

            System.out.print("\n");
        }
        System.out.print("\\ ");

        for (int i = 0; Nsize > i; i++) {
            System.out.print(" " + alphabet[i] + "  ");
        }
        System.out.print("/\n\n");
    }

    public void movePiece() throws OutOfBounds, NotYourPiece, AlreadyOccupied, BadMove, NoTake, NumberFormatException, WrongInput {
        System.out.print(this.returnPlayer());
        System.out.print("Please provide the move: ");
        String input = scan.nextLine();
        String[] inparr = input.split("\\s");
        if (inparr.length < 2) throw new BadMove(); 
        checkIfMoveIsValidAndPrepare(inparr[0], inparr[1]);
    }

    public void checkIfMoveIsValidAndPrepare(String _m1, String _m2)
            throws OutOfBounds, NotYourPiece, AlreadyOccupied, BadMove, NoTake, NumberFormatException, WrongInput {
        int x1 = _m1.charAt(0) - 'A';
        int x2 = _m2.charAt(0) - 'A';
        int y1 = Integer.parseInt(_m1.substring(1)) - 1;
        int y2 = Integer.parseInt(_m2.substring(1)) - 1;

        if (!(y1 >= 0 && y1 <= Nsize && y2 >= 0 && y2 <= Nsize)) // move in board //(j + i) % 2
            throw new OutOfBounds();

        if (board[y1][x1] == null || board[y1][x1].returnColor() != this.player) // is it this player piece
            throw new NotYourPiece();

        if (board[y2][x2] != null && board[y2][x2].returnColor() == this.player) // your piece already on 2nd poz
            throw new AlreadyOccupied();
        // logic for standard movement
        if ((board[y1][x1].isQueen() || !board[y1][x1].returnColor()) && y2 + 1 == y1 && Math.abs(x1 - x2) == 1) { // is supported for white or queen
            takePieceAndFinishMove(x1, y1, x2, y2);

        } // destroy if anything is present
        else if ((board[y1][x1].isQueen() || board[y1][x1].returnColor()) && y1 + 1 == y2 && Math.abs(x1 - x2) == 1) { // is supported for black or queen
            takePieceAndFinishMove(x1, y1, x2, y2); // destroy if anything is present
        } else
            throw new BadMove(); // move prohibited

        last_move[this.player ? 1 : 0][0] = _m1;
        last_move[this.player ? 1 : 0][1] = _m2;
    }

    public void takePieceAndFinishMove(int x1, int y1, int x2, int y2) throws NoTake {
        if (board[y2][x2] != null) {
            int x3 = (x2 - x1 > 0) ? x2 + 1 : x2 - 1;
            int y3 = (y2 - y1 > 0) ? y2 + 1 : y2 - 1;
            if (board[y3][x3] != null)
                throw new NoTake();
            else {
                graveyard[board[y2][x2].returnColor() ? 1 : 0][this.Nsize
                        - returnAlive(board[y2][x2].returnColor() ? 1 : 0)] = board[y2][x2];
                take();
            }

            board[y3][x3] = board[y1][x1];
            board[y2][x2] = null;
            if ((!board[y1][x1].returnColor() && y3 == 0) || (board[y1][x1].returnColor() && y3 == 7))
                board[y3][x3].makeQueen();

        } else {
            board[y2][x2] = board[y1][x1];
            if ((!board[y1][x1].returnColor() && y2 == 0) || (board[y1][x1].returnColor() && y2 == 7))
                board[y2][x2].makeQueen();
        }

        board[y1][x1] = null;
    }

    public String returnPlayer() {
        return (!this.player) ? "White turn!\n" : "Black turn!\n";
    }

    public void swapPlayer() {
        this.player = !this.player;
    }

    public Piece[][] returnGraveyard() {
        return graveyard;
    }

    public int returnNSize() {
        return this.Nsize;
    }

    public String showGraveyard(int p) {
        StringBuilder sb = new StringBuilder();
        sb.append("\t");
        for (int i = 0; graveyard[p].length > i; i++) {
            if (graveyard[p][i] == null)
                break;
            sb.append(graveyard[p][i].returnGraphics());
            sb.append(" ");
        }

        return sb.toString();
    }

    public String showLastMove(int p) {
        return "\t" + last_move[p][0] + " " + last_move[p][1];
    }

    public void take() {
        this.alive[this.player ? 0 : 1]--;
    }

    public int returnAlive(int p) {
        return this.alive[p];
    }
}
