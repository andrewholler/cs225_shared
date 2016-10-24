#include <iostream>
using namespace std;

class Queue{
    private:
        struct node{
            int val;
            node * next;
        };
        node * head;
        node * tail;
        int size;
    public:
        Queue();
        ~Queue();
        int getSize();
        bool isEmpty();
        void push(int value);
        int pop();
        void print();
};

Queue::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

Queue::~Queue(){
    while(tail){
        node * temp = tail;
        cout << "deleting " << temp->val << endl;
        tail = tail->next;
        delete temp;
        temp = tail;
    }
}

int Queue::getSize(){return size;}

bool Queue::isEmpty(){return ((size == 0) ? true : false);}

void Queue::push(int value){
    if(head == NULL){
        head = new node;
        tail = head;
    }
    else{
        head->next = new node;
        head = head->next;
    }
    head->val = value;
    head->next = NULL;
    size++;
}

int Queue::pop(){
    if(size == 0)
        return -1;
    node * temp = tail;
    tail = tail->next;
    int ret = temp->val;
    delete temp;
    size--;
    if(size == 0){
        head = NULL;
        tail = NULL;
    }
    return ret;
}

void Queue::print(){
    node * temp = tail;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main(){
    Queue a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
    cout << "popped " << a.pop() << endl;
    a.pop();
    a.pop();
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}
