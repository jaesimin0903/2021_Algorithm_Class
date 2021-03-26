#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;
/*
int Bubble(int sorted, vector<int> &a, int n)
{
    int temp;
    if (*(a - 1) > *a) {
        temp = *(a - 1);
        *(a - 1) = *a;
        *a = temp;
        sorted = false;
    }
    return sorted;
}

void bubbleSort(vector<int> &a, int n)
{
    int i, Sorted;
    Sorted = false;
    while (!Sorted) {
        Sorted = true;
        for (i = 1; i < n; i++)
            Sorted = Bubble(Sorted, a[i], n);
    }
}
*/
void bubble_sort(vector<int> &list, int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        // 0 ~ (i-1)까지 반복
        compare++;
        for (j = 0; j < i; j++) {
            
            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if (list[j] > list[j + 1]) {
                data_Swap++;
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
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
    int c1, c2, d1, d2;
    cout << "N - ";
    cin >> N;
    int j = N;
    std::vector<int> arr, arr1;
    arr.resize(N, 0);
    arr1.resize(N, 0);
    for (int i = 0; i < N; i++) {
        arr.push_back(j);
        j--;
    }
    arr.erase(arr.begin(), arr.begin() + N );

    bubble_sort(arr, N);
    cout << "SortedData_A: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    c1 = compare;
    d1 = data_Swap;
    data_Swap = 0;
    compare = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) {
        int a = 1 + rand() % 100000;
        arr1.push_back(a);
    }
    unique(arr1.begin(), arr1.end());
    arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
    while (arr1.size() < N)
    {
        for (int i = arr1.size(); i < N; i++) {
            int j = arr1.size();
            int a = 1 + rand() % 100000;
            arr1.push_back(a);
            unique(arr1.begin(), arr1.end());
            arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
        }
    }
    bubble_sort(arr1, N);
    unique(arr1.begin(), arr1.end());
    arr1.erase(arr1.begin() + N, arr1.end());
    c2 = compare;
    d2 = data_Swap;
    cout << "SortedData_B: ";
    for (int i = 1; i <= 20; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    print('A', c1, d1);
    print('B', c2, d2);
}