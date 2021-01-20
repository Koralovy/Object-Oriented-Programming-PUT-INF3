package checkers;

public class BlackPiece implements Piece {
    private boolean queen = false;
    private String spawn = "bp";
    private String squeen = "bq";

    public void makeQueen() {
        this.queen = true;
    }

    public boolean isQueen() {
        return this.queen;
    }

    public final boolean returnColor() {
        return true;
    }

    public final String returnGraphics() {
        return this.isQueen() ? this.squeen : this.spawn;
    }

}
