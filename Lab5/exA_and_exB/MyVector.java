import java.util.ArrayList;
import java.util.Iterator;
import java.util.function.Consumer;

// TODO this class needs to be fixed so that this is Comparable
public class MyVector <E extends Number & Comparable<E>> {

	private ArrayList<Item<E>> storageM;
	private Sorter <E> sorter;
	
	public MyVector(int n) {
		storageM = new ArrayList<Item<E>>(n);
	}
	
	public MyVector(ArrayList<Item<E>> source) {
		source.forEach(x -> storageM.add(x));
		
//		Iterator<Item<E>> it = source.iterator();
//		while(it.hasNext()) {
//			storageM.add(it.next());
//		}
	}
	
	public void add(Item<E> value) {
		storageM.add(value);
	}
	
	public void setSortStrategy(Sorter <E> s) {
		sorter = s;
	}
	
	public void performSort() {
		sorter.sort(storageM);
	}
	
	public void display() {
		storageM.forEach(x -> System.out.println(x.getItem() + "	"));
		
//		Iterator<Item<E>> it = storageM.iterator();
//		while(it.hasNext()) {
//			System.out.println(it.next().getItem());
//		}
	}
	
	
	
	
	
	 
}
