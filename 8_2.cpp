#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int wayCheck(vector<vector<int>> A, int i, int j, int m, int n) {
    if (i == m) {
        return 2;
    }
    else if (j == n) return 3;
    else if (i == m && j == n) return 0;
    else {
        if (A[i][j] < A[i + 1][j] && A[i][j] < A[i][j + 1] && A[i][j] < A[i + 1][j + 1]) return 11; // u s d
        else if (A[i][j] < A[i + 1][j] && A[i][j] < A[i][j + 1] && A[i][j] == A[i + 1][j + 1]) return 10;
        else if (A[i][j] < A[i + 1][j] && A[i][j] < A[i + 1][j + 1]) return 9; // u s
        else if (A[i][j] < A[i + 1][j] && A[i][j] == A[i + 1][j + 1]) return 8;
        else if (A[i][j] < A[i + 1][j] && A[i][j] < A[i][j + 1]) return 7; // u d
        else if (A[i][j] < A[i][j + 1] && A[i][j] < A[i + 1][j + 1]) return 6; // d s
        else if (A[i][j] < A[i][j + 1] && A[i][j] == A[i + 1][j + 1]) return 5;
        else if (A[i][j] < A[i + 1][j]) return 4; // u
        else if (A[i][j] < A[i][j + 1]) return 3; // d
        else if (A[i][j] < A[i + 1][j + 1])return 2;
        else if (A[i][j] = A[i + 1][j + 1])return 1; // s
    }
}

int move(int A, int i, int j) {
    int ran;
    if (A == 11) {
        ran = 1 + rand() % 3;
        if (ran == 1) {
            //j++;
            cout << 'I';
            move(A, i, j + 1);
        }
        else if (ran == 2) {
            //i++; j++;
            cout << 'C';
            move(A, i + 1, j + 1);
        }
        else {
            //i++;
            cout << 'D';
            move(A, i + 1, j);
        }
    }
    else if (A == 10) {
        ran = 1 + rand() % 3;
        if (ran == 1) {
            j++;
            cout << 'I';
            return j++;
            move(A, i, j + 1);
        }
        else if (ran == 2) {
            i++; j++;
            cout << 'O';
            return i++, j++; move(A, i + 1, j + 1);
        }
        else {
            j++;
            cout << 'D';
            return i++;move(A, i, j + 1);
        }
    }
    else if (A == 9) {
        ran = 1 + rand() % 2;
        if (ran == 1) {
            j++;
            cout << 'I';
            return j++; move(A, i, j + 1);
        }
        else if (ran == 2) {
            i++; j++;
            cout << 'C'; move(A, i + 1, j + 1);
        }
    }
    else if (A == 8) {
        ran = 1 + rand() % 2;
        if (ran == 1) {
            j++;
            cout << 'I'; move(A, i, j + 1);
        }
        else if (ran == 2) {
            i++; j++;
            cout << 'O'; move(A, i + 1, j + 1);
        }
    }
    else if (A == 7) {
        ran = 1 + rand() % 2;
        if (ran == 1) {
            j++;
            cout << 'I'; move(A, i, j + 1);
        }
        else if (ran == 2) {
            i++;
            cout << 'D';move(A, i, j + 1);
        }
    }
    else if (A == 6) {
        ran = 1 + rand() % 2;
        if (ran == 1) {
            i++; j++;
            cout << 'C'; move(A, i + 1, j + 1);
        }
        else if (ran == 2) {
            i++;
            cout << 'D';move(A, i, j + 1);
        }
    }
    else if (A == 5) {
        ran = 1 + rand() % 2;
        if (ran == 1) {
            i++; j++;
            cout << 'O'; move(A, i + 1, j + 1);
        }
        else if (ran == 2) {
            i++;
            cout << 'D';move(A, i, j + 1);
        }
    }
    else if (A == 4) {
        j++;
        cout << 'I'; move(A, i, j + 1);
    }
    else if (A == 3) {
        i++; j++;
        cout << 'C'; move(A, i + 1, j + 1);
    }
    else if (A == 2) {
        i++;j++;
        cout << 'O'; move(A, i + 1, j + 1);
    }
    else if (A == 1) {
        i++;
        cout << 'D'; move(A, i, j + 1);
    }
    else return 0;
}

int main(void)
{
    string A, B;
    getline(cin, A);
    getline(cin, B);
    vector<vector<int>> way(10, vector<int>(10, 0));
    vector<int> num(10, 0);
    way.push_back(num);
    printf("편집거리테이블\n");
    //cout <<"최소편집 비용 : "<< DP(way,A, B);
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
            if (aChar[i - 1] == bChar[j - 1]) {
                E[i][j] = min(E[i - 1][j] + 1, min(E[i][j - 1] + 1, E[i - 1][j - 1]));

            }
            else {
                E[i][j] = min(E[i - 1][j] + 1, min(E[i][j - 1] + 1, E[i - 1][j - 1] + 2));

            }
        }
    }
    for (int i = 0;i <= aLen;i++) {
        for (int j = 0;j <= bLen;j++) {
            printf("%d\t", E[i][j]);

        }
        printf("\n");

    }
    /*for (int i = 0;i <= aLen;i++) {
        for (int j = 0;j <= bLen;j++) {
            if(i == aLen){
                cout << 'D';
                if(j!=bLen) j++;
            }
            else {
                if (E[i][j] < E[i + 1][j]) {
                    cout << 'I';
                    if (i != bLen) i++;
                }
            }
            if (j == bLen) {
                cout << 'I';
                i++;
            }
            else {
                if (E[i][j] < E[i][j + 1] && E[i][j + 1] > 0) {
                    cout << 'D';
                    j++;
                }
            }
            if((i == aLen || j == bLen)||(i==aLen && j==bLen)){
                break;
            }
            else {
                if (E[i][j] == E[i + 1][j + 1]) {
                    cout << 'O';
                    i++;
                    j++;
                }
                else if (E[i][j] < E[i + 1][j + 1]) {
                    cout << 'C';
                    i++;
                    j++;
                }
            }
        }
    }*/
    cout << "-----------------------------" << '\n';
    //for (int i = 0;i <= aLen;i++) {
    //    for (int j = 0;j <= bLen;j++) {
    //        way[i][j]= E[i][j];
    //    }
    //}
    vector<char> fin;
    int i = 0;
    int j = 0;
    int m = aLen;
    int n = bLen;
    //while(1){
    //    move(wayCheck(way, i, j, aLen, bLen), i, j);
    //    /*i+= move(wayCheck(way, i, j, aLen, bLen), i, j) ;
    //    j+= move(wayCheck(way, i, j, aLen, bLen), i, j);*/
    //}
    int s;
    while (1) {

        while (1) {
            if (i == m && j == n) {
                for (int i = 0;i < fin.size();i++) {
                    cout << fin[i];
                }
                return 0;
            }
            else if (j == n) {
                if (E[i][j] > E[i + 1][j]) { i = 0;j = 0;fin.erase(fin.begin(), fin.end());break; }
                else {
                    s = 1;
                }
            }
            else if (i == m) if (E[i][j] < E[i][j + 1]) { i = 0;j = 0;fin.erase(fin.begin(), fin.end()); break; }
            else {
                s = 4;
            }
            else {
                if (E[i][j] < E[i + 1][j] && E[i][j] < E[i][j + 1] && E[i][j] < E[i + 1][j + 1]) s = 11; // u s d
                else if (E[i][j] < E[i + 1][j] && E[i][j] < E[i][j + 1] && E[i][j] == E[i + 1][j + 1]) s = 10;
                else if (E[i][j] < E[i][j + 1] && E[i][j] < E[i + 1][j + 1]) s = 9; // u s
                else if (E[i][j] < E[i][j + 1] && E[i][j] == E[i + 1][j + 1]) s = 8;
                else if (E[i][j] < E[i + 1][j] && E[i][j] < E[i][j + 1]) s = 7; // u d
                else if (E[i][j] < E[i + 1][j] && E[i][j] < E[i + 1][j + 1]) s = 6; // d s
                else if (E[i][j] < E[i + 1][j] && E[i][j] == E[i + 1][j + 1]) s = 5;
                else if (E[i][j] < E[i][j + 1]) s = 4; // u
                else if (E[i][j] < E[i + 1][j]) s = 1; // d
                else if (E[i][j] < E[i + 1][j + 1])s = 3;
                else if (E[i][j] = E[i + 1][j + 1])s = 2; // s
            }
            int ran;
            srand(time(NULL));
            if (s == 11) {

                ran = 1 + rand() % 3;
                if (ran == 1) {
                    j++;
                    fin.push_back('I');

                }
                else if (ran == 2) {
                    i++; j++;
                    fin.push_back('C');

                }
                else {
                    i++;
                    fin.push_back('D');

                }
            }
            else if (s == 10) {
                ran = 1 + rand() % 3;
                if (ran == 1) {
                    j++;
                    fin.push_back('I');


                }
                else if (ran == 2) {
                    i++; j++;
                    fin.push_back('O');

                }
                else {
                    i++;
                    fin.push_back('D');

                }
            }
            else if (s == 9) {
                ran = 1 + rand() % 2;
                if (ran == 1) {
                    j++;
                    fin.push_back('I');

                }
                else if (ran == 2) {
                    i++; j++;
                    fin.push_back('C');
                }
            }
            else if (s == 8) {
                ran = 1 + rand() % 2;
                if (ran == 1) {
                    j++;
                    fin.push_back('I');
                }
                else if (ran == 2) {
                    i++; j++;
                    fin.push_back('O');
                }
            }
            else if (s == 7) {
                ran = 1 + rand() % 2;
                if (ran == 1) {
                    j++;
                    fin.push_back('I');
                }
                else if (ran == 2) {
                    i++;
                    fin.push_back('D');
                }
            }
            else if (s == 6) {
                ran = 1 + rand() % 2;
                if (ran == 1) {
                    i++; j++;
                    fin.push_back('C');
                }
                else if (ran == 2) {
                    i++;
                    fin.push_back('D');
                }
            }
            else if (s == 5) {
                ran = 1 + rand() % 2;
                if (ran == 1) {
                    i++; j++;
                    fin.push_back('O');
                }
                else if (ran == 2) {
                    i++;
                    fin.push_back('D');
                }
            }
            else if (s == 4) {
                j++;
                fin.push_back('I');
            }
            else if (s == 3) {
                i++; j++;
                fin.push_back('C');
            }
            else if (s == 2) {
                i++;j++;
                fin.push_back('O');
            }
            else if (s == 1) {
                i++;
                fin.push_back('D');
            }
            else return 0;
        }
    }
    printf("-----------------------------------\n");



}



