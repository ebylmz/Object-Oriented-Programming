package Employee;   //? I DONT DO THIS BY INTENTION

public class CommissionEmployee {
    protected String _fname;
    protected String _lname;
    protected String _ssn;
    protected double _grossSales;
    protected double _commissionRate;

    CommissionEmployee (String fname, String lname, String ssn, double sales, double rate) {
        _fname = fname; 
        _lname = lname;
        _ssn = ssn;
        setGrossSales(sales); 
        setCommissionRate(rate); 
    }

    public void setFirstName (String fname) {_fname = fname;}

    public void setLastName (String lname) {_lname = lname;}

    public void setSocialSecurityNumber (String ssn) {_ssn = ssn;}

    public void setGrossSales (double sales) {_grossSales = (sales < 0.0) ? 0.0 : sales;}

    public void setCommissionRate (double rate) {_commissionRate = (0.0 < rate && rate < 1.0) ? rate : 0.0;}
    
    public String firstName () {return _fname;}

    public String lastName () {return _lname;}

    public String socialSecurityNumber () {return _ssn;}

    public double grossSales () {return _grossSales;}

    public double commissionRate () {return _commissionRate;}

    public double earnings () {return commissionRate() * grossSales();}

    public String toString () {
        return String.format( "%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f", 
                "commission employee", _fname, _lname,
                "social security number", _ssn, 
                "gross sales", _grossSales, 
                "commission rate", _commissionRate );    
    }
}
