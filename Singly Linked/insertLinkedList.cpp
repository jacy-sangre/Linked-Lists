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

    cout << "Enter position: "; 
    cin >> pos;
    cout << "Enter data to insert: ";
    cin >> n;

    Node* newNode = new Node{n};
    
    // If the node must be inserted on the front
    if(pos == 1){ 
        newNode->next = head;
        head = newNode;
    }else{
        Node* temp = head;
        for(int i = 1; i < pos-1 && temp != nullptr; i++){ // Get position
            temp = temp->next;
        }

        if(temp){
            newNode->next = temp->next;
            temp->next = newNode;
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