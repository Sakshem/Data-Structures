import java.util.*;
public class Main {
    public static void main(String[] args) {
        // int[] array = {7, 3, 1, 4, 6, 2, 3};
        // int[] array = {7, 3, 2, 6};
        int[] array = {5, 1, 7, 2, 6, 4};
        // var sorter = new BubbleSort();
        // var sorter = new SelectionSort();
        // var sorter = new InsertionSort();
        // var sorter = new MergeSort();
        // var sorter = new QuickSort();
        // var sorter = new CountingSort();
        var sorter = new BucketSort();
        sorter.sort(array, 3);

        System.out.println(Arrays.toString(array));
    }
}
