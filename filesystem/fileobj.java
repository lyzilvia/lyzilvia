import java.io.Serializable;

public class FilePro implements Serializable{  
	String filename;  
	String content;  
	String username;  
	int flag;  
	int protect; 
	public FilePro(String filename,String username,String content,int flag,int protect){ 
	this.filename = filename;   
	this.username = username;   
	this.content = content;   
	this.flag = flag;   
	this.protect = protect; 
	} 
} 