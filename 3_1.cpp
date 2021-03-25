#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int data_Swap = 0;
void insertionSort(std::vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        // Searching the upper bound, i.e., first 
        // element greater than *it from beginning
        auto const insertion_point =
            std::upper_bound(vec.begin(), it, *it);

        // Shifting the unsorted part
        std::rotate(insertion_point, it, it + 1);
        data_Swap++;
    }
    
}

// Function to print the array
void print(std::vector<int> vec)
{
    for (int x : vec)
        std::cout << x << " ";
    std::cout << '\n';
}

// Driver code
int main()
{
    std::vector<int> arr, arr1;
    for (int i = 20000; i > 0; i--) {
        arr.push_back(i);
    }
    insertionSort(arr);
 
    srand((unsigned)time(NULL));
    for (int i = 0; i < 20000; i++) {
        int a = 1 + rand() % 100000;
        arr1.push_back(a);
    }

    int k = 0;
    insertionSort(arr1);
    unique(arr1.begin(), arr1.end());
    arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
    while (arr1.size() != 20000)
    {
        for (int i = arr1.size(); i < 20000; i++) {
            int j = arr1.size();
            int a = 1 + rand() % 100000;
            arr1.push_back(a);
            unique(arr1.begin(), arr1.end());
            arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << arr1[i] << " ";
    }
}