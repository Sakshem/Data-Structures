#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& A, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    vector<int> B((int)A.size() + 1);
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}
void mergesort(vector<int>& A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main() {
    vector<int> A = {8, 2, 9, 6, 5, 3, 7, 4};
    mergesort(A, 0, A.size() - 1);
    for (auto i: A) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}