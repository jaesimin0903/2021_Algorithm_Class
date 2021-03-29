#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;

void insertion(vector<int>& a, int n)
{
    int i, j, v;

    for (i = 2; i <= n; i++)
    {
        compare++;
        v = a[i]; j = i;
        while (a[j - 1] > v) { data_Swap++; a[j] = a[j - 1]; j--; }
        a[j] = v;

    }

}

// Function to print the array
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
    //硅凯 A 积己
    for (int i = 0; i < N; i++) {
        arr.push_back(j);
        j--;
    }
    arr.erase(arr.begin(), arr.begin() + N - 1);
    insertion(arr, N);

    cout << "SortedData_A: ";
    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    c1 = compare;
    d1 = data_Swap;
    data_Swap = 0;
    compare = 0;
    //硅凯 B 积己
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
    insertion(arr1, N);
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