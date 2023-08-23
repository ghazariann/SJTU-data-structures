#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;

    for (int j = i; j <= right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[left], arr[i - 1]);

    return i - 1;
}

int quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int pivotIndex = partition(arr, left, right);
    int comparisons = right - left;

    int leftCount = quickSort(arr, left, pivotIndex - 1);
    int rightCount = quickSort(arr, pivotIndex + 1, right);

    return comparisons + leftCount + rightCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << quickSort(arr, 0, n - 1) << "\n";

    return 0;
}
