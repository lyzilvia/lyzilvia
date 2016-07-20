package domain;

public class Account {

	  protected double   balance;

	  public Account(double init) {
	    balance = init;
	  }

	  public double getBalance() {
	    return balance;
	  }
	  public boolean deposit(double amount) {
	    balance = balance + amount;
	    return true;
	  }
	  public void withdraw(double amount) throws OverdraftException
	  {
	    if ( balance >= amount ) {
	    	balance = balance - amount;
	    } else {
	      throw new OverdraftException("Insufficient funds", amount - balance);
	    }
	   
	  }
	}

