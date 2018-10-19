import java.util.ArrayList;

public class BubbleSorter <E extends Number & Comparable<E>> implements Sorter <E> {

	@Override
	public void sort(ArrayList<Item<E>> theList) {
		 int n = theList.size(); 
	        for (int i = 0; i < n-1; i++) 
	            for (int j = 0; j < n-i-1; j++) 
	                if (theList.get(j).getItem().compareTo(theList.get(j+1).getItem()) >= 0)
	                { 
	                    Item<E> temp = theList.get(j); 
	                    theList.set(j, theList.get(j+1));
	                    theList.set(j+1, temp);
	                } 
	}

}
