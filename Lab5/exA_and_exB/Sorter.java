import java.util.ArrayList;

public interface Sorter <E extends Number & Comparable<E>> {
	public void sort(ArrayList<Item<E>> theList);
}
