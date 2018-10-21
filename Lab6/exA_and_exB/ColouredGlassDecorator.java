import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator{

	public ColouredGlassDecorator(Component c, int x, int y, int width, int height) {
		super(c, x, y, width, height);
	}
	
	public void draw(Graphics g) {
		System.out.println("CGD");
		t.draw(g);
		Graphics2D g2d = (Graphics2D) g;
		g2d.setColor(Color.green);
		g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER,
						 1 * 0.1f));
		g2d.fillRect(x, y, width, height);
	}
	
}
