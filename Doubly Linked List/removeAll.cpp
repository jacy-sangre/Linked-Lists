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


    cout << "Enter number/s to delete: ";
    cin >> n;;

    Node *curr = head;
    while(curr){
        if(curr->val == n){
            Node* toDelete = curr;
            if(head == curr){
                head = head->next;
                if(head) head->prev = nullptr;
                else tail = nullptr;
            }else{
                curr->prev->next = curr->next;
                if(!curr->next) tail = curr->prev;
                else curr->next->prev = curr->prev;       
            }
            curr = curr->next;
            delete toDelete;
        }else{
            curr = curr->next;  
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