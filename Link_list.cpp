#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
void _clear(char[], int);

struct Node{
    typedef string cate;
    cate cla;
    int no;
    string name;
    Node* next;
};

class Store{
    private:
        Node* top = NULL;
        int no = 0;
    public:
    	Node* top_node(){return top;}
        int print_top(){if(top == NULL) return 0; return top-> no;};
        Node::cate top_class(){return top-> cla;};
        string top_name(){return top-> name;}
        void push(Node::cate, string);
        void pop();
        void display();
        bool isEmpty(){if(no == 0) return true; else return false;};
        void display_class(Node::cate);
        Node* _search(string);                                         //return the item number
        void _insert(int, Node::cate, string);
        void _delete(int);
        void _insert_list(int no, int _no);
        void _reverse(Node*);
};

void Store::push(Node::cate cla, string name){
    Node* newNode = new Node;
    newNode-> cla = cla;
    newNode-> no = ++no;
    newNode-> name = name;
    newNode-> next = top;
    top = newNode;
}

void Store::pop(){
    if(isEmpty()){
        cout << "Store is empty!!" << endl << endl;
        return;
    }else{
        Node* temp;
        cout << "REMOVE" << endl;
        cout << "No. " << top-> no << endl;
        cout << "Class " << top-> cla << "  " << top-> name << endl << endl;
        no--;
        temp = top;
        top = top-> next;
        delete temp;
    }
}

void Store::display(){
    if(isEmpty()){
        cout << "There is nothing in storage." << endl;
        return;
    }else{
        Node* ptr = top;
        while(ptr != NULL){
            cout << "Class " << ptr-> cla << endl;
            cout << "No. " << ptr-> no << "  " << ptr-> name << endl << endl;
            ptr = ptr-> next;
        }
        delete ptr;
    }
}

void Store::display_class(Node::cate cla){
    if(isEmpty()){
        cout << "There is nothing in storage." << endl;
        return;
    }else{
        cout << "Class " << cla << endl;
        Node* ptr = top;
        bool n = true;
        while(ptr != NULL){
            if(cla == ptr-> cla){
                cout << "No. " << ptr-> no << " " << ptr-> name << endl;
                n = false;
            }
            ptr = ptr-> next;
        }
        if(n) cout << "Nothing\n";
        delete ptr;
    }
    return;
}

Node* Store::_search(string name){
    if(isEmpty()){
        cout << " Store is empty" << endl;
        return NULL;
    }
    else{
        Node* ptr = top;
        while(ptr != NULL){
            if(ptr-> name == name){
                cout << "\nClass " << ptr-> cla << endl;
                cout << "No. " << ptr-> no << "  " << ptr-> name << endl << endl;
                return ptr;
            }else{
                ptr = ptr-> next;
            }
        }
        cout << "Not fine!!" << endl;
        return NULL;
    }
}

void Store::_insert(int _no, Node::cate cla, string name){
    if((isEmpty() && _no > 0) || _no > top-> no || _no <= 0) cout << "Error!!\n";
    else{
        no--;
        Node* newNode = new Node;
        Node* ptr = top;
        newNode-> no = _no;
        newNode-> cla = cla;
        newNode-> name = name;
        while(ptr != NULL){
            ptr-> no++;
            if(ptr-> no == _no+1){
                newNode-> next = ptr-> next;
                ptr-> next = newNode;
                return;
            }else ptr = ptr-> next;
        }
    }
}

void Store::_delete(int _no){
    if(isEmpty()){
        cout << "Storage have nothing!!" << endl;
        return;
    }else if(_no > top-> no || _no <= 0){
        cout << "Error!!" << endl;
    }else if(_no == top-> no){
        pop();
    }else{
        no--;
        Node* ptr = top;
        while(ptr != NULL){
            ptr-> no--;
            if(ptr-> no == _no){
                cout << ptr-> next-> name << " is remove" << endl;
                if(ptr-> next-> next == NULL){
                    ptr-> next = NULL;
                    return;
                }
                ptr-> no = ptr-> next-> no;
                ptr-> next = ptr-> next-> next;
                return;
            }else ptr = ptr-> next;
        }
    }
}

void Store::_insert_list(int no, int _no){
    if(isEmpty()){
        cout << "Storage have nothing!!" << endl;
        return;
    }else if(no > top-> no || no <= 0 || _no > top-> no || _no <= 0){
        cout << "Error!!" << endl;
        return;
    }else{
        Node* pte = top;
        Node* ptr = top;
        while(ptr != NULL){
            if(ptr-> no == no){
                while(pte != NULL){
                    if(pte-> no == _no){
                        ptr-> next = pte-> next;
                        pte-> next = top;
                        top = pte;
                        break;
                    }else pte = pte-> next;
                }
                break;
            }else ptr = ptr-> next;
        }
        ptr = top;
        int t = pte-> next-> no;
        while(ptr != NULL){
            ptr-> no = t--;
            ptr = ptr-> next;
        }
    }
}

void Store::_reverse(Node* first){
	int _no = top-> no;
	Node* fwd = first-> next;
	Node* ptr = first;
	Node* pre = NULL;
	while(fwd != NULL){
		ptr-> next = pre;
		pre = ptr;
		ptr = fwd;
		fwd = fwd-> next;
	}
	ptr-> next = pre;
	top = ptr;
	while(ptr != NULL){
        ptr-> no = _no--;
        ptr = ptr-> next;
    }
}

int main(){
    Store S1;
    Store* reg = new Store;
    Node::cate _class;
    string name;
    int choice, no, _no, _size, i = 0, sw = 0;

    fstream file;
    file.open("data/linklist_data.txt", ios::in);
    char data[100] = {' '};
    while(!file.eof()){
        file.getline(data, sizeof(data));
        switch(sw){
            case 0:
                _class = data;
                break;
            case 1:
                name = data;
                break;
            default:
                break;
        }
        if(sw){
            S1.push(_class, name);
        }

        if(sw == 1) sw = 0;
        else sw++;
    }
    file.close();

    while(true){

        cout << "\nPlease select an action:" << endl;
        cout << "  1. Push the item to the storage" << endl;
        cout << "  2. Pop the last last item put in" << endl;
        cout << "  3. Show all stock" << endl;
        cout << "  4. Search the item in storage" << endl;
        cout << "  5. Search the class" << endl;
        cout << "  6. Insert the item" << endl;
        cout << "  7. Delete the data" << endl;
        cout << "  8. Move the list" << endl;
        cout << "  9. Output" << endl;
        cout << "  0. Clear screen\n" << endl;

        cin >> choice;
        if(choice == -1) break;

        switch(choice){
            case 1:
                cout << "Enter the class: ";
                cin >> _class;
                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, name);
                S1.push(_class, name);
                break;
            case 2:
                S1.pop();
                break;
            case 3:
                S1.display();
                break;
            case 4:
                cout << "Enter the data name: ";
                cin.ignore();
                getline(cin, name);
                S1._search(name);
                break;
            case 5:
                cout << "Enter the class name: ";
                cin >> _class;
                S1.display_class(_class);
                break;
            case 6:
                cout << "Enter the serial number: ";
                cin >> no;
                cout << "Enter the class: ";
                cin >> _class;
                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, name);
                S1._insert(no, _class, name);
                break;
            case 7:
                cout << "Enter the data number: ";
                cin >> no;
                S1._delete(no);
                break;
            case 8:
                cout << "Enter the No. want to move: ";
                cin >> no;
                cout << "Enter the target number: ";
                cin >> _no;
                S1._insert_list(no, _no);
                break;
            case 9:
            	S1._reverse(S1.top_node());
                sw = S1.print_top();
                file.open("data/linklist_data.txt", ios::out);
                if(S1.print_top() == 0) file << " ";
                else{
                    for(i = 0; i < sw; i++){
                        file << S1.top_class() << endl;
                        file << S1.top_name() << endl;
                        S1.pop();
	                    }
	                }
	                file.close();
                system("cls");
                cout << "Data input completed." << endl;
                break;
            case 0:
                system("cls");
                break;
            default:
                break;
        }
        if(choice == 9){
            break;
        }
    }
    return 0;
}

