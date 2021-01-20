package checkers;

public class WhitePiece implements Piece {
    private boolean queen = false;
    private String spawn = "wp";
    private String squeen = "wq";

    public void makeQueen() {
        this.queen = true;
    }

    public boolean isQueen() {
        return this.queen;
    }

    public final boolean returnColor() {
        return false;
    }

    public final String returnGraphics() {
        return this.isQueen() ? this.squeen : this.spawn;
    }
}
