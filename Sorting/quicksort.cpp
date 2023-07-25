#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int i = low, j = high;
    int pivot = arr[low];
    do {
        do {i++;} while (arr[i] <= pivot);
        do {j--;} while (arr[j] > pivot);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}
int main() {
    vector<int> arr = {10, 3, 1, 2, 6, 4, 5, 9, 8, 7};
    arr.push_back(INT_MAX);
    cout << "Before sorting: " << '\n';
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << '\n';
    quicksort(arr, 0, int(arr.size()) - 1);
    cout << "After sorting: " << '\n';
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}