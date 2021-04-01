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
void shellsort(vector<int>& a, int N) // �� ����

{

    int i, j, h; int v;

    h = 1;

    do { h = 3 * h + 1; } while (h < N); // �迭�� ũ�⺸�� �����鼭 ���� ū

    // h�� ���� ã�´�




    do { // h���� ���̸鼭 �� �κй迭�� ���������� ����

        h = h / 3; // h���� 3���� ������ ������ ������

        for (i = h; i <= N; i++) {

            compare++; // �񱳿��� ī���� ����

            v = a[i]; j = i;
            swap_Sum += v;
            while (a[j - h] > v) {

                data_Swap++; // �ڷ��̵� ī���� ����
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
        // 0 ~ (i-1)���� �ݺ�
        compare++;
        for (j = 0; j < i; j++) {

            // j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
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