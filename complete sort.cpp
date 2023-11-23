#include <iostream>
#include <vector>

class SortingAlgorithms {
public:
    // Bubble Sort
    static void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Insertion Sort
    static void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    // Selection Sort
    static void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }

    // Merge Sort
    static void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    // Helper function for Merge Sort
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<int> leftArray(n1);
        std::vector<int> rightArray(n2);

        for (int i = 0; i < n1; ++i) {
            leftArray[i] = arr[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            rightArray[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                ++i;
            } else {
                arr[k] = rightArray[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = leftArray[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = rightArray[j];
            ++j;
            ++k;
        }
    }

    // Quick Sort
    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }

    // Helper function for Quick Sort
    static int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Heap Sort
    static void heapSort(std::vector<int>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; --i) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    // Helper function for Heap Sort
    static void heapify(std::vector<int>& arr, int n, int root) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != root) {
            std::swap(arr[root], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Binary Search
    static int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Element not found
    }
};

int main() {
    // Example usage of sorting algorithms and binary search
    std::vector<int> array = {64, 25, 12, 22, 11};

    // Applying Bubble Sort
    SortingAlgorithms::bubbleSort(array);
    std::cout << "After Bubble Sort:" << std::endl;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Applying Binary Search
    int target = 22;
    int result = SortingAlgorithms::binarySearch(array, target);
    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    return 0;
}
