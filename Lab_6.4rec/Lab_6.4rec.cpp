#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

template <typename T>
void genArray(T* arr, int size, int i = 0)
{
    const int HIGH = 10;
    const int LOW = -10;

    if (i >= size) {
        return;
    }

    arr[i] = rand() % (HIGH - LOW + 1) + LOW;
    genArray(arr, size, i + 1);
}

template <typename T>
void Print(const T* arr, int size, int i = 0)
{
    if (i >= size) {
        return;
    }
    cout << setw(8) << arr[i];

    Print(arr, size, i + 1);
}

template <typename T>
T productElement(const T* arr, int size, int i = 0, T product = 1)
{
    if (i >= size) {
       return product;
    }

    if (arr[i] > 0) {
       product *= arr[i];
    }
    

    return productElement(arr, size, i + 1, product);
}

template <typename T>
int findMinIndex(const T* arr, int size, int i = 1, int minIndex = 0)
{
    if (i >= size) {
        return minIndex;
    }

    if (arr[i] < arr[minIndex]) {
        minIndex = i;
    }

    return findMinIndex(arr, size, i + 1, minIndex);
}

template <typename T>
T sumToMinElement(const T* arr, int minIndex, int i = 0, T sum = 0)
{
    if (i >= minIndex) {
        return sum;
    }

    sum += arr[i];
    return sumToMinElement(arr, minIndex, i + 1, sum);
}

template <typename T>
void sortArray(T* arr, int size, int i, int j)
{
    if (i >= size) {
        return;
    }

    if (j >= size) {
        sortArray(arr, size, i + 2, i + 2);
        return;
    }

    if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
    }

    sortArray(arr, size, i, j + 2);
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "Type size of array: ";
    cin >> n;

    double* arr = new double[n];

    genArray(arr, n);
    cout << "First Array:" << endl;
    Print(arr, n);

    double product = productElement(arr, n);
    cout << "\nProduct of Elements: " << product << endl;
    
    int minIndex = findMinIndex(arr, n);
    double sum = sumToMinElement(arr, minIndex);
    cout << "Sum to Min Element: " << sum << endl;

    sortArray(arr, n, 0, 1); 

    cout << "Sorted Array:" << endl;
    Print(arr, n);

    delete[] arr;

    return 0;
}
