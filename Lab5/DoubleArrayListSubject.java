import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject{
	public ArrayList <Double> data;
	public ArrayList<Observer> observers;
	
	public DoubleArrayListSubject() {
		data = new ArrayList<Double>();
		observers = new ArrayList<Observer>();
	}
	
	public void addData(Double theD) {
		data.add(theD);
		notifyObservers();
	}
	
	public void setData(Double element, int index) {
		data.set(index, element);
		notifyObservers();
	}
	
	public ArrayList <Double> getData() {
		return data;
	}
	
	public void populate(double[] theArr) {
		for(int i=0; i<theArr.length; i++) {
			data.add(theArr[i]);
		}
	}
	
	public void display() {
		if(data.isEmpty()) {
			System.out.println("Empty List ...");
			return;
		}
		data.forEach(x -> System.out.println(x + " "));
		
	}

	@Override
	public void register(Observer o) {
		observers.add(o);
		o.update(data);
	}

	@Override
	public void remove(Observer o) {
		observers.remove(o);
	}

	@Override
	public void notifyObservers() {
		for(int i=0; i<observers.size(); i++) {
			Observer o = observers.get(i);
			o.update(data);
		}
	}
	
	
}
