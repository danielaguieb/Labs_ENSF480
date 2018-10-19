import java.util.ArrayList;

public class SelectionSort <E extends Number & Comparable<E>> implements Sorter <E> {

	@Override
	public void sort(ArrayList<Item<E>> theList) {
		int n = theList.size();
		  
        // One by one move boundary of unsorted subarray 
        for (int i = 0; i < n-1; i++) 
        { 
            // Find the minimum element in unsorted array 
            int min_idx = i; 
            for (int j = i+1; j < n; j++) 
                if (theList.get(j).getItem().compareTo(theList.get(min_idx).getItem()) <= 0)
                    min_idx = j; 
  
            // Swap the found minimum element with the first 
            // element 
            Item<E> temp = theList.get(min_idx);
            theList.set(min_idx, theList.get(i));
            theList.set(i, temp);
        }
	}

}
