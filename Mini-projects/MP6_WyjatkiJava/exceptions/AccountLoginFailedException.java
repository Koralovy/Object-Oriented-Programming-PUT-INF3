class AccountLoginFailedException extends Exception{
    static final long serialVersionUID = 1L;
    private final int password;
    private final String login;

    AccountLoginFailedException(){password = -1; login = "";}
    AccountLoginFailedException(String errorMsg, String s, int passwd) {
        super(errorMsg);
        login = s;
        password = passwd;
    }

    int getPassword(){
        return this.password;
    }

    String getLogin(){
        return this.login;
    }
}
