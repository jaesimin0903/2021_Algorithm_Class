#include<iostream>

using namespace std;



typedef struct node* itemType; // node ����ü ����



void traverse(struct node* t); // inorder traverse �Լ� ����

void visit(struct node* t); // ��� �Լ�





class Stack // Ʈ�� �ڷ��� ������ ���� ���� Class

{

private:

	itemType* stack;

	int p;



public:



	Stack(int max = 100) // Stack Class�� ������

	{
		stack = new itemType[max]; p = 0;
	}



	~Stack() // Stack Class�� �Ҹ���

	{
		delete stack;
	}



	inline void push(itemType v) // ���ÿ� Data�� Push �Ѵ�

	{
		stack[p++] = v;
	}



	inline itemType pop() // ���� �ֱٿ� Push�� Data�� Pup�Ѵ�.

	{
		return stack[--p];
	}



	inline int empty() // ������ empty üũ

	{
		return !p;
	}



};



struct node // node ����ü �Լ� (Data�� ����� info��, Ʈ���� left, right ���)

{

	char info; struct node* l, * r;

}; struct node* x, * z;

void traverse(struct node* t)

{

	if (t != z) // z���� ���Ͽ� ������� ������ Ȯ���Ѵ�

	{

		traverse(t->l); // left��带 �ٽ� taverse() ���ȣ���Ѵ�.

		visit(t); // ����� ���Ͽ� visit() �Լ� ȣ��

		traverse(t->r); // right��带 �ٽ� taverse() ���ȣ���Ѵ�.

	}

}

void visit(struct node* t)

{

	cout << t->info << " ";// ���޹��� ����� ��(info)�� ���

}




void main()

{

	char c; // Data�� �Էµ� ������ ���� ����



	Stack stack(50); // Stack Class ����



	z = new node; // x��� ��½� ������� ���� �����ľ��� ���� z��� ����

	z->l = z;

	z->r = z;



	while ((c = cin.get()) != '\n') // ������� ����(next line)Ű�� �ԷµǱ� ������

		//�ݺ��� ����

	{

	while (c == ' ') cin.get(c); // ����(�����̽�)���� ����input�� ����



	x = new node; // ���ÿ� ����� x ��� ����

	x->info = c; // x��忡 �Էµ� ���� �ִ´�

	x->l = z; // ������� ���� Ȯ�θ� ���Ͽ� z��带 ����Ű�� �Ѵ�

	x->r = z; // ������� ���� Ȯ�θ� ���Ͽ� z��带 ����Ű�� �Ѵ�



	if (c == '+' || c == '*') // ��+��,��*���������� ��� ���ÿ� ����� ���� ����

	{
	 //�����ʰ�, ���ʳ�忡 ��ġ ��Ų��(Ʈ��)

  x->r = stack.pop();

  x->l = stack.pop();

  }

  stack.push(x); // ���ÿ� x��带 push�Ѵ�.

	}

	traverse(x); // ���ÿ� ������ �Ϸ�� x��� Ʈ���� traverse�Լ��� ������

}



