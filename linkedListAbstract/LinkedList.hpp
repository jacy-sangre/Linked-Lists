#include <iostream>

#include "List.hpp"
#include "node.hpp"

using namespace std;

class Linkedlist : public List{

    

    int size = 0;
    Node* head;
    Node* tail;

    public:
    Linkedlist(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print(){
        Node *temp = head;
        while(temp){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void add(int n){
         
        Node *newNode = new Node{n, nullptr};
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
        size++;
    }

    void addHead(int n){
         
        Node *newNode = new Node{n, nullptr};
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addTail(int n){
        Node *newNode = new Node{n, nullptr};
        tail = tail->next = newNode;
        size++;
    }

    int getPosition(int n){
        Node *temp = head;
        for(int i = 0; temp != nullptr && i < size; i++){
            if(temp->val == n){
                return i+1;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(int n){

        
        if(head->val == n && head){
            Node* temp = head;
            head = head->next;
            if(!head) tail = nullptr;
            delete temp;
            size--;
            return;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        while(curr){
            if(curr->val == n){
                prev->next = curr->next;
                if(curr == tail) tail = prev;
                delete curr;
                size--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        
    }

    void addAt(int n, int pos){

        Node* newNode = new Node{n, nullptr};

        if(pos <= size+1){
            if(pos == 1){
                newNode->next = head; 
                head = newNode;
            }else if(pos == size+1){
                tail = tail->next = newNode;
            }else{
                Node *temp = head;
                for(int i = 1; i < pos-1 && temp != nullptr; i++){
                    temp = temp->next;
                }

                if(temp){
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }else{
            cout << "Invalid Position" << endl;
            return;
        }
    }


};