#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<stdexcept>

typedef int itemType;
using namespace std;

void Print_Vec(const vector<int>& vec) {
    for (const int& it : vec) {
        cout << it << " ";
    }
    cout << "\n";
}

void sameDelete(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
int main() {
    int a, b, r;
    int v1_size, v2_size;
    vector<int> v1, v2;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    cout << "";
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        r = dis(gen);
        v1.push_back(r);
    }
    cout << "집합 A - ";
    sameDelete(v1);
    Print_Vec(v1);

    for (int i = 0; i < b; i++) {
        r = dis(gen);
        v2.push_back(r);
    }
    cout << "\n" << "집합 B - ";
    sameDelete(v2);
    Print_Vec(v2);

    cout << "\n" << "교집합 - ";
    vector<int> v3;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1.at(i) == v2.at(j)) {
                v3.push_back(v1.at(i));
            }
        }
    }
    sort(v3.begin(), v3.end());
    Print_Vec(v3);

    cout << "\n" << "합집합 - ";
    vector<int> v4(v1.size() + v2.size());
    auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    v4.erase(iter, v4.end());
    Print_Vec(v4);
}