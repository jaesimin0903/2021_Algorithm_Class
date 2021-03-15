#include<iostream>
using namespace std;
typedef struct node* itemType;

class Stack
{
private:
	itemType* stack;
	int p;
public:
	Stack(int max = 100)
	{
		stack = new itemType[max]; p = 0;
	}
	~Stack()
	{
		delete stack;
	}
	inline void push(itemType v)
	{
		stack[p++] = v;
	}
	inline itemType pop()
	{
		return stack[--p];
	}
	inline int empty()
	{
		return !p;
	}
};

class Queue
{
private:
	itemType* queue;
	int head;
	int tail;
	int size;
	
public:
	Queue(int max = 100)
	{
		size = max;
		queue = new itemType[size];
		head = 0;
		tail = 0;
		
	} ~Queue()
	{
		delete queue;
	}
	void put(itemType v)
	{
		queue[tail++] = v;
		if (tail > size) tail = 0;
	}
	itemType get()
	{
		itemType t = queue[head++];
		if (head > size) head = 0;
		return t;
	}
	int empty()
	{
		return head == tail;
	}
};

struct node
{
	char info; struct node* l, * r;
};
struct node* x, * z;

void visit(struct node* t)
{
}
void levelOrderTraverse(struct node* t, char c)
{
	int level = 1;
	char a;
	Queue queue(50);
	queue.put(t);
	
	while (!queue.empty()) {
		t = queue.get();
		if (t->info == '+' || t->info == '-' || t->info == '*') level++;
		if (t->r->info == '+' || t->r->info == '-' || t->r->info == '*')
			if (t->l->info == '+' || t->l->info == '-' || t->l->info == '*')
				level--;
		if (t->info != c) {
			if (t->l != z) {
				queue.put(t->l);
			}
			if (t->r != z) {
				queue.put(t->r);
			}
		}
		else if (t->info == c) {
			cout << level;
			break;
		}
	}
	if (t->info != c) {
		cout << "not found";
	}	
}

void main()
{
	char c;
	Stack stack(50); 
	int level = 0;
	z = new node;
	z->l = z;
	z->r = z;
	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c);
		x = new node;
		x->info = c;
		x->l = z;
		x->r = z;
		if (c == '+' || c == '*' || c == '-')
		{
			x->r = stack.pop();
			x->l = stack.pop();
		}
		stack.push(x);
	}
	char findIndex;
	cout << endl;
	cin >> findIndex;
	char findIndexUpper = toupper(findIndex);
	levelOrderTraverse(x, findIndexUpper);
}






