class CustomerNotFoundException extends Exception{
    static final long serialVersionUID = 1L;
    private final String name;

    CustomerNotFoundException(){name="";}
    CustomerNotFoundException(String errorMsg, String n) {
        super(errorMsg);
        name = n;
    }

    public String getName() {
        return this.name;
    }
}
