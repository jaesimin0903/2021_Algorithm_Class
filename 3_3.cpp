#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;

void bubble_sort(vector<int>& list, int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        // 0 ~ (i-1)까지 반복

        for (j = 0; j < i; j++) {
            compare++;
            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if (list[j] > list[j + 1]) {
                data_Swap++;
                temp = list[j];
                data_Swap++;
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
    arr.erase(arr.begin(), arr.begin() + N);

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
    // B 벡터 생성 //


    vector<int> v1;
    v1.resize(0, 1);
    int r1, r2, test = 0;
    for (int i = 1; i <= N; i++) {
        v1.push_back(i);

    }
    srand(unsigned(time(NULL)));
    for (int i = 0; i < N; i++) {

        r1 = 1 + rand() % v1.size() - 1;
        r2 = 1 + rand() % v1.size() - 1;
        swap(v1.at(r1), v1.at(r2));

    }

    // B 벡터 생성 /
    bubble_sort(v1, N);
    c2 = compare;
    d2 = data_Swap;
    cout << "SortedData_B: ";
    for (int i = 0; i < 20; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    print('A', c1, d1);
    print('B', c2, d2);
}