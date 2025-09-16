#include <iostream>
#include "node.hpp"
#include "list.hpp"

using namespace std;

class Linkedlist : public Lists{

    Node* head, *tail;
    int size = 0;

    public:
    Linkedlist(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print(){

        if(size == 0){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;

        temp = tail;
    
        while(temp){
            cout << "<- " << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;

    }

    void addHead(int n){
        Node* newNode = new Node{n, nullptr, nullptr};
        if(!head){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        
    }

    void addTail(int n){
        Node* newNode = new Node{n, nullptr, nullptr};
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int removeFirst(){
        if(size == 0) return -1;

        int val = head->val;
        Node* toDelete = head;
        head = head->next;

        if(!head) tail = nullptr; 
        else head->prev = nullptr;
    
        delete toDelete;
        size--;
        return val;
 
    }

    int removeLast(){
        if(size == 0) return -1;
        int val = tail->val;
        Node* toDelete = tail;
        tail = tail->prev;
        
        if(!tail) head = nullptr; 
        else tail->next = nullptr;

        delete toDelete;
        size--;
        return val;
    }

};
