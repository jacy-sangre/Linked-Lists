#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main(){

    List *list = new Linkedlist();
    char op;
    int n, pos;

    do{
        cout << "OP: ";
        cin >> op;

        switch(op){
            case 'a':
                cin >> n;
                list->add(n);
                break;
            case 'p':
                list->print();
                break;
            case 'h':
                cin >> n;
                list->addHead(n);
                break;
            case 't':
                cin >> n;
                list->addTail(n);
                break;
            case 'g':
                cin >> n;
                if(list->getPosition(n) == -1){
                    cout << "Element not found" << endl;
                }else{
                    cout << "Element is in position " << list->getPosition(n) << endl;
                }
                break;
            case 'r':
                cin >> n;
                if(list->remove(n)){
                    cout << "Succesfully removed!" << endl;
                }else{
                    cout << "Element not found in list" << endl;
                }
                break;
            case 'A':
                cin >> n;
                cin >> pos;
                if(list->addAt(n, pos)){
                    cout << "Succesfully added!" << endl;
                }
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
            
        }
    }while(op != 'x');
}