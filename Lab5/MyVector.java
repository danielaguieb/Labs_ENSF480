import java.util.ArrayList;
import java.util.Iterator;
import java.util.function.Consumer;


// TODO this class needs to be fixed so that this is Comparable
public class MyVector<E extends Number & Comparable<E>> {

	private ArrayList<Item<E>> storageM;
	
	public MyVector(int n) {
		storageM = new ArrayList<Item<E>>(n);
	}
	
	public MyVector(ArrayList<Item<E>> source) {
		Consumer<Item<E>> func = x -> storageM.add(x);
		
		if (source == storageM)
			return;
		
		Iterator<Item<E>> it = source.iterator();
//		while(it.hasNext()) {
//			storageM.add(it.next());
//		}
		

		
		
		// MORE SUS
		source.forEach(func);
		
		
		//SUS
//		it.forEachRemaining(x -> storageM.add(x));
		
	}
	
	
	
	 
}
