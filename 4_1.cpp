#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
int compare = 0;
int swap_Sum = 0;

int sum = 0;
int partition(vector<int>& a, int l, int r) {
    int i, j; int v;
    if (r > l) {
        v = a[l]; i = l; j = r + 1;
        while (1) {

            while (i < a.size() - 1 && a[++i]);
            while (a[--j] > v);
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        swap(a[j], a[l]);
    }
    return j;

}

void quicksort(vector<int>& a, int l, int r) {
    int  j;
    if (r > l) {

        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
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
    int j = N;
    std::vector<int> arr;
    arr.resize(N, 0);
    for (int i = 0; i < N; i++) {
        arr.push_back(j);
        j--;
    }
    arr.erase(arr.begin(), arr.begin() + N);



    quicksort(arr, 0, arr.size() - 1);
    for (int i = 0;i < 20;i++) {
        cout << arr[i] << " ";
    }
}