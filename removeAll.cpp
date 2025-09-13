#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};

int main(){

    Node *head = nullptr, *tail = nullptr;
    int size, n, pos;

    cout << "Enter the size of the list: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> n;

        Node* newNode = new Node{n, nullptr};
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }

    cout << "Enter the numbers to delete: "; 
    cin >> n;
    int flag = 0;

    Node* curr = head;
    Node* prev = nullptr;

    while(curr){
        if(curr->val == n){
            Node* toDelete = curr;
            if(head == curr){
                head = head->next; 
                if(head == nullptr) tail = nullptr;        
            }else{
                prev->next = curr->next;
                if(tail == curr) tail = prev;       
            }
            curr = curr->next;
            delete toDelete;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }  
    
    

    cout << "Linked list: ";
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


}