package domain;
import java.text.NumberFormat;
/**
 * The Bank class implements the Singleton design pattern, because
 * there should be only one bank object.
 */
public class Bank
{
  /**
   * The class variable that holds the single Bank instance.
   */
  private static final Bank bankInstance = new Bank();
  public static Bank getBank() {
    return bankInstance;
  }

  private static final int MAX_CUSTOMERS = 10;
  private static final double SAVINGS_RATE = 3.5;

  private Customer[] customers;
  private int        numberOfCustomers;

  private Bank() {
    customers = new Customer[MAX_CUSTOMERS];
    numberOfCustomers = 0;
  }

  public void addCustomer(String f, String l) {
    int i = numberOfCustomers++;
    customers[i] = new Customer(f, l);
  }
  public Customer getCustomer(int customer_index) {
    return customers[customer_index];
  }
  public int getNumOfCustomers() {
    return numberOfCustomers;
  }
  
  public void sortCustomers()
  { 
	  for( int j= 0; j< numberOfCustomers ; j++)
	  {
		for( int i = numberOfCustomers-1; i>j; i--)
		{
		if(getCustomer(j).compareTo(getCustomer(i)) == 1) 
		{
		Customer temp;
		temp = getCustomer(j);
		customers[j] = getCustomer(i);
		customers[i] = temp; 
		
		} 
		}
	  }
  }
  public void searchCustomers(String first,String last)
  {
	  for( int i=0; i< numberOfCustomers; i++)
	  {
		  if( getCustomer(i).getFirstName().equals(first) && getCustomer(i).getLastName().equals(last))
		  { 
			  System.out.println();
	      System.out.println("Customer: "
				 + getCustomer(i).getLastName() + ", "
				 + getCustomer(i).getFirstName());
	      
	      NumberFormat currency_format = NumberFormat.getCurrencyInstance();
	    
	      for ( int acct_idx = 0; acct_idx < getCustomer(i).getNumOfAccounts(); acct_idx++ ) {
	  	Account account = getCustomer(i).getAccount(acct_idx);
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
	      }
		  }
		  return;
	  } 
	  
  }


  
}
