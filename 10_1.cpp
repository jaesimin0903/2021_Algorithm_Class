#include <iostream>
#include <vector>
#include<stdlib.h>
#include<string>

using namespace std;

int comp = 0; // 비교연산카운터변수

vector<int> indexBF;
vector<int> indexRK;
vector<int> indexKMP;

int brutesearch(string a, string p)

{

	int  k, s = 0;
	int i = 0;
	int j = 0;
	int M = p.size(), N = a.size();//M - pattern , N - String


	while (i != N && j != M)

	{



		if (a[i] != p[j])//패턴과 문자열이 맞지 않는경우

		{
			comp++;
			i = i - j + 1; // Text 는한칸씩이동한다

			j = 0; // Pattern 은항상처음부터비교한다

		}
		else {
			comp++;
			i++;
			j++;
		}
		if (j == M) {// J 증가횟수와 패턴의 크기가 일치하면 벡터에 인덱스 저장 후 다시 비교위해 J 재할당

			indexBF.push_back(i - M); j = 0;
		}
	}

	for (int z = 0; z < indexBF.size(); z++) {
		cout << indexBF[z] << " ";
	}
	cout << comp << endl;
	comp = 0;
	return 0;
}



const int q = 33554393; // 해시함수에의해결정되는값, 통상소수를선택함

const int d = 26; // 알파벳크기



int index(char c)
{
	if (c == ' ') return ' ';
	else return toupper(c) - 'A';
}



int rksearch(string p, string a)

{
	int i, dM = 1, h1 = 0, h2 = 0;

	int M = p.size(), N = a.size();

	for (i = 1; i < M; i++) dM = (d * dM) % q;

	for (i = 0; i < M; i++)
	{
		h1 = (h1 * d + index(p[i])) % q; // Pattern의Hash value

		h2 = (h2 * d + index(a[i])) % q; // Text의Hash value
	}

	for (i = 0; i <= N - M; i++) // Hash value가같지않다면비교한다.

	{

		comp++;

		h2 = (h2 - index(a[i]) * dM) % q;

		h2 = (h2 * d + index(a[i + M])) % q;

		if (h1 == h2) {
			indexRK.push_back(i + 1);
		}

	}

	for (int z = 0; z < indexRK.size(); z++) {
		cout << indexRK[z] << " ";
	}
	cout << comp;
	comp = 0;
	return 0;

}





void result(int index)

{

	cout << "Comparison : " << comp << "\n";

	cout << "indexPattern : " << index << "\n\n\n";

	comp = 0;

}
int* SP;
void initSP(string p);
void kmpsearch(string p, string a) {
	int i, j, m = p.size(), n = a.size();
	initSP(p);

	for (i = 0, j = -1; i <= n - 1; i++) {

		while ((j >= 0) && (p[j + 1] != a[i])) {
			comp++; j = SP[j];
		}
		if (p[j + 1] == a[i]) {
			comp++; j++;
		}
		else comp++;
		if (j == m - 1) {
			comp++;
			indexKMP.push_back(i - m + 1);
			j = SP[j];
		}
		else comp++;
	}
	for (int z = 0; z < indexKMP.size(); z++) {
		cout << indexKMP[z] << ' ';
	}
	cout << comp;
	comp = 0;

}
void initSP(string p) {

	int i, j, m = p.size();
	SP = new int[m];
	SP[0] = -1;
	for (i = 1, j = -1; i <= m - 1; i++) {

		while ((j >= 0) && (p[j + 1] != p[i])) {
			comp++; j = SP[j];
		}
		if (p[j + 1] == p[i]) {
			comp++; j++;
		}
		else comp++;
		SP[i] = j;
	}
}
// SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.




void main()

{


	string A, B;

	getline(cin, A);
	getline(cin, B);



	char* Pattern2 = new char[B.size()];
	char* Text2 = new char[A.size()];


	cout << "--------------------BF---------------------" << endl;

	int indexPattern = brutesearch(A, B);




	cout << "--------------------RK---------------------" << endl;

	indexPattern = rksearch(B, A);

	cout << "\n-------------------KMP---------------------" << endl;

	kmpsearch(B, A);




}


