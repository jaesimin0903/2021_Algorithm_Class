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
        while (a[j - 1] > v) { //cout << "here" << endl;
            data_Swap++; a[j] = a[j - 1]; j--;
        }
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

    c1 = compare;
    d1 = data_Swap;
    data_Swap = 0;
    compare = 0;
    // B 氦磐 积己 //


    vector<int> v1;

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
    cout << endl;
    // B 氦磐 积己 /


    v1.insert(v1.begin(), -1);
    insertion(v1, N);

    c2 = compare;
    d2 = data_Swap;
    cout << "SortedData_B: ";
    for (int i = 1; i <= 20; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    print('A', c1, d1);
    print('B', c2, d2);
}