import java.util.ArrayList;

public class ThreeColumnTable_Observer implements Observer {
	public ArrayList<Double> arrList;
	public DoubleArrayListSubject subject;
	
	
	public ThreeColumnTable_Observer(DoubleArrayListSubject doub) {
		subject = doub;
		subject.register(this);
	}

	public void display() {
		System.out.println("\nNotification to Three-Column Table Observer: Data Changed:");
		for(int i=0; i<arrList.size(); i++) {
			if(i%3 == 0 && i != 0)
				System.out.println();
			System.out.print(arrList.get(i) + " ");
		}
		System.out.println();
	}
	
	@Override
	public void update(ArrayList<Double> theList) {
		arrList = theList;
		display();
	}

}
