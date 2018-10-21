import java.awt.Graphics;


public class Decorator implements Component{
	public Component t;
	public int x;
	public int y;
	public int width;
	public int height; 

	public Decorator(Component c, int x, int y, int width, int height) {
		t = c;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void draw(Graphics g) {
		System.out.println("Somehow in Decorator draw func");
	}
	
}
