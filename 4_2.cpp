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

    // �պ��� ����ǰ� �ִ� �� �κй迭 ��ο� ���� Ű�� �������� �� �̵��� �պ�

    while (leftptr <= mid && rightptr <= high) {
        compare++;
        if (a[leftptr] < a[rightptr])

        {
            b[bufptr++] = a[leftptr++]; compare++;data_Swap++;
        }

        else { b[bufptr++] = a[rightptr++]; compare++;data_Swap++; }

    }

    // �� �κй迭 �� �� ���� �迭���� Ű�� ������ �� �� Ű���� �迭 b��

    // �պ��� ���ҵ� �ڿ� �״�� ����

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


    // �պ��� ������ b�� �ִ� ���ĵ� Ű���� a�� �ű��

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

        mid = (l + r) / 2; // �迭�� ���Ұ� �� �̻��̸�



        mergesort(a, l, mid); // ���ҵ� ���� �κ� �迭�� ���Ͽ�

        // mergesort ��ȯȣ��





        mergesort(a, mid + 1, r); // ���ҵ� ������ �κ� �迭�� ���Ͽ�

        // mergesort ��ȯȣ��



        merge(a, l, mid, r); // ���ĵ� ���ʰ� �������� merge

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