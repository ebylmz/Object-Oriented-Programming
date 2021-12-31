package inheritance.Employee;

public class PayrollSystemTest {
    public static void main (String args[]) {
        SalariedEmployee salaried = new SalariedEmployee("Emirkan Burak", "Yilmaz", "111-11-1111", 800.00);
        
        HourlyEmployee hourly = new HourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40);
        
        CommissionEmployee commission = new CommissionEmployee("Mary", "Jane", "333-33-3333", 10000, .06);
        
        BasePlusCommissionEmployee basePlusCommission = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

        Employee employees[] = new Employee[4];
        employees[0] = salaried;
        employees[1] = hourly;
        employees[2] = commission;
        employees[3] = basePlusCommission;
 
        for (Employee current : employees) {
            // determine whether element is a BasePlusCommissionEmployee
            if (current instanceof BasePlusCommissionEmployee) {
                // downcast Employee reference to BasePlusCommissionEmployee reference
                BasePlusCommissionEmployee employee = (BasePlusCommissionEmployee) current;
                double oldBaseSalary = employee.baseSalary();
                employee.setBaseSalary( 1.10 * oldBaseSalary );
                System.out.printf("new base salary with 10%% increase is: $%,.2f\n", employee.baseSalary() );            
            }
            System.out.printf("earned $%,.2f\n\n", current.earnings() );        
        }

        // print the types of employee objects
        for (int i = 0; i < employees.length; ++i)
            System.out.printf("Employee %d is a %s\n", i, employees[i].getClass().getName());
    }
}
