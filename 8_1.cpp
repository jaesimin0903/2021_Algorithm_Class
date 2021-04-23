#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DP(string A, string B)
{
    int aLen = A.size();
    int bLen = B.size();
    int** E;
    char* aChar, * bChar;
    aChar = (char*)A.c_str();
    bChar = (char*)B.c_str();
    E = new int* [aLen + 1];
    for (int i = 0; i <= aLen; i++)
    {
        E[i] = new int[bLen + 1];
    }
    for (int i = 0; i <= aLen; i++)
    {
        E[i][0] = i;
    }
    for (int i = 0; i <= bLen; i++)
    {
        E[0][i] = i;
    }
    for (int i = 1; i <= aLen; i++)
    {
        for (int j = 1; j <= bLen; j++)
        {
            if (aChar[i - 1] == bChar[j - 1])
                E[i][j] = min(E[i - 1][j] + 1, min(E[i][j - 1] + 1, E[i - 1][j - 1]));
            else
                E[i][j] = min(E[i - 1][j] + 1, min(E[i][j - 1] + 1, E[i - 1][j - 1] + 2));
        }
    }
    for (int i = 0;i <= aLen;i++) {
        for (int j = 0;j <= bLen;j++) {
            printf("%d\t", E[i][j]);

        }
        printf("\n");

    }
    printf("-----------------------------------\n");
    return E[aLen][bLen];
}
int main(void)
{
    string A, B;
    getline(cin, A);
    getline(cin, B);
    printf("편집거리테이블\n");
    cout << "최소편집 비용 : " << DP(A, B);
}


