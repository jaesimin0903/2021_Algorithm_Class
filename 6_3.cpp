#include <iostream>

#include<stdlib.h>

using namespace std;



#define MAX 150

#define infoLILk 0 // 더미노드 이자 마지막 노드인 z의값

#define itemMIN -1 // Binary search tree의 head 값,





typedef int itemType;

typedef double infoType;



int comparision = 0;

void swap(int arr[], int a, int b) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

class BST

{

private:

	struct node

	{

		itemType key;

		infoType info;

		struct node* l, * r;

		// 구조체 초기화를 위해

		node(itemType k, infoType i, struct node* ll, struct node* rr)

		{
			key = k; info = i; l = ll; r = rr;
		}

	};

	struct node* head, * z;



public:

	BST(int max)

	{

		z = new node(0, infoLILk, 0, 0);

		head = new node(itemMIN, 0, z, z);

	}



	~BST()

	{

		delete(z);

		delete(head);

	}



	infoType BSTsearch(itemType v);

	void BSTinsert(itemType v, infoType info);

	void BSTdelete(itemType v);
	void BSTInorderTraverse(BST* t2);
	void BSTInorderTraverse(node* t, BST* t2);
	void BSTresult();



};



infoType BST::BSTsearch(itemType v) // Binary search tree 를 탐색하는 함수

{

	struct node* x = head->r;

	z->key = v;



	while (v != x->key) { // tree를 순회하며 v의 값을 탐색한다

		comparision++; // 비교연산회수 카운터 증가

		x = (v < x->key) ? x->l : x->r;

	}

	return x->info;

}


void BST::BSTinsert(itemType v, infoType info) // Binary search tree 를 구현하는 함수

{

	struct node* p, * x;

	p = head;

	x = head->r;



	while (x != z) // 전달받은 킷값이 들어갈 노드의 위치를 탐색한다

	{

		p = x;

		x = (v < x->key) ? x->l : x->r;


	}



	x = new node(v, info, z, z); // 위치를 탐색한 x에 새로운 노드를 생성한다

	if (v < p->key) p->l = x; // 부모 노드인 p와비교하여 l,r 위치를 결정한다.

	else p->r = x;

}

void BST::BSTdelete(itemType v) {
	struct node* x;
	struct node* p, * t, * c;

	p = head;
	x = head->r;
	while (x->key != v && x != z) {
		comparision++;
		p = x;
		x = (v < x->key) ? x->l : x->r;
	}
	if (x == z) {
		comparision++;return;
	}
	else {
		comparision++;t = x;
	}
	if (t->r == z) {
		comparision++;x = t->l;
	}
	else if (t->r->l == z) {
		comparision++;
		x = t->r; x->l = t->l;
	}
	else {
		comparision++;
		c = x->r; while (c->l->l != z) {
			comparision++; c = c->l;
		}
		x = c->l; c->l = x->r;
		x->l = t->l; x->r = t->r;
	}
	free(t);
	if (v < p->key) {
		comparision++;p->l = x;
	}
	else {
		comparision++;p->r = x;
	}
}
void BST::BSTInorderTraverse(BST* t2)

{

	BSTInorderTraverse(head->r, t2);

}



// 전달받은 노드와 class T2를 inorder traverse 하며 BSTinsert로 보내 tree T2를 생성한다.

void BST::BSTInorderTraverse(node* t, BST* t2)

{

	if (t != z)

	{

		BSTInorderTraverse(t->l, t2);

		t2->BSTinsert(t->key, t->key);

		BSTInorderTraverse(t->r, t2);

	}

}




void result(float N) // 결과출력함수

{

	//cout << " 총 비교연산회수는: " << comparision << "\n";

	cout << "평균비교연산회수: " << (comparision / N) << "\n\n";

}



void main()

{
	int N;
	cout << "N - ";
	cin >> N;
	BST T1(N);
	BST T2(N);

	int* a = new int[N];
	int* b = new int[N];

	itemType info = 0;



	int i;
	int r1 = 0;
	int ran = 0;
	int r2 = 0;
	int j = 0;



	for (int i = 0;i <= N;i++) {
		j = i + 1;
		a[i] = j;
	}

	for (int i = 0; i < N;i++) {
		r1 = 1 + rand() % N;
		ran = 1 + rand() % N;
		swap(a, i, r1);
	}

	for (i = 0; i < N; i++) {

		//cout << a[i] << " ";
		T1.BSTinsert(a[i], info++); // Rand() 함수를 통한 임의의 수 발생과 동시에 BSTinsert를 이용하여 Binary search tree 를 구현한다.

	}

	/*r2 = N-10 + rand() & N;

	T1.BSTdelete(a[r2]);*/
	for (i = 0; i < N; i++) T1.BSTsearch(a[i]);
	cout << "T1";
	result(N);

	T1.BSTInorderTraverse(&T2);

	for (i = 0; i < N; i++) T2.BSTsearch(a[i]); // Binary search tree 에 입력된 모든 자료를 탐색한다



	cout << "T3";
	result(N); // 총 비교회수와, 평균 비교회수를 출력한다.




}



