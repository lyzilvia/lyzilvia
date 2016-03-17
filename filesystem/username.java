public class UserCon {  
	List<String> list = new ArrayList<String>();  
	ObjectInputStream in = null;  
	ObjectOutputStream out = null;  
	String path = "D:\\user";  
	public List<String> readUser(){   
		try {    
			in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(path)));    
			list = (List<String>) in.readObject(); 
		} catch(EOFException e){   
		} catch (Exception e) {   
		} 
		return list; 
	} 
	public void writeUser(List<String> list){   
		try {    
			out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(path)));    
			out.writeObject(list);    
			out.flush();   
		} catch (Exception e) {    
			e.printStackTrace(); 
		}     
	} 
} 