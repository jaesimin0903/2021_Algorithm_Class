#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;

void shellsort(vector<int>&a, int N) // �� ����

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

            while (a[j - h] > v) {

                data_Swap++; // �ڷ��̵� ī���� ����

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

    shellsort(arr1, N);
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