package Employee;

public class BasePlusCommissionEmployee extends CommissionEmployee {
    private double _baseSalary;

    BasePlusCommissionEmployee (String fname, String lname, String ssn, double sales, double rate, double baseSalary) {
        super(fname, lname, ssn, sales, rate);
        setBaseSalary(baseSalary);    
    }

    public void setBaseSalary (double baseSalary) {_baseSalary = (baseSalary < 0.0) ? 0.0 : baseSalary;}    

    public double baseSalary () {return _baseSalary;}

    public double earnings () {return super.earnings() + baseSalary();}

    public String toString () {
        return  super.toString() + String.format("base salary: %.2f", _baseSalary);
    } 
}
