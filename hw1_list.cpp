#include<iostream>

#include "hw1_list.h"
using namespace std;

Node::Node(){}

Node::~Node(){}

List::List(){
    head = NULL;
    curr = NULL;
    Joker = 0;
    temp = NULL;
}
List::~List(){}

void List::AddNode(int addData){
    if(addData==0)
        head->next->data = 0;
    else {
        Node* n = new Node;
        n->next = NULL;
        head = new Node;
        head->data = -1;
        n->data = 1;
        head->next = n;
        curr = head->next;
        for(int i=2;i<=addData;i++){
            Node* n = new Node;
            n->data = i;
            n->next = NULL;
            curr->next = n;
            curr = curr->next; 
        }
    }
}

void List::MoveNode(int a,int b,List *NextPlayer){
    curr = head;
    NextPlayer->curr = NextPlayer->head;
    a = a-1; // move to the prev of the target node
    while(NextPlayer->curr->next->next && a--) NextPlayer->curr = NextPlayer->curr->next;
    NextPlayer->temp = NextPlayer->curr->next->next;
    b = b-1;
    while(curr->next && b--) curr = curr->next;
    temp = curr->next;
    if(NextPlayer->curr->next->data==0){
        NextPlayer->Joker--;
        Joker++;
    }
    curr->next = NextPlayer->curr->next;
    curr->next->next = temp;
    NextPlayer->curr->next = NextPlayer->temp;
}

void List::print(){
    curr = head->next;
    if(curr) {
        cout<<curr->data;
        curr = curr->next;
    }
    while(curr){
        cout<<" "<<curr->data;
        curr = curr->next;
    }
    cout<<"\n";
}