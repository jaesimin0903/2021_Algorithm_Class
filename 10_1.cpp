#include <iostream>
#include <vector>
#include<stdlib.h>

using namespace std;

int comp = 0; // 비교연산카운터변수

vector<int> indexBF;

int brutesearch(char* p, char* a)

{

	int  k, s = 0;
	int i = 0;
	int j = 0;
	int M = strlen(p), N = strlen(a);//M - pattern , N - String

	cout << a << "\n";

	while (i != N && j != M)

	{

		comp++;

		if (a[i] != p[j])//패턴과 문자열이 맞지 않는경우

		{

			i = i - j + 1; // Text 는한칸씩이동한다

			j = 0; // Pattern 은항상처음부터비교한다

		}
		else {
			i++;
			j++;
		}
		if (j == M) {
			cout << "1" << endl;
			indexBF.push_back(i - M); j = -1;
		}


		//else return i;
	}

	cout << endl;

	for (int z = 0; z < indexBF.size(); z++) {
		cout << indexBF[z] << " ";
	}
	return 0;
}



const int q = 33554393; // 해시함수에의해결정되는값, 통상소수를선택함

const int d = 21; // 알파벳크기



int index(char c)
{
	return toupper(c) - 'A';
}



int rksearch(char* p, char* a)

{
	int i, dM = 1, h1 = 0, h2 = 0;

	int M = strlen(p), N = strlen(a);

	for (i = 1; i < M; i++) dM = (d * dM) % q;

	for (i = 0; i < M; i++)
	{
		h1 = (h1 * d + index(p[i])) % q; // Pattern의Hash value

		h2 = (h2 * d + index(a[i])) % q; // Text의Hash value
	}

	for (i = 0; h1 != h2; i++) // Hash value가같지않다면비교한다.

	{

		comp++;

		h2 = (h1 + d * q - index(a[i]) * dM) % q;

		h2 = (h2 * d + index(a[i + M])) % q;

		if (i > N - M) return N;

	}

	return i;

}





void result(int index)

{

	cout << "Comparison : " << comp << "\n";

	cout << "indexPattern : " << index << "\n\n\n";

	comp = 0;

}





void main()

{

	char Text1[] = "A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN STING";

	char Pattern1[] = "STING";





	int indexPattern = brutesearch(Pattern1, Text1);

	result(indexPattern);





	cout << "--------------------RK---------------------" << endl;

	indexPattern = rksearch(Pattern1, Text1);

	result(indexPattern);




}


