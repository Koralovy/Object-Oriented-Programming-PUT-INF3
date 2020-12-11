public class Customer {
    private String name;
    
    public Customer(){}
    public Customer(String s) {
        this.name = s;
    }
    public String getName() {
        return this.name;
    }

    @Override //override nadpisuje domyslna metode klasy
    public boolean equals(Object c) {
        if (c instanceof Customer)
            return this.getName() == ((Customer) c).getName();
        return false;

    }
}
