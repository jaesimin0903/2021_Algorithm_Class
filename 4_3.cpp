#include<string.h>    //strcmp
#include<stdio.h>    //printf
#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<vector>

#define _CRT_SECURE_NO_WARNIGS
using namespace std;


bool comp(pair<string, int>a, pair<string, int>b) {//대소비교
    return a.second > b.second;
}
int main(void)
{
    FILE* fp = NULL;
    vector<string> word;
    vector<int> number;
    vector<int> high;
    vector < pair<string, int>> v;

    int c;
    int i = 0;
    int j = 0;
    int z = 1;
    fopen_s(&fp, "datafile.txt", "r");
    if (fp == NULL)
    {
        cout << "error";
    }
    else
    {
        cout << "perfect open" << endl;
    }
    char* arr = new char[500];

    char* context = NULL; // 남은 문자열 넣는곳

    while ((c = fgetc(fp)) != EOF) //파일 읽기
    {
        arr[i] = c;
        i++;
    }
    char* ptr = strtok_s(arr, ".,/  \n", &context); //토큰화
    while (ptr != NULL)
    {
        word.push_back(ptr);
        j++;
        ptr = strtok_s(NULL, ".,/ \n", &context);
    }
    word.erase(word.begin() + 65, word.end());
    sort(word.begin(), word.end());
    for (int i = 0;i < word.size();i++) {//중복값 구하기
        if (i + 2 <= word.size()) {
            while (word[i] == word[i + 1]) {

                z++;
                i++;

            }
            number.push_back(z);
            z = 1;
        }
        else {
            z = 1;
            number.push_back(z);

        }
    }
    unique(word.begin(), word.end());
    int h = 0;
    for (int i = 0; i < number.size() - 1;i++) {
        if (number[i] != 1) {
            high.push_back(number[i]);
            v.push_back(pair<string, int>(word[i], high[h]));//중복되는 요소 다른 벡터에 넣기
            number.erase(number.begin() + i);
            word.erase(word.begin() + i);
            h++;
        }

    }
    sort(v.begin(), v.end(), comp);

    for (int i = 0;i < v.size(); i++) {
        cout << v[i].first << ": " << v[i].second << endl;
    }
    word.erase(word.begin() + 52, word.end());

    for (int i = 0;i < word.size();i++) {
        cout << word[i] << ": " << number[i] << endl;
    }
    return 0;

    fclose(fp);



}

