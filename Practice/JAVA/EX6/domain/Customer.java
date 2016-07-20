package domain;

public class Customer implements Comparable
{

	  // Data Attributes
	  private String   firstName;
	  private String   lastName;
	  // Association Attributes
	  private Account[] accounts = new Account[5];
	  private int       numberOfAccounts = 0;

	  public Customer(String f, String l) {
	    firstName = f;
	    lastName = l;
	  }

	  public String getFirstName() {
	    return firstName;
	  }
	  public String getLastName() {
	    return lastName;
	  }
	  public void addAccount(Account acct) {
	    int i = numberOfAccounts++;
	    accounts[i] = acct;
	  }
	  public Account getAccount(int account_index) {
	    return accounts[account_index];
	  }
	  public int getNumOfAccounts() {
	    return numberOfAccounts;
	  }

	  public int compareTo(Object arg0) {
			// TODO Auto-generated method stub
		if( getLastName().compareToIgnoreCase(((Customer)arg0).getLastName())>0)
		{
				return 1;
		}
		else if( getLastName().compareToIgnoreCase(((Customer)arg0).getLastName())==0)
		{
			if( getFirstName().compareToIgnoreCase(((Customer)arg0).getFirstName()) > 0)
				return 1;
			else if(getFirstName().compareToIgnoreCase(((Customer)arg0).getFirstName()) == 0)
				return 0;
			else return -1;
		}
		else
			return -1;
			
	  }
	  }
