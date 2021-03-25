#include <iostream>

#include<stdio.h>

#include<stdlib.h>

using namespace std;



#define MAX 1500

typedef int itemType;

int data_swap = 0;

int comparision = 0;



void insertion(itemType a[], int N) // ���� ����

{

	int i, j;

	itemType v;

	for (i = 2; i <= N; i++) {

		comparision++; // �񱳿��� ī���� ����

		v = a[i]; //���� ���Ե� ���ڸ� v������ ����

		j = i;

		while (a[j - 1] > v) { // �����迭�� ���� Ű ������ ũ��

			data_swap++; // �ڷ��̵� ī���� ����

			a[j] = a[j - 1]; // ������ �̵�

			j--; // j ����

		}

		a[j] = v;

	}

};



void result() // ��� ��� �Լ�

{

	cout << "\n�񱳿��� ȸ���� " << comparision << "�� ���� �Ǿ����ϴ�.\n";

	cout << "�ڷ��̵� ȸ���� " << data_swap << "�� ���� �Ǿ����ϴ�.\n\n";



	comparision = 0; // �񱳿��� ī���� ���� �ʱ�ȭ

	data_swap = 0; // �ڷ��̵� ī���� ���� �ʱ�ȭ

}

void main()

{

	// ����,�� ���Ŀ� ���Ǵ� �迭

	itemType a[MAX + 1];

	a[0] = -1; // ù��° �迭�� ���̰� �ʱ�ȭ



	int j = 1; // Worst Case �迭�� ���� ����





	printf("\nInserttion Sort : %d���� �������� Case ��\n\n", MAX);





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



