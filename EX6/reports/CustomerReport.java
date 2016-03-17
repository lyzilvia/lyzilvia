package reports;

import domain.*;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.NumberFormat;

public class CustomerReport {

  public void generateReport() throws FileNotFoundException {
    NumberFormat currency_format = NumberFormat.getCurrencyInstance();
    Bank         bank = Bank.getBank();
    Customer     customer;

	PrintWriter output = new PrintWriter("output.txt");
	   
    
    System.out.println("\t\t\tCUSTOMERS REPORT");
    output.println("\t\t\tCUSTOMERS REPORT");
    System.out.println("\t\t\t================");
    output.println("\t\t\t================");

    bank.sortCustomers();
    
    
    for ( int cust_idx = 0; cust_idx < bank.getNumOfCustomers(); cust_idx++ ) {
      customer = bank.getCustomer(cust_idx);

      System.out.println();
      output.println();
      System.out.println("Customer: "
			 + customer.getLastName() + ", "
			 + customer.getFirstName());
      output.println("Customer: "
 			 + customer.getLastName() + ", "
 			 + customer.getFirstName());

      for ( int acct_idx = 0; acct_idx < customer.getNumOfAccounts(); acct_idx++ ) {
	Account account = customer.getAccount(acct_idx);
	String  account_type = "";

	// Determine the account type
	if ( account instanceof SavingsAccount ) {
	  account_type = "Savings Account";
	} else if ( account instanceof CheckingAccount ) {
	  account_type = "Checking Account";
	} else {
	  account_type = "Unknown Account Type";
	}

	// Print the current balance of the account
	System.out.println("    " + account_type + ": current balance is "
			 + currency_format.format(account.getBalance()));
	output.println("    " + account_type + ": current balance is "
			 + currency_format.format(account.getBalance()));
      }
    }
    
    output.close();
  }
  
  

}
