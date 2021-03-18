#include<iostream>

using namespace std;



typedef struct node* itemType; // node 구조체 선언



void traverse(struct node* t); // inorder traverse 함수 선언

void visit(struct node* t); // 출력 함수





class Stack // 트리 자료의 저장을 위한 스택 Class

{

private:

	itemType* stack;

	int p;



public:



	Stack(int max = 100) // Stack Class의 생성자

	{
		stack = new itemType[max]; p = 0;
	}



	~Stack() // Stack Class의 소멸자

	{
		delete stack;
	}



	inline void push(itemType v) // 스택에 Data를 Push 한다

	{
		stack[p++] = v;
	}



	inline itemType pop() // 가장 최근에 Push된 Data를 Pup한다.

	{
		return stack[--p];
	}



	inline int empty() // 스택의 empty 체크

	{
		return !p;
	}



};



struct node // node 구조체 함수 (Data가 저장될 info와, 트리의 left, right 노드)

{

	char info; struct node* l, * r;

}; struct node* x, * z;

void traverse(struct node* t)

{

	if (t != z) // z노드와 비교하여 하위노드 유무를 확인한다

	{

		traverse(t->l); // left노드를 다시 taverse() 재귀호출한다.

		visit(t); // 출력을 위하여 visit() 함수 호출

		traverse(t->r); // right노드를 다시 taverse() 재귀호출한다.

	}

}

void visit(struct node* t)

{

	cout << t->info << " ";// 전달받은 노드의 값(info)을 출력

}




void main()

{

	char c; // Data가 입력된 문자형 변수 선언



	Stack stack(50); // Stack Class 선언



	z = new node; // x노드 출력시 하위노드 유무 상태파악을 위한 z노드 생성

	z->l = z;

	z->r = z;



	while ((c = cin.get()) != '\n') // 사용자의 엔터(next line)키가 입력되기 전까지

		//반복문 실행

	{

	while (c == ' ') cin.get(c); // 공백(스페이스)으로 다음input을 구분



	x = new node; // 스택에 저장될 x 노드 생성

	x->info = c; // x노드에 입력된 값을 넣는다

	x->l = z; // 하위노드 유무 확인를 위하여 z노드를 가르키게 한다

	x->r = z; // 하위노드 유무 확인를 위하여 z노드를 가르키게 한다



	if (c == '+' || c == '*') // ‘+’,‘*’연산자의 경우 스택에 저장된 값을 꺼내

	{
	 //오른쪽과, 왼쪽노드에 위치 시킨다(트리)

  x->r = stack.pop();

  x->l = stack.pop();

  }

  stack.push(x); // 스택에 x노드를 push한다.

	}

	traverse(x); // 스택에 저장이 완료된 x노드 트리를 traverse함수로 보낸다

}



