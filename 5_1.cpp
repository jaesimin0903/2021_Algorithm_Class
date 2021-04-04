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
    data_Swap++;data_Swap++;
};


void makeHeap(itemType a[], int Root, int LastNode)

{

    int Parent, LeftSon, RightSon, Son, RootValue;

    Parent = Root;

    RootValue = a[Root];

    LeftSon = 2 * Parent + 1;

    RightSon = LeftSon + 1;



    while (LeftSon <= LastNode) {

        if (RightSon <= LastNode && a[LeftSon] < a[RightSon])

        {
            Son = RightSon; compare++;
        }

        else { Son = LeftSon; compare++; }

        if (RootValue < a[Son]) {

            compare++;

            a[Parent] = a[Son];
            data_Swap++;
            Parent = Son;

            LeftSon = Parent * 2 + 1;

            RightSon = LeftSon + 1;

        }

        else break;

    }

    a[Parent] = RootValue;
    data_Swap++;

}

void heapsort(itemType a[], int N)

{



    int i;

    for (i = N / 2; i >= 1; i--)

        makeHeap(a, i - 1, N - 1);

    for (i = N - 1; i >= 1; i--)

    {

        swap(a, 0, i);

        makeHeap(a, 0, i - 1);

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
    int j = 0;
    j = N;
    for (int i = 0; i < N; i++) {
        arr[i] = j;
        j--;
    }

    heapsort(arr, N);
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
        swap(arr1, r1, r2);

    }
    heapsort(arr1, N);
    cout << "SortedData_B: ";
    for (int i = 1; i <= 20; i++) {
        cout << arr1[i] << " ";
    }
    c2 = compare;
    d2 = data_Swap;;
    cout << endl;
    for (int i = 0; i < N; i++) {
        r1 = 1 + rand() % N - 1;
        arr2[i] = r1;
    }
    heapsort(arr2, N);
    cout << "SortedData_C: ";
    for (int i = 0; i < 20; i++) {
        cout << arr2[i] << " ";
    }
    c3 = compare;
    d3 = data_Swap;;
    cout << endl;
    print('A', c1, d1);
    print('B', c2, d2);
    print('C', c3, d3);
    compare = 0;
    data_Swap = 0;
    cout << endl;
    delete arr, arr1, arr2;
}