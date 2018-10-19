import java.util.ArrayList;

public class InsertionSorter <E extends Number & Comparable<E>> implements Sorter <E> {

	@Override
	public void sort(ArrayList<Item<E>> theList) {
		int n = theList.size(); 
        for (int i=1; i<n; ++i) 
        { 
            Item<E> key = theList.get(i); 
            int j = i-1; 
  
            /* Move elements of arr[0..i-1], that are 
               greater than key, to one position ahead 
               of their current position */
            while (j>=0 && (theList.get(j).getItem().compareTo(key.getItem())) >= 0)
            { 
                theList.set(j+1, theList.get(j));
                j = j-1; 
            } 
            theList.set(j+1, key);
        } 
	}


}
