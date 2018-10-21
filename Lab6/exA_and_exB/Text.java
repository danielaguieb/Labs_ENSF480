import java.awt.Graphics;
import java.awt.Graphics2D;

public class Text implements Component{
	public int x;
	public int y;
	public String text;
	
	public Text(String s, int x, int y) {
		// TODO check if this breaks any string rules lmao
		text = s;
		this.x = x;
		this.y = y;
	}

	@Override
	public void draw(Graphics g) {
		System.out.println("Text");
		Graphics2D g2d = (Graphics2D) g;
		g2d.drawString("Hello world", x, y);
	}
	
	
}
