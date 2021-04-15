#include <iostream>

#include<stdlib.h>
#include<iomanip>
using namespace std;





#define infoNIL 0 // 더미노드이자 마지막 노드인 z의 값

#define itemMIN -1 // Binary search tree의 head 값, // head의 오른쪽부터 노드가 오게하기 위하여



// Red Black Tree tag

#define black 0

#define red 1



typedef int itemType;

typedef double infoType;



double comparision = 0.0;

double build = 0.0;

double rbtbuild = 0.0;

////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// RB Tree Class /////////////////////////////////////



class RBtree

{

private:



	struct node

	{

		itemType key, tag;

		infoType info;

		struct node* l, * r;

		// 구조체초기화

		node(itemType k, infoType i, itemType t, struct node* ll, struct node* rr)

		{
			key = k; info = i; tag = t; l = ll; r = rr;
		}

	};

	struct node* head, * tail, * x, * p, * g, * gg, * z;



public:



	RBtree(int max)

	{

		z = new node(0, infoNIL, black, 0, 0);

		z->l = z;

		z->r = z;

		head = new node(itemMIN, 0, black, z, z);

	}



	~RBtree()

	{

		delete head;

		delete z;

		delete x;

	}



	infoType RBTsearch(itemType v);

	void RBTinsert(itemType v, infoType info);

	void split(itemType k);



	// rotate 함수, class밖으로 꺼내 보았으나 에러발생

	// 에러를 잡지못해 class 안에 구현하였습니다.

	struct node* rotate(itemType k, node* y)

	{

		struct node* high, * low;

		high = (k < y->key) ? y->l : y->r;



		if (k < high->key)

		{

			low = high->l;

			high->l = low->r;

			low->r = high;

		}

		else

		{

			low = high->r;

			high->r = low->l;

			low->l = high;

		}



		if (k < y->key) y->l = low;

		else y->r = low;



		return low;

	}



};



// Red Black Tree는물리적으로Binary Search Tree와같으므로

// 똑같은Search 함수를사용한다.

infoType RBtree::RBTsearch(itemType v)

{

	struct node* x = head->r;

	z->key = v;



	while (v != x->key) {

		comparision++;

		x = (v < x->key) ? x->l : x->r;

	}

	return x->info;

}



// Red Black 형태를유지하기위해insert 하며split한다.

void RBtree::RBTinsert(itemType k, infoType info)

{

	x = head; p = head; g = head;



	while (x != z) // 전달받은키값이들어갈노드의위치를탐색한다

	{
		rbtbuild++;

		gg = g; g = p; p = x;

		x = (k < x->key) ? x->l : x->r;

		if (x->l->tag && x->r->tag) split(k);

	}



	x = new node(k, info, 1, z, z); // 위치를탐색한x에새로운노드를생성한다



	// 부모노드인p와비교하여l,r 를결정한다.

	if (k < p->key) p->l = x;

	else p->r = x;

	split(k);

	head->r->tag = black;

}



// split과rotate를통해Red Black 트리형태를구현한다.

void RBtree::split(itemType k)

{

	x->tag = red;

	x->l->tag = black;

	x->r->tag = black;



	if (p->tag)

	{

		g->tag = red;

		if (k < g->key != k < p->key) p = rotate(k, g);

		x = rotate(k, gg);

		x->tag = black;

	}

}





////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// BS Tree Class /////////////////////////////////////



// Binary Search Tree 는 6번실습에서 구현 하였으므로 주석 생량합니다.

class BStree

{

private:



	struct node

	{

		itemType key;

		infoType info;

		struct node* l, * r;

		node(itemType k, infoType i, struct node* ll, struct node* rr)

		{
			key = k; info = i; l = ll; r = rr;
		}

	};

	struct node* head, * z;



public:

	BStree(int max)

	{

		z = new node(0, infoNIL, 0, 0);

		head = new node(itemMIN, 0, z, z);

	}



	~BStree()

	{

		delete(z);

		delete(head);

	}



	infoType BSTsearch(itemType v);

	void BSTinsert(itemType v, infoType info);



	void BSTInorderTraverse(BStree* t2, RBtree* t3);

	void BSTInorderTraverse(node* t, BStree* t2, RBtree* t3);



};



infoType BStree::BSTsearch(itemType v)

{

	struct node* x = head->r;

	z->key = v;



	while (v != x->key) {

		comparision++;

		x = (v < x->key) ? x->l : x->r;

	}

	return x->info;

}



void BStree::BSTinsert(itemType v, infoType info)

{

	struct node* p, * x;

	p = head;

	x = head->r;



	while (x != z)

	{
		build++;

		p = x;

		x = (v < x->key) ? x->l : x->r;

	}



	x = new node(v, info, z, z);

	if (v < p->key) p->l = x;

	else p->r = x;

}



// Overloarding 을통해BStree T1을InorderTraverse하며

// T2, 그리고RBtree Class의T3를구현한다.

void BStree::BSTInorderTraverse(BStree* t2, RBtree* t3)

{

	BSTInorderTraverse(head->r, t2, t3);

}



void BStree::BSTInorderTraverse(node* t, BStree* t2, RBtree* t3)

{

	if (t != z)

	{

		BSTInorderTraverse(t->l, t2, t3);

		t2->BSTinsert(t->key, t->key); // T2 생성

		t3->RBTinsert(t->key, t->key); // T3 생성

		BSTInorderTraverse(t->r, t2, t3);

	}

}


void swap(int arr[], int r1, int r2) {
	int temp;
	temp = arr[r1];
	arr[r1] = arr[r2];
	arr[r2] = temp;
}


void result(int A, double N) // 결과출력함수

{



	cout << "T" << A << " 평균비교연산회수는: " << double(comparision / N) << "\n";



	comparision = 0.0; // T1의비교연산회수출력후초기화

}
void buildResult(int A, double N) // 결과출력함수

{

	if (rbtbuild == 0)
		cout << "T" << A << " 평균구축비교회수는: " << double(build / N) << "\n";
	else {
		cout << "T" << A << " 평균구축비교회수는: " << double(build / N) << "\n";
		cout << "T" << A + 1 << " 평균구축비교회수는: " << double(rbtbuild / N) << "\n";
	}


	build = 0.0; // T1의비교연산회수출력후초기화
	rbtbuild = 0.0;
}




void main()

{
	int i;
	int N;
	int r1;
	cin >> N;
	BStree T1(N), T2(N);
	RBtree T3(N);

	int* a = new int[N];

	itemType info = 0;

	for (i = 0;i < N; i++) {
		a[i] = i + 1;
	}
	for (i = 0; i < N; i++) {
		r1 = 1 + (rand() % N) + 1;
		swap(a, i, r1);
	}

	for (i = 0;i < N;i++) {
		T1.BSTinsert(a[i], info);
		info++;
	}
	cout << endl << endl;

	buildResult(1, N);



	for (i = 0; i < N; i++) T1.BSTsearch(a[i]);

	T1.BSTInorderTraverse(&T2, &T3);
	buildResult(2, N);

	cout << endl;
	result(1, N);

	for (int i = 0; i < N; i++) T2.BSTsearch(a[i]);

	result(2, N);

	for (int i = 0; i < N; i++) T3.RBTsearch(a[i]);
	result(3, N);
}



