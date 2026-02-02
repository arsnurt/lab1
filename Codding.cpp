#include <utility>
// Оптимизированная сортировка пузырьком

void bubbleSort(int* arr, int n) 
{
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
// Оптимизированная шейкер сортировка
void shakerSort(int* a, int n) {
    int l = 0, r = n - 1, k;
    while (l < r) {
        for (int j = r; j > l; j--) if (a[j-1] > a[j]) std::swap(a[j-1], a[j]), k = j;
        l = k;
        for (int j = l; j < r; j++) if (a[j] > a[j+1]) std::swap(a[j], a[j+1]), k = j;
        r = k;
    }
}

// Оптимизированная сортировка вставками 
void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) a[j + 1] = a[j], j--;
        a[j + 1] = k;
    }
}

// Оптимизированная сортировка бинарными вставками 
void binaryInsertionSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i], l = 0, r = i;
        while (l < r) {
            int m = (l + r) / 2;
            (k < a[m]) ? r = m : l = m + 1;
        }
        for (int j = i; j > l; j--) a[j] = a[j - 1];
        a[l] = k;
    }
}
// Оптимизированная сортировка слияниями
void merge(int* a, int l, int m, int r, int* t) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= m) t[k++] = a[i++]; while (j <= r) t[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = t[i];
}

void mergeSort(int* a, int l, int r, int* t) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m, t); mergeSort(a, m + 1, r, t);
        merge(a, l, m, r, t);
    }
}

void mergeSort(int* a, int n) { int* t = new int[n]; mergeSort(a, 0, n - 1, t); delete[] t; }

// Оптимизированная быстрая сортировка
void quickSort(int* a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, p = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < p) i++; while (a[j] > p) j--;
        if (i <= j) std::swap(a[i++], a[j--]);
    }
    quickSort(a, l, j); quickSort(a, i, r);
}

void quickSort(int* a, int n) { quickSort(a, 0, n - 1); }