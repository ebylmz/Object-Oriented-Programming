#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "commissionEmployee.h"
using EmployeeGTU::CommissionEmployee;

#include "basePlusCommissionEmployee.h"
using EmployeeGTU::BasePlusCommissionEmployee;

int main () {
    CommissionEmployee commissionE("Sue", "Jones", "555-55-5555", 100, .06);    
    BasePlusCommissionEmployee basePlusCommissionE("Bob", "Lewis", "333-33-3333", 5000, .04, 300 );
    
    // set floating-point output formatting
    cout << fixed << setprecision(2);
    
    cout << "Print base-class and derived-class objects:\n\n";
    commissionE.print(); // invokes base-class print
    cout << "\n\n";
    basePlusCommissionE.print(); // invokes derived-class print
    
    CommissionEmployee * ptr_commissionE = &commissionE;
    cout << "\n\n\nCalling print with base-class pointer to "
         << "\nbase-class object invokes base-class print function:\n\n";
    ptr_commissionE->print(); // invokes base-class
    
    BasePlusCommissionEmployee * ptr_basePlusCommissionE = &basePlusCommissionE;
    cout << "\n\n\nCalling print with derived-class pointer to "
         << "\nderived-class object invokes derived-class "
         << "print function:\n\n";
    ptr_basePlusCommissionE->print(); // invokes derived-class print    
    
    ptr_commissionE = &basePlusCommissionE;
    cout << "\n\n\nCalling print with base-class pointer to "
         << "derived-class object\ninvokes base-class print "
         << "function on that derived-class object:\n\n";
    ptr_commissionE->print(); // invokes base-class print !!!
    cout << endl;
    return 0;
} 