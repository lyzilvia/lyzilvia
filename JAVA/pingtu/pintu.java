import java.awt.*;
import java.applet.*;
import java.awt.event.* ;
import javax.swing.*;
import java.util.Timer;
import java.util.TimerTask;

public class pintu extends Applet	implements MouseListener,MouseMotionListener  
{
	private Image picture;
	private Graphics buffer;
	
	private Image pic[];
	private Image off_pic[];
	private Graphics off_buf[];
	private Image off_screen;
	private Graphics off_buffer;	
	private Image off_drag;
	private Graphics off_drag_buf;
	
	private int map[][];
	private int ran[];
	private int width=0;
	private int height=0;
	private int lastx;
	private int lasty;
	private int last_downx;
	private int last_downy;
	private int stepx;
	private int stepy;
	private boolean choose;
	private boolean click[][];
	private boolean m_down;
	private boolean m_drag;
	private boolean not_redraw;
	private boolean gameStarted;
	private Timer timeCount;
	private int index;
	private int gameTime=0;
	private int stepCounts=0;
	Font font1,font2;
	
	class TimerTaskItem extends TimerTask
	{
		public void  run()
		{
			gameTime++;
			repaint();
			if(!gameStarted)
			{
				
				timeCount.cancel();
			}
		}
	}
	
	public void init()
	{
		resize(640,480);
		pic = new Image [3];
		off_pic =  new Image[16];		
		off_buf = new Graphics [16];
		map = new int [4][4];
		ran = new int [15];
		
		for(int a=0;a<16;a++)
			map[a/4][a%4] = a;		
		for(int a=0;a<15;a++)
			ran[a]=a;
		click=new boolean [4][4];
		
		MediaTracker tracker= new MediaTracker (this);

		
		pic[0]=getImage(getCodeBase(),"PICTURE0.JPG");
		pic[1]=getImage(getCodeBase(),"PICTURE1.JPG");
		pic[2]=getImage(getCodeBase(),"PICTURE2.GIF");
		
		tracker.addImage (pic[0],0);
		tracker.addImage (pic[1],0);
		tracker.addImage (pic[2],0);		
		try{
			tracker.waitForID (0);
		}catch(InterruptedException e){}
	
		font1= new Font ("TimesRoman", Font.BOLD, 48);
		font2= new Font ("TimesRoman", Font.BOLD, 32);
		width=640;
		height=480;
		
		initForm();
		
		addMouseListener(this);
		addMouseMotionListener(this);	

	}

	void initForm()
	{
		this.setBackground (Color.orange);
		if(off_drag==null){
			off_drag = createImage(width/4,height/4);
			off_drag_buf = off_drag.getGraphics ();
			//off_drag_buf.drawString("4X4Æ´Í¼ÓÎÏ·", 200, 50);
		}
	}
	
	public void paint(Graphics g){
		if(off_screen==null)
		{
			resize(width,height);
			off_screen = createImage(width,height);
			off_buffer=off_screen.getGraphics ();	
			//off_buffer.drawString("4X4Æ´Í¼ÓÎÏ·", 200, 50);
		}
		if(gameStarted){
			
			resize(width+200,height);
			off_screen = createImage(width+300,height);
			off_buffer=off_screen.getGraphics ();	
			off_buffer.setColor (Color.black );	

			off_buffer.drawImage(pic[index],width+10,height-180,180,150,this);
			off_buffer.setFont(font2);
			off_buffer.drawString("Step£º"+stepCounts, width+20, 60);
			off_buffer.setFont(font1);;
			off_buffer.drawString("ÓÎÏ·Ê±¼ä", width, 120);
			off_buffer.drawString(gameTime+"", width+80, 180);
			off_buffer.setFont(font2);
			off_buffer.drawRect(width+30, 210, 140,40 );
			off_buffer.drawString("ÍË³öÓÎÏ·", width+30, 240);
		
			for(int a=0;a<4;a++)
				for(int b=0;b<4;b++)
				{
					if(map[a][b]!=15)
						off_buffer.drawImage (off_pic[map[a][b]],b*width/4,a*height/4,this);
					if(map[a][b]==15)
						off_buffer.fillRect (b*width/4,a*height/4,width/4,height/4);
					
					for(int c=0;c<2;c++)
						off_buffer.drawRect (b*width/4+c,a*height/4+c,width/4-c,height/4-c);
					if(click[a][b])
					{
						off_buffer.setColor(Color.red);
						for(int d=0;d<2;d++)
						off_buffer.drawOval (b*width/4-d,a*height/4-d,width/4+d,height/4+d);
						off_buffer.setColor (Color.black );				
					}
				}
		}
		else{
			resize(640,480);
			off_screen = createImage(width,height);
			off_buffer=off_screen.getGraphics ();	
			
			off_buffer.setColor (Color.orange );
			off_buffer.fillRect (0,0,640,480);
			off_buffer.setFont (font1);
			off_buffer.setColor(Color.red );
			off_buffer.drawImage (pic[2],30,50,250,180,this);			
			off_buffer.drawImage (pic[0],370,160,250,180,this);
			off_buffer.drawImage (pic[1],60,270,250,180,this);
			off_buffer.drawString("Æ´Í¼ÓÎÏ·", 320, 50);
			off_buffer.drawString ("Choose One!",320,100);
		}
		g.drawImage (off_screen,0,0,this);								   
	}
	
	public void repaint(){
		paint(this.getGraphics ());
	}

	public void mouseClicked(MouseEvent evt){}

	public void mouseEntered(MouseEvent evt){}

	public void mouseExited(MouseEvent evt){}

	public void mouseMoved(MouseEvent evt){	
		if(!gameStarted){	
			Point point;		
			point=evt.getPoint();
			if(point.x >30 && point.x<280 && point.y>50 && point.y<230)
			{
				off_buffer.setColor (Color.orange );
				off_buffer.fillRect (0,0,640,480);
				off_buffer.setFont (font1);
				off_buffer.drawImage (pic[2],25,45,250,180,this);			
				off_buffer.drawImage (pic[0],370,160,250,180,this);
				off_buffer.drawImage (pic[1],60,270,250,180,this);				
				off_buffer.setColor(Color.black );
				off_buffer.fillRect (30,225,250,5);
				off_buffer.fillRect (275,50,5,176);
				off_buffer.setColor(Color.red );
				off_buffer.drawString ("picture 2!",320,100);	
				this.getGraphics ().drawImage (off_screen,0,0,this);								   				
			}
			else if(point.x >370 && point.x<620 && point.y>160 && point.y<340)
			{
				off_buffer.setColor (Color.orange );
				off_buffer.fillRect (0,0,640,480);
				off_buffer.setFont (font1);
				off_buffer.drawImage (pic[2],30,50,250,180,this);			
				off_buffer.drawImage (pic[0],365,155,250,180,this);
				off_buffer.drawImage (pic[1],60,270,250,180,this);				
				off_buffer.setColor(Color.black );
				off_buffer.fillRect (370,335,250,5);
				off_buffer.fillRect (615,160,5,175);
				off_buffer.setColor(Color.red );
				off_buffer.drawString ("picture 0!",320,100);	
				this.getGraphics ().drawImage (off_screen,0,0,this);								   				
			
			}
			else if(point.x >60 && point.x<310 && point.y>270 && point.y<450)
			{
				off_buffer.setColor (Color.orange );
				off_buffer.fillRect (0,0,640,480);
				off_buffer.setFont (font1);
				off_buffer.drawImage (pic[2],30,50,250,180,this);			
				off_buffer.drawImage (pic[0],370,160,250,180,this);
				off_buffer.drawImage (pic[1],55,265,250,180,this);				
				off_buffer.setColor(Color.black );
				off_buffer.fillRect (60,445,250,5);
				off_buffer.fillRect (305,270,5,175);
				off_buffer.setColor(Color.red );
				off_buffer.drawString ("picture 1!",320,100);	
				this.getGraphics ().drawImage (off_screen,0,0,this);								   							
			}	
			else{
				repaint();
			}
		}
	}	

	public void mouseDragged(MouseEvent evt){
		if(!gameStarted)
			return;
		if(m_down){	
			Point point;
			Point temp;
			point=evt.getPoint();
			m_drag=true;
			repaint();
			Graphics david = this.getGraphics ();
			if(!not_redraw)
				off_drag_buf.drawImage (off_pic[map[last_downy][last_downx]],0,0,this);
			int x=point.x+stepx;
			int y=point.y+stepy;
			if(x>=0&&x<=480&&y>=0&&y<=360)
			david.drawImage (off_drag,point.x+stepx,point.y+stepy,this);
			not_redraw=true;
		}	
	}		
		
	public void mousePressed(MouseEvent evt){
		if(!gameStarted)
			return;
		Point point;
		Point temp;
		point=evt.getPoint();
		if(getarea(point) == point)
			return;
		else {
			temp=getarea(point);
			if(!m_down){
				if(map[temp.y][temp.x]==15)
					return;
				else{
					m_down=true;
					last_downx=temp.x;
					last_downy=temp.y;
					stepx=temp.x*160-point.x;
					stepy=temp.y*120-point.y;
				}
			}
			else if(m_down){
				m_down=false;
			}
		}
	}

	public void mouseReleased(MouseEvent evt){
	
		Point tPoint;
		tPoint=evt.getPoint();
		
		if(tPoint.x>=670&&tPoint.x<=810&&tPoint.y<=250&&tPoint.y>=210)
		{
			gameStarted=false;
		}
		
	if(gameStarted){
		if(m_drag){
			m_down=false;m_drag=false;not_redraw=false;
						
			Point point;
			Point temp;
			point=evt.getPoint();
			if(getarea(point) == point)
			{	repaint();
				return;}
			else {
				temp=getarea(point);
				if(map[temp.y][temp.x]!=15){
					repaint();return;}
				else{
						if(Math.abs (last_downx-temp.x)==1 && last_downy-temp.y==0)
						{
							int david;
							david=map[last_downy][last_downx];						
							map[last_downy][last_downx] =15;
							map[temp.y][temp.x]=david;
							stepCounts++;
							if(wingame())
							{
								gameStarted=false;	//timeCount.cancel();
							}
							repaint();
							return;
						}
						else if(last_downx-temp.x==0 && Math.abs (last_downy-temp.y)==1)
						{
							int david;
							david=map[last_downy][last_downx];						
							map[last_downy][last_downx] =15;
							map[temp.y][temp.x]=david;
							stepCounts++;
							if(wingame())
							{
								gameStarted=false;	//timeCount.cancel();
							}						
							repaint();
							return;
						}
						else{repaint(); return;}
				}
			}
		}
	}
		else{
			Point point;		
			point=evt.getPoint();
			if(point.x >30 && point.x<280 && point.y>50 && point.y<230)
			{
				gameStarted=true;	initmap(2);index=2;
				timeCount =new Timer();
				timeCount.schedule(new TimerTaskItem(),0,1000);
			}
			if(point.x >370 && point.x<620 && point.y>160 && point.y<340)
			{
				gameStarted=true;initmap(0);index=0;
				timeCount =new Timer();
				timeCount.schedule(new TimerTaskItem(),0,1000);
				}
			if(point.x >60 && point.x<310 && point.y>270 && point.y<450)
			{
				gameStarted=true;initmap(1);index=1;
				timeCount =new Timer();
				timeCount.schedule(new TimerTaskItem(),0,1000);
				}
			else return;
		}
	}
	
	public Point getarea(Point point){
		if(point.x>640 || point.y>480)
			return point;
		else return point = new Point (point.x/160,point.y/120);			
	}
	
	void initmap(int stage){
		picture = createImage(width,height);
		buffer = picture.getGraphics ();
		buffer.drawImage (pic[stage],0,0,640,480,this);
	
		for(int a=0;a<15;a++)
		{
				off_pic[a] = createImage(width/4,height/4);
				off_buf[a] = off_pic[a].getGraphics ();
				off_buf[a].drawImage (picture,0,0,width/4,height/4,
							(a%4)*width/4,(a/4)*height/4,(a%4+1)*width/4,(a/4+1)*height/4,this);
		}					
		initgame();
		repaint();
	}
	
	boolean wingame(){
		for(int a=0;a<4;a++)
			for(int b=0;b<4;b++)
			{
				if(map[a][b]!=a*4+b)
				return false;
				

			}
		
		timeCount.cancel();
		return true;
	}

	void initgame(){
		
		stepCounts=0;
		gameTime=0;
	for(int i=0;i<15;i++)
	{
		ran[i]=i;
	}
		
		
		for(int a=0;a<4;a++)
			for(int b=0;b<4;b++)
			{
				if(!(a==3 && b==3)){
					map[a][b] = (int)(Math.random()*14);
					if(ran[map[a][b]]==-1)
					{
						int temp=map[a][b];
						while(ran[temp]==-1){
							temp++;
							if(temp>14)
								temp=0;
						}
						map[a][b]=ran[temp];
						ran[temp]=-1;
					}
					else{
						ran[map[a][b]]=-1;
					}
				}
				else map[3][3] = 15;
			}
	}
}