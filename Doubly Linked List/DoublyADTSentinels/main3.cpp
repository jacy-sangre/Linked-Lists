#include <iostream>
#include "linkedList.hpp"

using namespace std;

int main(){

    Lists* list = new Linkedlist();
    int  n, res, pos;
    char op;

    do{ 
        cout << "Op: ";
        cin >> op;
        switch(op){
            case 'f':
                cin >> n;
                list->addHead(n);
                break;
            case 'l':
                cin >> n;
                list->addTail(n);
                break;
            case 'p':
                list->print();
                break;
            case 'F':
                res = list->removeFirst();
                if(res != -1){
                    cout << "Removed " << res << endl;
                }else{
                    cout << "Nothing is removed" << endl;
                }
                break;
            case 'L':
                res = list->removeLast();
                if(res != -1){
                    cout << "Removed " << res << endl;
                }else{
                    cout << "Nothing is removed" << endl;
                }
                break;
            case 'r':
                cin >> n;
                res = list->remove(n);
                if(res != -1){
                    cout << "Removed at position " << res << endl;
                }else{
                    cout << "Nothing is removed" << endl;
                }
                break;
            case 'R':
                cin >> n;
                res = list->removeAll(n);
                if(res != -1){
                    cout << "Removed elements: " << res << endl;
                }else{
                    cout << "Nothing is removed" << endl;
                }
                break;
            case 't':
                cin >> pos;
                res = list->removeAt(pos);
                if(res != -1){
                    cout << "Removed number: " << res << endl;
                }else{
                    cout << "Nothing is removed" << endl;
                }
                break;
            case 'I':
                cin >> n;
                cin >> pos;
                list->addAt(n , pos);
                break;
            case 'z':
                list->reverse();
                break;
            case 'g':
                cin >> pos;
                res = list->get(pos);
                if(res != -1){
                    cout << "Number at position " << pos << " is " << res << endl;
                }else{
                    cout << "Invalid Position" << endl;
                }
                break;
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Operation" << endl;
                break;
            }

    }while(op != 'x');

}
