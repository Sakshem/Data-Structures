public class QuickSort {
    public void sort(int[] array) {
        sort(array, 0, array.length - 1);
    } 
    private void sort(int[] array, int start, int end) {

        // base condition
        if (start >= end) return;

        // partition the array
        int boundary = partition(array, start, end);

        // sort left
        sort(array, start, boundary - 1);

        // sort right
        sort(array, boundary + 1, end);
    }
    private int partition(int[] array, int start, int end) {
        int pivot = array[end];
        int boundary = start - 1;
        for (int i = start; i <= end; i++) {
            if (array[i] <= pivot) {
                boundary++;
                swap(array, i, boundary);
            }
        }
        return boundary;
    }

    private void swap(int[] array, int index1, int index2) {
        var temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
 
}
