#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;
int swap_Sum = 0;
void SWAP(int* arr, int a, int b) {
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    data_Swap++;
}
int Partition(int* arr, int len) {
    SWAP(arr, 0, rand() % len);
    int temp = arr[0];

    int low = 0;
    int high = len;

    while (1) {
        do {
            low++;
            compare++;
        } while (low < len && arr[low] < temp);
        do {
            high--;
            compare++;
        } while (high > 0 && arr[high] > temp);

        if (low > high) break;
        SWAP(arr, low, high);
    }
    SWAP(arr, 0, high);
    return high;
}
void Quicksort(int* arr, int len) {
    if (len <= 1) return;

    int pivot = Partition(arr, len);
    Quicksort(arr, pivot);
    Quicksort(arr + pivot + 1, len - pivot - 1);
}
/*
int Old_Partition(int* arr, int left, int right) {
    int pivot = left;
    while (left < right) {
        while (arr[pivot] > arr[left] && left < right)
            left++;
        while (arr[pivot] <= arr[right] && left < right)
            right--;
        if (left < right)
            SWAP(arr, left, right);
    }
    SWAP(arr, pivot, right);
    return right;
}

void Old_Quicksort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = Old_Partition(arr, left, right);
        Old_Quicksort(arr, left, pivot);
        Old_Quicksort(arr, pivot + 1, right);
    }
}
*/




void print(char A, int a, int b)
{
    cout << "Compare_Cnt_" << A << " " << a << ", " << "DataMove_Cnt_" << A << " " << b << endl;
}


int main()
{
    int N;
    cout << "N - ";
    cin >> N;
    int c1, c2, d1, d2;
    int* arr = new int[N];
    int* arr1 = new int[N];
    int j = 0;
    j = N;
    for (int i = 0; i < N; i++) {
        arr[i] = j;
        j--;
    }

    Quicksort(arr, N);
    cout << "SortedData_A: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 1; i <= N; i++) {
        arr1[i] = i;
    }

    c1 = compare;
    d1 = data_Swap;;
    cout << endl;

    compare = 0;
    data_Swap = 0;
    //(unsigned(time(NULL)));

    int r1, r2;
    for (int i = 0; i < N; i++) {

        r1 = 1 + rand() % N - 1;
        r2 = 1 + rand() % N - 1;
        SWAP(arr1, r1, r2);

    }
    Quicksort(arr1, N);
    cout << "SortedData_B: ";
    for (int i = 1; i <= 20; i++) {
        cout << arr1[i] << " ";
    }
    c2 = compare;
    d2 = data_Swap;;
    cout << endl;
    print('A', c1, d1);
    print('B', c2, d2);
    compare = 0;
    data_Swap = 0;
    cout << endl;
    delete arr, arr1;
}