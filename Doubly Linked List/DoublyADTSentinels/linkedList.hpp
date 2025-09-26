#include <iostream>
#include "node.hpp"
#include "list.hpp"

using namespace std;

class Linkedlist : public Lists{

    Node head, tail;
    int size = 0;

    Node* addBetween(int num, Node* pred, Node* succ){
        Node* newNode = new Node{num, nullptr, nullptr};
        newNode->next = succ;
        newNode->prev = pred;
        pred->next = newNode;
        succ->prev = newNode;
        size++;
        return newNode;
    }

    int removeNode(Node* n){
        int val = n->val;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        size--;

        return val;
    }

    public:
    Linkedlist(){
        head.next = &tail;
        tail.prev = &head;
        size = 0;
    }

    void print(){
        cout << "FROM HEAD: ";
        Node* temp = head.next;
        while(temp != &tail){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
        
        cout << "FROM TAIL: ";
        temp = tail.prev;
        while(temp != &head){
            cout << temp->val << " -> ";
            temp = temp->prev;
        }
        cout << endl;
    }
    
    void addHead(int n){
        addBetween(n, &head, head.next);
    }

    void addTail(int n){
        addBetween(n, tail.prev, &tail);
    }

    int removeFirst(){
        return (size == 0) ? -1 : removeNode(head.next);
    }
    int removeLast(){
        return (size == 0) ? -1 : removeNode(tail.prev);
    }
    
    int remove(int n){

        if(size == 0) return -1;

        Node* curr = head.next;
        int i = 1;
        while(curr != &tail){
            if(curr->val == n){
                if(head.next == curr){
                    removeFirst();
                }else{
                    removeNode(curr);
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

        Node* curr = head.next;
        int count = 0;
        while(curr != &tail){
            if(curr->val == n){
                Node* nextNode = curr->next;
                count++;
                if(head.next == curr){
                    removeFirst();
                }else{
                    removeNode(curr);
                }
                curr = nextNode;
            }else{
                curr = curr->next;;
            }  
        }

        return count;
    }

    void addAt(int n, int pos){
        if(pos < 1 || pos > size + 1){
            cout << "Invalid Position" << endl;
            return;
        }

        Node* curr = head.next;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        addBetween(n, curr->prev, curr);
    }

    void reverse(){
        if(size <= 1) return;

        Node* curr = head.next;
        Node* prev = &tail;
        tail.prev = curr;

        while(curr != &tail){
            Node* nextNode = curr->next;
            curr->next = prev;
            curr->prev = nextNode;
            prev = curr;
            curr = nextNode;
        }

        head.next = prev;
        prev->prev = &head;       
    }

    int removeAt(int pos){
        if(pos < 1 || pos > size) return -1;

        Node* curr = head.next;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        int val = curr->val;
        removeNode(curr);

        return val;
    }

    int get(int pos){
        if(pos < 1 || pos > size) return -1;
        
        Node* curr;
        if(pos <= (size+1)/2){
            curr = head.next;
            cout << "From the head" << endl;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }
            return curr->val;
        }else{
            curr = tail.prev;
            cout << "From the tail" << endl;
            for(int i = size; i > pos; i--){
                curr = curr->prev;
            }
            return curr->val;
        }
    }

};



   

