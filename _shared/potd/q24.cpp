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

int main(){
    node * head = NULL;
    for(int i = 5; i > 0; i--){
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

    // test print
    // shoud print 1 2 3 4 5
    printList(head);
    cout << "---------------" << endl;

    // test insert sorted
    node * n = new node;
    n->val = 0;
    n->next = NULL;
    insertSorted(&head, n);
    // should print 0 1 2 3 4 5
    printList(head);
    cout << "---------------" << endl;

    n = new node;
    n->val = 7;
    n->next = NULL;
    insertSorted(&head, n);
    // should print 0 1 2 3 4 5 7
    printList(head);
    cout << "---------------" << endl;

    n = new node;
    n->val = 6;
    n->next = NULL;
    insertSorted(&head, n);
    // should print 0 1 2 3 4 5 6 7
    printList(head);
    cout << "---------------" << endl;

    return 0;
}
