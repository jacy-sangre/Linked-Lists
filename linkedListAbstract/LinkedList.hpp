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

    int remove(int n){

        if(!head) return 0;

        Node* prev = nullptr;
        Node* curr = head;

        while(curr){
            if(curr->val == n){
                Node *toDelete = curr;
                if(head == curr){
                    head = head->next;
                }
            }
        }
        
    }

    int addAt(int n, int pos){

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
            return 0;
        }

        return 1;
    }


};