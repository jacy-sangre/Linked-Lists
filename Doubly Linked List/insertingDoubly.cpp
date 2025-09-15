#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* prev;
    Node* next;
};

int main(){

    Node* head = nullptr,*tail = nullptr;
    int size, n, pos;

    cout << "Enter the size of the list: ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> n;

        Node* newNode = new Node{n, nullptr, nullptr};
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    cout << "Head to Tail: ";
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Enter data to insert: ";
    cin >> n;
    cout << "Enter position to enter data (1-indexed): ";
    cin >> pos;

    Node* newNode = new Node{n, nullptr, nullptr};

    if(pos == 1){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }else{
        temp = head;
        for(int i = 1; i < pos-1 && temp != nullptr; i++){
            temp = temp->next;
        }

        if(temp){
            Node* replace = temp->next;
            newNode->next = replace;
            temp->next = newNode;
            if(!replace) tail = newNode;
            else replace->prev = newNode;
            newNode->prev = temp;
        }
    }

    cout << "Head to Tail: ";
    temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Tail to Head: ";
    temp = tail;
    while(temp){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;



    

}