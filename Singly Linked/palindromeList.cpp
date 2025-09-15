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
    
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* prev = nullptr;
    Node* curr = slow->next;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    int flag = 1;
    Node* left = head;
    Node* right = prev;
    while(right){
        if(left->val != right->val){
            flag = 0;
            break;
            
        }
        left = left->next;
        right = right->next;
    }
    
    if(flag){
        cout << "The linked list is a palindrome." << endl;
    }else{
        cout << "The linked list is not a palindrome." << endl;
    }
    
}