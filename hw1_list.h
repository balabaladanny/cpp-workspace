#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<iostream>

using namespace std;

class Node {
public:
    Node();
    ~Node();
    int data;
    Node *next;
};

class List
{
private:
    Node* head;
    Node* curr;
    Node* temp;
public:
    List();
    ~List();
    void AddNode(int addData);
    void MoveNode(int a,int b,List *NextPlayer);
    void print();
    int Joker;
};

#endif