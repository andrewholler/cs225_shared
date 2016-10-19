#include <iostream>
using namespace std;

class Stack{
    private:
        struct node{
            int val;
            node * next;
        };
        node * head;
        int size;
    public:
        Stack();
        ~Stack();
        int getSize();
        bool isEmpty();
        void push(int value);
        int pop();
        void print();
};

Stack::Stack(){
    head = NULL;
    size = 0;
}

Stack::~Stack(){
    while(head){
        node * temp = head;
        cout << "deleting " << temp->val << endl;
        head = head->next;
        delete temp;
        temp = head;
    }
}

int Stack::getSize(){return size;}

bool Stack::isEmpty(){return ((size == 0) ? true : false);}

void Stack::push(int value){
    node * temp = new node;
    temp->val = value;
    temp->next = head;
    head = temp;
    size++;
}

int Stack::pop(){
    if(size == 0)
        return -1;
    node * temp = head;
    head = head->next;
    int ret = temp->val;
    delete temp;
    size--;
    return ret;
}

void Stack::print(){
    node * temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main(){
    Stack a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}
