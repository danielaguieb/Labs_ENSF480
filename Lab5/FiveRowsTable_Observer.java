import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {
	public ArrayList<Double> arrList;
	public DoubleArrayListSubject subject;
	
	
	public FiveRowsTable_Observer(DoubleArrayListSubject doub) {
		subject = doub;
		subject.register(this);
	}
	
	public void display() {
		System.out.println("\nNotification to FiveRowsTable Observer: Data Changed:");
		int row = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = row; j < arrList.size(); j+=5)
			{
				System.out.print(arrList.get(j) + " ");
			}
			System.out.println();
			row++;
		}
		
		System.out.println();
	}

	@Override
	public void update(ArrayList<Double> theList) {
		arrList = theList;
		display();
	}
}
