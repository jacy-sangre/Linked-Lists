#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

int main(){
    
    Node* head = nullptr, *tail = nullptr;
    int size, n;
    
    cout << "Enter size of linked list: ";
    cin >> size;
    
    for(int i = 0; i < size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> n;
        
        Node* newNode = new Node{n, nullptr};
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
        
    }
    
    cout << "Original list: ";
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    cout << "Reversed list: ";
    temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    } 
    cout << endl;
    

    
}