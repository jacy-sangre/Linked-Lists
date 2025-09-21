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

    int remove(int n){
        if(size == 0) return -1;

        Node* curr = head;
        int i = 1;
        while(curr){
            if(curr->val == n){
                if(head == curr){
                    removeFirst();
                }else if(tail == curr){
                    removeLast();
                }else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    size--;
                }
                return i;
            }else{
                curr = curr->next;;
            }
            i++;
        }

        return -1;
    }
    int removeAll(int n){
        if(size == 0) return -1;

        Node* curr = head;
        int count = 0;
        while(curr){
            if(curr->val == n){
                Node* toDelete = curr;
                count++;
                if(head == curr){
                    head = head->next;
                    if(head) head->prev = nullptr;
                    else tail = nullptr;
                }else{
                    curr->prev->next = curr->next;
                    if(!curr->next) tail = curr->prev;
                    else curr->next->prev = curr->prev;
                    
                }
                curr = curr->next;
                delete toDelete;
                size--;
            }else{
                curr = curr->next;;
            }  
        }

        return count;
    }

    void addAt(int n, int pos){
        if(size == 0){
            addHead(n);
            return;
        }

        if(pos < 1 || pos > size+1) return;

        Node* newNode = new Node{n, nullptr, nullptr};

        if(pos == 1){
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }else{
            Node* temp = head;
            for(int i = 1; i < pos-1 && temp != nullptr; i++){
                temp = temp->next;
            }

            if(temp){
                newNode->next = temp->next;
                newNode->prev = temp;
                
                if(!temp->next) tail = newNode;
                else temp->next->prev = newNode;
                            
                temp->next = newNode;
            }
        }
        size++;
    }
    
    int removeAt(int pos){

        if(size == 0 || pos < 1 || pos > size) return -1;

        int val;
        if(pos == 1){
            val = head->val;
            Node* toDelete = head;
            head = head->next;
            if(!head) tail = nullptr;
            else head->prev = nullptr;
            delete toDelete;
        }else{
            Node* temp = head;
            for(int i = 1; i < pos && temp; i++){
                temp = temp->next;
            }

            if(temp){
                val = temp->val;
                temp->prev->next = temp->next;
                if(!tail->next) tail = temp->prev;
                else temp->next->prev = temp->prev;
        
                delete temp;
            }
        }
        size--;

        return val;
    }

    void reverse(){

        Node* curr = head;
        Node* prev = nullptr;
        tail = curr;

        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

};
