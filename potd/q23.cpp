#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    node * temp = head;
    int count = 0;
    while(temp != NULL){
        cout << "Node " << count << ": " << temp ->val << endl;
        count++;
        temp = temp->next;
    }
}

int main(){
    node * head = NULL;
    for(int i = 0; i < 5; i++){
        node * newNode = new node;
        newNode->val = i;
        if(head == NULL){
            head = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    // shoud print 4 3 2 1 0
    printList(head);
    return 0;
}
