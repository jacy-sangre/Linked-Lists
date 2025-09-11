#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){

    //Must take note where the first node and the last node is
    Node* head = nullptr; // first item in the list
    Node* tail = nullptr; // last item in the list

    for(int i = 0; i < 5; i++){

        int val;
        cout << "Enter data: ";
        cin >> val;

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        // if the list in empty
        if(head == nullptr){
            head = newNode; 
            tail = newNode;
        }else{ // connect to the newNode and make the tail point to the newNode
            tail->next = newNode;
            tail = newNode; // or can be tail->next;
        }
    }
    
     //Print the List
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //Delete whole list
    temp = head;
    while(temp != nullptr){
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}