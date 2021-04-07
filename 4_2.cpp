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

}
typedef int itemType;

itemType b[100000];

inline void swap(itemType a[], int i, int j) {
    itemType t = a[i]; a[i] = a[j]; a[j] = t;
    data_Swap++; data_Swap++;
};

void merge(int a[], int low, int mid, int high)

{

    int i, leftptr, rightptr, bufptr;

    leftptr = low; rightptr = mid + 1; bufptr = low;

    // 합병이 진행되고 있는 두 부분배열 모두에 아직 키가 남아있을 때 이들을 합병

    while (leftptr <= mid && rightptr <= high) {
        compare++;
        if (a[leftptr] < a[rightptr])

        {
            b[bufptr++] = a[leftptr++]; compare++;data_Swap++;
        }

        else { b[bufptr++] = a[rightptr++]; compare++;data_Swap++; }

    }

    // 두 부분배열 중 한 개의 배열에만 키가 남았을 때 이 키들을 배열 b의

    // 합병된 원소들 뒤에 그대로 복사

    if (leftptr > mid) {

        for (i = rightptr; i <= high; i++)

        {
            b[bufptr++] = a[i]; compare++;data_Swap++;
        }
    }
    else {

        for (i = leftptr; i <= mid; i++)

        {
            b[bufptr++] = a[i];  compare++;data_Swap++;

        }
    }


    // 합병이 끝나면 b에 있는 정렬된 키들을 a에 옮긴다

    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
        data_Swap++;
    }
}



void mergesort(itemType a[], int l, int r)

{

    int mid;



    if (l < r)

    {

        mid = (l + r) / 2; // 배열의 원소가 둘 이상이면



        mergesort(a, l, mid); // 분할된 왼쪽 부분 배열에 대하여

        // mergesort 순환호출





        mergesort(a, mid + 1, r); // 분할된 오른쪽 부분 배열에 대하여

        // mergesort 순환호출



        merge(a, l, mid, r); // 정렬된 왼쪽과 오른쪽을 merge

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
    int c1, c2, d1, d2;
    int* arr = new int[N];
    int* arr1 = new int[N];
    int j = 0;
    j = N;
    for (int i = 0; i < N; i++) {
        arr[i] = j;
        j--;
    }

    mergesort(arr, 0, N - 1);
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

    int r1, r2;
    for (int i = 0; i < N; i++) {
        r1 = 1 + rand() % N - 1;
        r2 = 1 + rand() % N - 1;
        SWAP(arr1, r1, r2);

    }
    for (int i = 1; i <= 20; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    mergesort(arr1, 0, N - 1);
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