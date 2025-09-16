#include <iostream>
#include "linkedList.hpp"

using namespace std;

int main(){

    Lists* list = new Linkedlist();
    int  n, res;
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
            case 'x':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Operation" << endl;
                break;
            }

    }while(op != 'x');
}
