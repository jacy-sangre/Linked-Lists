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

    //Swap
    Node* prev = nullptr;
    Node* curr = head;

    while(curr && curr->next){

        Node* nextPair = curr->next->next; // take not of the element next to the pair
        Node* second = curr->next; // take note of the element next to the current

        // swap
        curr->next = nextPair; // link curr to the element next to the pair
        second->next = curr; // link the element next to curr to the curr so they swap

        if(prev){
            prev->next = second; // take note of the previous after iteration 1
        }else{
            head = second; // make the second the head since they have been swapped
        }

        prev = curr; // take not of teh previous curr to link the list properly
        curr = curr->next; //traverse
    }

    cout << "Updated Linked list: ";
    temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


}