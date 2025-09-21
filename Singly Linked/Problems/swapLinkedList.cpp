#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};

int main(){

    int size, n;
    Node *head = nullptr, *tail = nullptr;

    cout << "Enter size of array: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> n;

        Node* newNode = new Node{n, nullptr};
        if(!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }

    cout << "Original Linked list: ";
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    
    Node* curr = head;
    Node* prev = nullptr;

    //Swap
    while(curr && curr->next){
        Node* firstNextPair = curr->next->next;
        Node* second = curr->next;

        curr->next = firstNextPair;
        second->next = curr;

        if(!prev) head = second;
        else prev->next = second;

        prev = curr;
        curr = curr->next;

    }

    cout << "Updated Linked list: ";
    temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


}