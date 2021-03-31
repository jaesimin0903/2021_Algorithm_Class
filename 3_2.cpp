#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;

void shellsort(vector<int>& a, int N) // 쉘 정렬

{

    int i, j, h; int v;

    h = 1;

    do { h = 3 * h + 1; } while (h < N); // 배열의 크기보다 작으면서 가장 큰

    // h의 값을 찾는다



    do { // h값을 줋이면서 각 부분배열에 삽입정렬을 적용

        h = h / 3; // h값을 3으로 나누는 정수형 나눗셈

        for (i = h; i <= N; i++) {

            compare++; // 비교연산 카운터 증가

            v = a[i]; j = i;

            while (a[j - h] > v) {

                data_Swap++; // 자료이동 카운터 증가

                a[j] = a[j - h];

                j -= h;

                if (j <= h - 1)break;

            }

            a[j] = v;

        }

    } while (h > 1);

};





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
    arr.erase(arr.begin(), arr.begin() + N - 1);

    shellsort(arr, N);
    cout << "SortedData_A: ";
    for (int i = 1; i <= 20; i++) {
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
    for (int i = 0; i < 20;i++) {
        cout << v1[i] << " ";
    }
    // B 벡터 생성 // 
    cout << endl;
    shellsort(v1, N - 1);

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