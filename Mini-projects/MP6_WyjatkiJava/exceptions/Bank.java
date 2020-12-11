import java.util.*;
public class Bank implements SearchAccounts, SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<>();
    ArrayList<Account> accounts = new ArrayList<>();

    @Override
    public Customer findByName(String name)
        throws CustomerNotFoundException {
            for (Customer c : customers) 
                if (c.getName().equals(name))
                    return c;
            throw new CustomerNotFoundException();                
    }
    @Override
    public Account findByName(int nm)
        throws AccountNotFoundException {
            for (Account a : accounts) 
                if (a.getNumber() == nm)
                    return a;
            throw new AccountNotFoundException();
    }
    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException {
            System.out.println("asdasd");
            ArrayList<Account> ac = new ArrayList<>();
            for (Account a : accounts)
                if (a.getCustomer() == cust)
                    ac.add(a);
            if (ac.isEmpty())
                throw new AccountNotFoundException();
            System.out.println("asdasd");
            return ac;
    }

    public void createCustomer(String nm){
        customers.add(new Customer(nm));
    }
    public void createAccount(int n, String onm, int passwd, String ln){
        try {
            accounts.add(new Account(n, findByName(onm), passwd, ln));
        }
        catch (Exception e) {
            System.out.println("Brak klienta w bazie, nie mozna utworzyc konta");
        }
        
    }

    public static void main(String[] args) {
        Bank b = new Bank();
        b.createCustomer("Andrzej");
        b.createAccount(1, "Andrzej", 0000, "Andrzej");
        b.createAccount(2, "Andrzej", 0000, "Andrzej");

        try {
            System.out.println(b.findByName("Andrzej"));
        }
        catch (CustomerNotFoundException e) {
            System.out.println("Klienta brak");
        }

        try {
            System.out.println(b.findByName("Stefan"));
        }
        catch (CustomerNotFoundException e) {
            System.out.println("Klienta brak");
        }

        try {
            System.out.println(b.findAllCustomerAccounts(b.findByName("Andrzej")));
        }
        catch (CustomerNotFoundException e) {
            System.out.println("Klienta brak");
        }
        catch (AccountNotFoundException e) {
            System.out.println("Konta brak");
        }

        try {
            b.accounts.get(0).login("Andrzejzlylogin", 1);
        }
        catch (AccountLoginFailedException e){
            System.out.println(e.getMessage());
            e.printStackTrace();
        }        
        
        Exception f = new AccountLoginFailedException("asd", "asd", 1111);
        System.out.println(f.getMessage());
        f.printStackTrace();
        System.out.println("Finalizowanie");

        try {
            b.accounts.get(0).login("Andrzejzlylogin", 1);
        }
        catch (AccountLoginFailedException e){
            e.fillInStackTrace();
            System.out.println(e.getMessage());
            e.printStackTrace();
        }   

        //Z9: implementujac interfejsy zapewniamy wieksza czytelnosc kodu umozliwiajaca wygodna reimplementafcje danych funkcji.
        //Z11: slady stosu roznia sie wskazaniem na lokalizacje sprawdzanego wyjatku w kodzie i brakiem wywolania polecenia login
        //Z12: fillInStackTrace zmienia stos wywolan na wlasny, zawarty w mainie 
    }

}