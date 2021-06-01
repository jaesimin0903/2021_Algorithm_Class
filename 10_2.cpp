#include <iostream>
#include <vector>
#include<stdlib.h>
#include<string>

using namespace std;

int comp = 0; // 비교연산카운터변수

vector<int> indexBF;
vector<int> indexRK;
vector<int> indexKMP;

void brutesearch(vector<vector<char>>& origin, vector<vector<char>>& pattern)

{
	int i = 0;//행
	int j = 0;//열
	int a = 0;//패턴행
	int b = 0;//패턴열

	for (i = 0; i + 9 < 100; i++) {
		for (j = 0; j + 9 < 100; j++) {
			for (a = i; a < i + 10; a++)
				for (b = j; b < j + 10; b++) {
					if (origin[a][b] != pattern[a - i][b - j])comp++;
					else comp++;
				}
		}
	}
	cout << comp << endl;
	comp = 0;
}



const int q = 33554393; // 해시함수에의해결정되는값, 통상소수를선택함

const int d = 26; // 알파벳크기



int index(char c)
{
	if (c == ' ') return ' ';
	else return toupper(c) - 'A';
}



void rksearch(vector<vector<char>>& origin, vector<vector<char>>& pattern)

{
	int i, dM = 1, h1 = 0, h2 = 0;
	int j;
	int a, b;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) dM = (d * dM) % q;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++) {
			h1 = (h1 * d + index(pattern[i][j])) % q; // Pattern의Hash value

			h2 = (h2 * d + index(origin[i][j])) % q; // Text의Hash value
		}
	}
	for (i = 0; i + 9 <= 99; i++) {
		for (j = 0; j + 9 <= 99; j++) {
			comp++;
			h2 = (h2 - index(origin[i][j]) * dM) % q;

			h2 = (h2 * d + index(origin[i + 9][j + 9])) % q;
			if (h1 == h2)comp++;


		}
	}
	cout << comp;
	comp = 0;
}






void main()

{
	vector<char> row(100, 'A');
	vector<vector<char>> col(100, vector<char>(100, 'A'));
	col.push_back(row);
	vector<char> row1(10, 'A');
	vector<vector<char>> pattern(10, vector<char>(10, 'A'));
	pattern.push_back(row1);
	pattern[9][9] = 'B';
	cout << "--------------------BF---------------------" << endl;

	brutesearch(col, pattern);




	cout << "--------------------RK---------------------" << endl;

	rksearch(col, pattern);






}


