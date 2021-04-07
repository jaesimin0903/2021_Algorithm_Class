#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;
int swap_Sum = 0;

typedef int itemType;
vector <int> sorted;

inline void swap(itemType a[], int i, int j) {

    itemType t = a[i]; a[i] = a[j]; a[j] = t;
    //data_Swap++;data_Swap++;
};


//int*a = new itemType[];  int* b = new itemType[];  int *N = new itemType[];
void CountSort(itemType a[], itemType b[], itemType N[], int n, int k) {
    int i, j;
    for (i = 1; i <= k; i++) N[i] = 0; // 배열 초기화
    for (i = 1; i <= n; i++) N[a[i]] = N[a[i]] + 1; data_Swap++;
    for (i = 2; i <= k; i++) N[i] = N[i] + N[i - 1];
    for (j = n; j >= 1; j--) {
        b[N[a[j]]] = a[j];
        N[a[j]] = N[a[j]] - 1;
    }
}
//int count[30000];
void newCountSort(itemType a[], itemType count[], int n) {
    for (int i = 0;i < 30000;i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i] - 1]++;
        compare++;
        data_Swap += 2;
    }
    for (int i = 0; i < 20; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i];j++) {
                cout << i + 1 << " ";
            }
        }
    }
}


void print(char A, int a, int b)
{
    cout << "Compare_Cnt_" << A << " " << a << ", " << "DataMove_Cnt_" << A << " " << b << endl;
}


int main()
{
    int N;
    cout << "N - ";
    cin >> N;
    int c1, c2, c3, d1, d2, d3;
    int* arr = new int[N];
    int* arr1 = new int[N];
    int* arr2 = new int[N];
    int* rarr = new int[N];
    int* rarr1 = new int[N];
    int* rarr2 = new int[N];
    int* count = new int[30000];
    int j = 0;
    j = N;
    for (int i = 0; i < N; i++) {
        arr[i] = j;
        j--;
    }
    cout << "SortedData_A: ";
    newCountSort(arr, count, N);


    for (int i = 0; i < N; i++) {
        arr1[i] = i;
    }

    c1 = compare;
    d1 = data_Swap;;
    cout << endl;

    compare = 0;
    data_Swap = 0;
    int r1, r2;
    for (int i = 0; i < N; i++) {
        r1 = 1 + rand() % N - 1;
        r2 = 1 + rand() % N - 1;
        swap(arr1, r1, r2);

    }
    cout << "SortedData_B: ";
    newCountSort(arr1, count, N);

    c2 = compare;
    d2 = data_Swap;;
    cout << endl;
    compare = 0;
    data_Swap = 0;
    for (int i = 0; i < N; i++) {
        r1 = 1 + rand() % N - 1;
        arr2[i] = r1;
    }
    cout << "SortedData_C: ";
    newCountSort(arr2, count, N);


    c3 = compare;
    d3 = data_Swap;;
    cout << endl;

    print('A', c1, d1);
    print('B', c2, d2);
    print('C', c3, d3);

    cout << endl;
    delete arr, arr1, arr2;
}