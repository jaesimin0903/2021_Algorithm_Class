#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;
int swap_Sum = 0;
void insertion(vector<int>& a, int n)
{
    int i, j, v;

    for (i = 2; i <= n; i++)
    {
        compare++;
        v = a[i]; swap_Sum += v; j = i;
        while (a[j - 1] > v) { data_Swap++; a[j] = a[j - 1]; swap_Sum += a[j - 1];  j--; }
        swap_Sum += v;
        a[j] = v;

    }

}
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
            swap_Sum += v;
            while (a[j - h] > v) {

                data_Swap++; // 자료이동 카운터 증가
                //swap_Sum += a[j];

                a[j] = a[j - h];
                swap_Sum += a[j - h];
                j -= h;

                if (j <= h - 1)break;

            }

            a[j] = v;
            swap_Sum += v;
        }

    } while (h > 1);

};
void bubble_sort(vector<int>& list, int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        // 0 ~ (i-1)까지 반복
        compare++;
        for (j = 0; j < i; j++) {

            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if (list[j] > list[j + 1]) {
                data_Swap++;
                swap_Sum += list[j + 1];
                temp = list[j + 1];

                swap_Sum += list[j];
                list[j] = list[j + 1];

                swap_Sum += list[j];
                list[j] = temp;
                swap_Sum += list[j];

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
    std::vector<int> arr, arr1, arr2, arr3;
    arr.resize(N, 0);
    arr1.resize(N, 0);
    arr2.resize(N, 0);
    arr3.resize(N, 0);
    for (int i = 0; i < N; i++) {
        arr.push_back(j);
        j--;
    }
    arr.erase(arr.begin(), arr.begin() + N);
    j = N;
    for (int i = 0; i < N; i++) {
        arr2.push_back(j);
        j--;
    }
    arr2.erase(arr2.begin(), arr2.begin() + N - 1);
    j = N;
    for (int i = 0; i < N; i++) {
        arr3.push_back(j);
        j--;
    }
    arr3.erase(arr3.begin(), arr3.begin() + N - 1);
    insertion(arr2, N);

    cout << "insertion Sort: " << swap_Sum << endl;
    swap_Sum = 0;
    shellsort(arr3, N);
    cout << "Shell Sort: " << swap_Sum << endl;
    swap_Sum = 0;
    bubble_sort(arr, N);
    //swap_Sum = 0;
    cout << "Bubble Sort: " << swap_Sum << endl;

}