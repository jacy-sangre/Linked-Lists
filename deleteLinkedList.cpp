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

        // Short way
        Node* newNode = new Node{n, nullptr};
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }

    cout << "Enter position to delete: "; 
    cin >> pos;
   
    // If the node in the front must be deleted
    if(pos == 1){ 
        Node *nodeToDelete = head; // take note of the nodeToDelete or the head
        head = head->next; // make the nextNode the head
        delete nodeToDelete;
    }else{
        Node* temp = head;
        for(int i = 1; i < pos-1 && temp != nullptr; i++){ // Get position
            temp = temp->next;
        }

        if(temp){
            Node *nodeToDelete = temp->next; // take note of the nodeToDelete
            temp->next = temp->next->next; // connect the node before the nodeToDelete to the next node of nodeToDelete
            delete nodeToDelete; 
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