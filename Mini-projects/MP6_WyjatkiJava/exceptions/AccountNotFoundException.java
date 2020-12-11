class AccountNotFoundException extends Exception{
    static final long serialVersionUID = 1L;
    private final int accountNumber;

    AccountNotFoundException(){accountNumber = -1;}
    AccountNotFoundException(String errorMsg, int an) {
        super(errorMsg);
        accountNumber = an;
    }

    public int getNumber() {
        return this.accountNumber;
    }
}
