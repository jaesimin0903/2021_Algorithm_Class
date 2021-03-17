#include <iostream>
using namespace std;
typedef int itemType;

class Stack2
{
public:
    Stack2() {
        head = new node;
        head->key;
        head->next;
        z = head;
    }
    ~Stack2() {
        delete head;
    }
    void push(itemType v) {
        node *node1 = new node;
        node1->key = v;
        node1->next = z;
        z = node1;
    };
    itemType pop() {
        
        int k;
        k = z->key;
        z = z->next;
        return k;
    };
    int empty() {
        z->key = head->key;
        z->next = head->next;
    };

private:
    struct node
    {
        itemType key; struct node* next;
    };
    struct node* head, * z;
};

int main() {
    char c; Stack2 acc; int a; int b;int x;

    while ((c = cin.get()) != '\n')
    {
        a = 0;
        b = 0;
        x = 0;
        while (c == ' ') cin.get(c);
        if (c == '+') x = acc.pop() + acc.pop();
        if (c == '-') x = -acc.pop() + acc.pop();
        if (c == '*') x = acc.pop() * acc.pop();
        if (c == '/') {
            a = acc.pop();
            b = acc.pop();
            if (a > b) {
                x = a / b;
            }
            else {
                x = b / a;
            }
        }
        while (c >= '0' && c <= '9')
        {
            x = 10 * x + (c - '0');  cin.get(c);
        }
        acc.push(x);
    }
    cout << acc.pop() << '\n';
}