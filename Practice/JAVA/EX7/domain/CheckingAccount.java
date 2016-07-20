package domain;


public class CheckingAccount extends Account {
  private static final double NO_PROTECTION = -1.0;

  private double overdraftProtection;

  public CheckingAccount(double bal, double protect) {
    super(bal);
    overdraftProtection = protect;
  }
  public CheckingAccount(double bal) {
    this(bal, NO_PROTECTION);
  }

  public void withdraw(double amount) throws OverdraftException
  {
    if ( balance < amount ) 
    {

      // Not enough balance to cover the amount requested to withdraw
      // Check if there is enough in the overdraft protection (if any)
      double overdraftNeeded = amount - balance;
      if ( (overdraftProtection == NO_PROTECTION) ||(overdraftProtection < overdraftNeeded))   
      {  if(overdraftProtection == NO_PROTECTION)
    		  throw new OverdraftException("No overdraft protection", amount - balance);
         if(overdraftProtection < overdraftNeeded)  
        	 throw new OverdraftException("Insufficient funds for overdraft protection", amount - balance);
      } 
      else {

	// Yes, there is overdraft protection and enough to cover the amount
	balance = 0.0;
	overdraftProtection = overdraftProtection - overdraftNeeded;
	
	
      }

    } else 
    {

      // Yes, there is enough balance to cover the amount
      // Proceed as usual
      balance = balance - amount;
    }
  }
}
