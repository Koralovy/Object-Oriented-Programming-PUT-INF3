public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account(){}
    public Account(int n, Customer c, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }
    public void login(String l, int passwd) 
        throws AccountLoginFailedException {
            if (!(this.login.equals(l) && this.password == passwd))
                throw new AccountLoginFailedException("AccountLoginFailedException", l, passwd);
    }
    public Customer getCustomer(){
        return this.owner;
    }
    public int getNumber() {
        return this.accountNumber;
    }
    public double getBalance() {
        return this.balance;
    }
    public double withdraw(double amount) {
        this.balance -= amount;
        return this.balance;
    }

}