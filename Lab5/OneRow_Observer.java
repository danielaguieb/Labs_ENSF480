import java.util.ArrayList;

public class OneRow_Observer implements Observer {
	public ArrayList<Double> arrList;
	public DoubleArrayListSubject subject;
	
	
	public OneRow_Observer(DoubleArrayListSubject doub) {
		subject = doub;
		subject.register(this);
	}
	
	public void display() {
		System.out.println("Notification to One-Row Observer: Data Changed:");
		arrList.forEach(x -> System.out.print(x + " "));
		System.out.println();
	}
	
	@Override
	public void update(ArrayList<Double> theList) {
		arrList = theList;
		display();
	}

}
