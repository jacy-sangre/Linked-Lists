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

    cout << "Enter the number to delete: "; 
    cin >> n;
    int flag = 0;

    if(head && head->val == n){
        Node* temp = head;
        head = head->next;
        delete temp;
        flag = 1;
    }else{
        Node* prev = head;
        Node* temp = head->next;
        while(temp){
            if(temp->val == n){
                prev->next = temp->next;
                if(temp == tail) tail = prev;
                delete temp;
                flag = 1;
            }
            prev = temp;
            temp = temp->next;
        }
    }
   

    if(flag){
        cout << "Number deleted!" << endl;
    }else{
        cout << "Number not in the list" << endl;
    }
        

    cout << "Linked list: ";
    Node* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;


}