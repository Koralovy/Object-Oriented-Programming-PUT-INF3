import java.util.*;
interface SearchAccounts {
    Account findByName(int number)
        throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException;
}