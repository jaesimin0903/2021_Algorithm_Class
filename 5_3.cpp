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

};

typedef struct node* node_pointer;
typedef struct node {
    itemType value;
    node_pointer next;
};
node_pointer TABLE[10], x, z, temp;
void radixSort(itemType* a, int n) {
    int i, j, cnt, radix, radix_mod = 10, cipher = 0;
    i = n;
    while (i > 0) { i = i / 10; cipher++; } // cipher : 입력 데이터의 자리수 (ex. 450 -> 3)
    for (i = 0; i < cipher; i++) {
        for (j = 0; j < n; j++) {
            compare++;
            cnt = 0; radix = (a[j] % radix_mod) / (radix_mod / 10);
            /* radix_mod = 10 이면 radix는 a[j]의 일의 자리수
           radix_mod = 100 이면 radix는 a[j]의 십의 자리수 */
            temp = new node; temp->value = a[j]; temp->next = z;
            data_Swap++;
            if (TABLE[radix] == z) {
                // z는 list의 끝을 확인하기 위한 노드 포인터 (NULL에 해당)
                TABLE[radix] = temp;
            }
            else {
                x = TABLE[radix];
                while (x->next != z) {
                    x = x->next;
                }
                x->next = temp;
            }
        }

        for (j = 0; j < 10; j++) {
            if (TABLE[j] != z) {
                x = TABLE[j]; 
                while (x != z) {
                    a[cnt++] = x->value; data_Swap++;
                    temp = x; // 메모리에서 노드를 삭제하기 위해 임시 저장
                    x = x->next;
                    delete temp; // 배열에 이미 넣은 노드를 메모리에서 삭제
                }
            }
            TABLE[j] = z;
        }
        radix_mod *= 10;
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
    int* count = new int[30000];
    int j = 0;
    j = N;
    for (int i = 0; i < N; i++) {
        arr[i] = j;
        j--;
    }
    cout << "SortedData_A: ";
    radixSort(arr, N);
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
    cout << "SortedData_B: ";
    radixSort(arr1, N);
    for (int i = 0; i < 20; i++) {
        cout << arr1[i] << " ";
    }
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
    radixSort(arr2, N);
    for (int i = 0; i < 20; i++) {
        cout << arr2[i] << " ";
    }

    c3 = compare;
    d3 = data_Swap;;
    cout << endl;

    print('A', c1, d1);
    print('B', c2, d2);
    print('C', c3, d3);
    delete arr, arr1, arr2;
}