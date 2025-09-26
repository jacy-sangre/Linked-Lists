case 'g':
                cin >> pos;
                res = list->get(pos);
                if(res != -1){
                    cout << "Number at position " << pos << " is " << res << endl;
                }else{
                    cout << "Invalid Position" << endl;
                }
                break;