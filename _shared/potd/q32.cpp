#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

node *createList(int arr[], int size){
    node * ret = new node;
    ret->val = arr[0];
    node * temp = ret;
    for(int i = 1; i < size; i ++){
        temp->next = new node;
        temp = temp->next;
        temp->val = arr[i];
    }
    temp->next = NULL;
    return ret;
}

void requeue(node **head, int times){
    if(times == 0)
        return;
    node * curhead = *head;
    node * tail = curhead;
    while(tail->next != NULL)
        tail = tail->next;
    if(curhead == tail)
        return;
    node * temp = curhead->next;
    node * prev = curhead;
    for(int i = 1; i < times; i++){     // move temp times times, ends up at new head
        if(temp == tail)
            temp = curhead;
        else
            temp = temp->next;
        if(prev == tail)
            prev = curhead;
        else
            prev = prev->next;
    }
    if(temp != curhead){
        *head = temp;
        prev->next = NULL;
        tail->next = curhead;
    }
}

int main(){
    int arr[1] = {1};
    node * n = createList(arr, 1);
    printList(n);
    requeue(&n, 5);
    cout << endl;
    printList(n);
    return 0;
}
