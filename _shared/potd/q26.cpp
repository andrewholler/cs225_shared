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

void insertSorted(node ** head, node * insert){
    node * temp = *head;
    if(temp == NULL){
        *head = insert;
        insert->next = NULL;
        return;
    }
    if(temp->val >= insert->val){   // this node becomes the new head
        insert->next = temp;
        *head = insert;
    }
    else{
        node * prev = *head;
        temp = temp->next;
        while(temp != NULL){
            if(temp->val >= insert->val){
                insert->next = temp;
                prev->next = insert;
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
        // we reached the end of list, this node must go at the end
        // prev points to last node, temp points to NULL
        prev->next = insert;
        insert->next = NULL;
    }
}

void sortList(node ** head){
    node * newHead = NULL;
    node * curHead = *head;
    node * insert;
    while(curHead != NULL){
        insert = curHead;
        curHead = curHead->next;
        insert->next = NULL;
        insertSorted(&newHead, insert);
    }
    *head = newHead;
}

node * shuffle(node * a, node * b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    node * aptr = a;
    node * bptr = b;
    while(aptr->next != NULL && bptr->next != NULL){
        node * tempa = aptr;
        aptr = aptr->next;
        node * tempb = bptr;
        bptr = bptr->next;
        tempa->next = tempb;
        tempb->next = aptr;
    }
    if(aptr->next == NULL){ // tack on rest of b
        aptr->next = bptr;
    }
    else{   // bptr->next == NULL
        // add last b node to a list
        node * tempa = aptr;
        aptr = aptr->next;
        tempa->next = bptr;
        bptr->next = aptr;
    }
    return a;
}

int main(){
    node * head = NULL;
    node * n = new node;
    n->val = 4;
    n->next = NULL;
    head = n;
    
    n = new node;
    n->val = 2;
    n->next = head;
    head = n;

    n = new node;
    n->val = 0;
    n->next = head;
    head = n;

    node * a = NULL;
    n = new node;
    n->val = 5;
    n->next = NULL;
    a = n;
    
    n = new node;
    n->val = 3;
    n->next = a;
    a = n;

    n = new node;
    n->val = 1;
    n->next = a;
    a = n;

    //test shuffle
    node * shuffled = shuffle(head, a);
    printList(shuffled);

    return 0;
}
