#include <iostream>

#include<stdio.h>

#include<stdlib.h>

using namespace std;



#define MAX 1500

typedef int itemType;

int data_swap = 0;

int comparision = 0;



void insertion(itemType a[], int N) // 삽입 정렬

{

	int i, j;

	itemType v;

	for (i = 2; i <= N; i++) {

		comparision++; // 비교연산 카운터 증가

		v = a[i]; //현재 삽입될 숫자를 v변수로 복사

		j = i;

		while (a[j - 1] > v) { // 이전배열의 값이 키 값보다 크면

			data_swap++; // 자료이동 카운터 증가

			a[j] = a[j - 1]; // 데이터 이동

			j--; // j 감소

		}

		a[j] = v;

	}

};



void result() // 결과 출력 함수

{

	cout << "\n비교연산 회수는 " << comparision << "번 수행 되었습니다.\n";

	cout << "자료이동 회수는 " << data_swap << "번 수행 되었습니다.\n\n";



	comparision = 0; // 비교연산 카운터 변수 초기화

	data_swap = 0; // 자료이동 카운터 변수 초기화

}

void main()

{

	// 삽입,쉘 정렬에 사용되는 배열

	itemType a[MAX + 1];

	a[0] = -1; // 첫번째 배열에 더미값 초기화



	int j = 1; // Worst Case 배열을 위한 변수





	printf("\nInserttion Sort : %d개의 양의정수 Case 비교\n\n", MAX);





	//////////////// Best Case array & Result //////////////////

	for (int i = 1; i <= MAX; i++) a[i] = i;

	printf("--------------------------------------------------");

	insertion(a, MAX);

	cout << "\n--- Best Case ---";

	result();

	////////////////////////////////////////////////////////////





	//////////////// Worst Case array & Result /////////////////

	for (int i = MAX; i >= 1; i--) {

		a[j] = i;

		j++;

	}

	printf("--------------------------------------------------");

	insertion(a, MAX);

	cout << "\n--- Worst Case ---";

	result();

	////////////////////////////////////////////////////////////





	//////////////// Random Case array & Result ////////////////

	for (int i = 1; i <= MAX; i++)a[i] = rand() % MAX + 1;

	printf("--------------------------------------------------");

	insertion(a, MAX);

	cout << "\n--- Random Case ---";

	result();

	////////////////////////////////////////////////////////////



	printf("--------------------------------------------------\n\n");

}



