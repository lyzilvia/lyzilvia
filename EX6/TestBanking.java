/*
 * This class creates the program to test the banking classes.
 * It creates a set of customers, with a few accounts each,
 * and generates a report of current account balances.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import domain.*;
import reports.CustomerReport;

public class TestBanking {

	  public static void main(String[] args) throws FileNotFoundException 
	  {
	    Bank     bank = Bank.getBank();
	    CustomerReport report = new CustomerReport();
	    
	   File file = new File("inputdata.txt");
	   Scanner input = new Scanner (file);
	   
	   
	   String tempFirstName = null;
	   boolean isPass = false;
	   
	   String firstName = null;
	   String lastName = null;
	   String savingBalance = null;
	   String checkBalance = null;
	   String protect = null;
	   String interest = null;
	   
	   int index = 0;
	   while(input.hasNext())
	   {
		   if(!isPass)
		   {
		    firstName = input.next();
		   }
		   else
		   {
			   firstName = tempFirstName;
			   isPass = false;
		   }
		   
		   lastName = input.next();
		   //判断第一个输入
		   String temp1 = input.next();
	 	   if(temp1.equals("s"))
		   {
			   savingBalance = input.next();
			   interest = input.next();
		   }
		   else if(temp1.equals("c"))
		   {
			   checkBalance = input.next();
			   if(!input.hasNext())
			   {
				   savingBalance = null;
				   interest = null;
				   protect = null;
				   setBankCustomerAccount(index++, bank, firstName, lastName, 
							  savingBalance, interest, checkBalance, protect);
				   continue;
			   }
			   protect = input.next();
			   if(!isDigit(protect))
			   {	   
				   tempFirstName = protect;
				   isPass = true;
				   savingBalance = null;
				   interest = null;
				   protect = null;
				   setBankCustomerAccount(index++, bank, firstName, lastName, 
							  savingBalance, interest, checkBalance, protect);
			
				   continue;
			   }
			   savingBalance = null;
			   interest = null;
			   setBankCustomerAccount(index++, bank, firstName, lastName, 
						  savingBalance, interest, checkBalance, protect);
			   continue;
		   }
		   if(!input.hasNext())
		   {
			   checkBalance = null;
			   protect = null;
			   setBankCustomerAccount(index++, bank, firstName, lastName, 
						  savingBalance, interest, checkBalance, protect);
			   continue;
		   }
		   String temp2 = input.next();
		   if(temp2.equals("c"))
		   {
			   checkBalance = input.next();
			   if(!input.hasNext())
			   {
				   protect = null;
				   setBankCustomerAccount(index++, bank, firstName, lastName, 
							  savingBalance, interest, checkBalance, protect);
				   continue;
			   }
			   protect = input.next();
			   if(!isDigit(protect))
			   {
				   tempFirstName = protect;
				   isPass = true;
				   protect = null;
				   setBankCustomerAccount(index++, bank, firstName, lastName, 
							  savingBalance, interest, checkBalance, protect);
				   continue;
			   }
		   }
		   else 
		   {
			   tempFirstName = temp2;
			   isPass = true;
		   }
		   setBankCustomerAccount(index++, bank, firstName, lastName, 
					  savingBalance, interest, checkBalance, protect);
	   }
	   input.close();

	    // Generate a report
	    
	   report.generateReport();

	   
	  }
	  
	  public static boolean isDigit(String str)
	  {
		  for (int i = 0; i < str.length(); i++)
		  {
			  if (!Character.isDigit(str.charAt(i)) && str.charAt(i)!='.')
			  {
			    return false;
			  }
		  }
			  return true;
	  }
	  public static void setBankCustomerAccount(int index,Bank bank, String firstName, String lastName, 
			  String saveBalance, String interest, String checkBalance,String protect)
	  {
		 
			  bank.addCustomer(firstName, lastName);	  
		      Customer customer = bank.getCustomer(index);
			  if(saveBalance != null)
			  {
				  customer.addAccount(new SavingsAccount(Double.parseDouble(saveBalance), Double.parseDouble(interest)));
			  }
			  if(checkBalance != null)
			  {
				  if(protect  != null)
				      customer.addAccount(new CheckingAccount(Double.parseDouble(checkBalance),Double.parseDouble(protect)));
				  else
					  customer.addAccount(new CheckingAccount(Double.parseDouble(checkBalance)));
			  }
	  }
	}

