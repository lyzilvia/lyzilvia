import java.util.*; 

public class FileSystem {  
	Object[][] data = new Object[7][100];  
	FileCon fc = new FileCon(); 
	List<String> user = new ArrayList<String>();  
	UserCon uc = new UserCon();   
	String[] cmd = new String[2]; 
	int currentuser = 0; 

	public FileSystem() {   
		data = fc.readData();   
		user = uc.readUser();  
	} 
  
	public static void main(String[] args) {   
		FileSystem fs = new FileSystem();   
		fs.help(); 
	} 

	public void help() {   
		System.out.println("Welcome to file system");   
		System.out.print("create ");   
		System.out.println("/create file");   
		System.out.print("dir    ");   
		System.out.println("/list directory of  file");   
		System.out.println("exit    /exit system"); 
		System.out.println("The following command must followed by file name");   
		System.out.println("eg：open ***");   
		System.out.print("open   ");   
		System.out.println("/open file");   
		System.out.print("close  ");   
		System.out.println("/close file");   
		System.out.print("read   ");   
		System.out.println("/read file");   
		System.out.print("write  ");   
		System.out.println("/write file");   
		System.out.print("delete ");   
		System.out.println("/delete file");    
		command(); 
	} 

	public void command() {   
		System.out.print("root:>");   
		String comd = null; 
		Scanner input = input = new Scanner(System.in);   
		comd = input.nextLine();   
		String[] cmd = new String[2];   
		cmd = comd.split(" ");   
		if (cmd[0].equals("login"))    
			login(); 
		else if (cmd[0].equals("create"))    
			create(); 
		else if (cmd[0].equals("dir"))    
			dir(); 
		else if (cmd[0].equals("delete"))    
			delete(cmd[1]); 
		else if (cmd[0].equals("open")) 
			open(cmd[1]); 
		else if (cmd[0].equals("close"))    
			close(cmd[1]); 
		else if (cmd[0].equals("read"))    
			read(cmd[1]); 
		else if (cmd[0].equals("write"))    
			write(cmd[1]); 
		else if (cmd[0].equals("exit")){    System.out.println("Exit the system！");    
			System.exit(0);} 
		else System.out.println("Wrong Command！！");   
		command(); 
	} 

	public void login() {   
		boolean f = false; 
		System.out.println("Enter user name:"); 
		Scanner input = input = new Scanner(System.in);   
		String username = input.next(); 
		for (int i = 0; i < user.size(); i++) {    
			if (user.get(i).equals(username)) {     
				System.out.println("Logged in!");     
				currentuser = i;     
				f = true;     
				break; 
			} 
  
		} 
		if (!f) {    
			System.out.println("User not exist. Register? input y for register, other for back to preceding step");    
			String cho = input.next();    
			if (cho.equals("y")) {     
				if (user.size() == 7)      
					System.out.println("Full user. Use a registered user name to login."); 
				else {      
					user.add(username);      
					uc.writeUser(user); 
					System.out.println("Register  sucessful. Please login again."); 
				}     
				login(); 
			} 
		} 
		command(); 
	} 

	public void dir() {   
		System.out.println("file name\t" + "user name\t" + "physical add.\t" + "code\t" + "length");   
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (!fp1.filename.equals(""))     
				System.out.println(fp1.filename + "\t" + fp1.username + "\t"       + currentuser + i + "\t" + fp1.protect + "\t" + fp1.content.length()); 
		} 
		command(); 
	} 

	public void create() {   
		Scanner input = input = new Scanner(System.in);   
		boolean f = true;   
		boolean fl = false;   
		String filename = null; 
		do{    
			fl = false; 
			System.out.print("Enter file name:");       
			filename = input.next();    
			for (int i = 0; i < 100; i++) {     
				FilePro fp1 = (FilePro) data[currentuser][i];     
				if (fp1.filename.equals(filename)) {      
					System.out.println("File already exists.");      
					fl = true;      
					break; 
				} 
   
			} 
		}while(fl); 
		System.out.print("Enter the accessibility:");   
		int protect = input.nextInt(); 
		FilePro fp = new FilePro(filename, user.get(currentuser), "", 1, protect); 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals("")) {     
				data[currentuser][i] = fp;  
				fc.writeData(data); 
				System.out.println("Create sucessful!");     
				f = false;     
				break; 
			} 
		} 
		if (f) {    
			System.out.println("Hard disk Full."); 
		} 
		command(); 
	} 

	public void delete(String file) {   
		boolean f = true; 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals(file)) {     
				fp1.filename = "";     
				fp1.content = null;     
				fp1.flag = 1;     
				fp1.username = null;     
				fc.writeData(data); 
				System.out.println("Delete sucessful!");     
				f = false;     
				break; 
			} 
		}   
		if (f) {    
			System.out.println("No such file."); 
		} 
		command(); 
	} 

	public void open(String file) {   
		boolean f = true; 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals(file)) {     
				if (fp1.flag == 0)      
					System.out.println("File already opened."); 
				else {      
					fp1.flag = 0; 
					System.out.println("File open sucessful!");
				} 
				f = false;     
				break; 
			} 
		} 
		if (f) {    
			System.out.println("No such file."); 
		} 
		command(); 
	} 

	public void close(String file) {   
		boolean f = true; 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals(file)) {     
				if (fp1.flag == 1)      
					System.out.println("File not open."); 
				else {      
					fp1.flag = 1; 
					System.out.println("File close sucessful!"); 
				} 
				f = false;     
				break; 
			} 
		}   
		if (f) {    
			System.out.println("No such file."); 
		} 
		command(); 
	} 

	public void read(String file) {   
		boolean f = true; 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals(file)) {     
				if (fp1.flag == 1)      
					System.out.println("File not open. Open the file first."); 
				else {      
					System.out.println(fp1.content); 
				} 
				f = false;     
				break; 
			} 
		} 
		if (f) {    
			System.out.println("No such file."); 
		} 
		command(); 
	} 
 
	public void write(String file) {   
		Scanner input = input = new Scanner(System.in);   
		boolean f = true; 
		for (int i = 0; i < 100; i++) {    
			FilePro fp1 = (FilePro) data[currentuser][i];    
			if (fp1.filename.equals(file)) {     
				if (fp1.flag == 1)      
					System.out.println("File not open. Open the file first."); 
				else {      
					if (fp1.protect != 0)       
						System.out.println("Sorry, you don't have the accessibility."); 
					else {       
						System.out.println("Enter the content that need to be written:");       
						String ss = input.next();       
						fp1.content = fp1.content + ss;       
						fc.writeData(data); 
						System.out.println("Written!"); 
					} 
				} 
				f = false;     
				break; 
			} 
		}   
		if (f) {    
			System.out.println("No such file."); 
		} 
		command(); 
	} 
}