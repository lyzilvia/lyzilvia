import java.io.*; 
import java.util.*; 

public class FileCon {  
	Object [][] data = new Object[7][100];  
	ObjectInputStream in = null;  
	ObjectOutputStream out = null;  
	String path = "D:\\file";  
	public FileCon(){   
	for(int i = 0;i<7;i++)    
		for(int j = 0;j<100;j++){     
			data[i][j] = new FilePro("",null,"",1,0);    
		} 
	} 
	public Object[][] readData(){   
		try {    
			in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(path)));    
			data = (Object[][]) in.readObject();   
		} catch(EOFException e){   
		} catch (Exception e) {   
		} 
		return data; 
	} 
	public void writeData(Object[][] data){   
		try {    
			out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(path)));    
			out.writeObject(data);    
			out.flush();   
		} catch (Exception e) {    
			e.printStackTrace(); 
		}     
	} 
}