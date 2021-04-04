#include <iostream>

using namespace std;

struct Node {
    int info;
    struct Node *next;
}*start;

class LList {
public:
        Node* create_node(int);     //create new node
        void insert_begin(int);     //
        void insert_pos(int, int);
        void insert_last(int);
        void delete_pos(int);
        void sortList();
        void searchList(int);
        void updateList(int, int);
        void reverseList();
        void display();
        LList() {
            start = NULL;
        }
};

Node *LList::create_node(int value) {
    struct Node *temp, *s;
    temp = new(struct Node);
    if (temp == NULL) {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }

    temp->info = value;
    temp->next = NULL;    //set the node to the null
    return temp;
};

void LList::insert_begin(int value) {   //insert at begin link list
    struct Node *temp, *p;
    temp = create_node(value);    //create new
    if (start == NULL) {
        start = temp;
        start->next = NULL;
    }
    else {
        p = start;      //add at begin link list
        start = temp;
        start->next = p;
    }

    cout << "After insert " << value << " at front: ";
    display();
}

void LList::insert_last(int value) {
    struct Node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL) {
        s = s->next;
    }

    temp->next = NULL;
    s->next = temp;

    cout << "After insert " << value << " at end: ";
    display();
}

void LList::insert_pos(int value, int pos) {
    int counter = 0;
    struct Node *temp, *s, *ptr;
    temp = create_node(value);
    int i;
    s = start;
    while (s != NULL) {
        s = s->next;
        counter++;
    }

    if (pos == 1) {
        if (start == NULL) {
            start = temp;
            start->next = NULL;
        }
        else {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }

    else if (pos > 1  && pos <= counter) {
        s = start;
        for (i = 1; i < pos; i++) {
            ptr = s;
            s = s->next;
        }

        ptr->next = temp;
        temp->next = s;
    }

    else {
        cout<<"Positon out of range"<<endl;
        return;
    }

    cout << "After insert " << value << " at pos " << pos << ": ";
    display();
}

void LList::sortList(){
    struct Node *ptr, *s;
    int value;
    if (start == NULL) {
        cout<<"The List is empty"<<endl;
        return;
    }

    ptr = start;
    while (ptr != NULL) {
        for (s = ptr->next;s !=NULL;s = s->next) {
            if (ptr->info > s->info) {
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }

    cout << "After sort: ";
    display();

}

void LList::delete_pos(int pos) {
    if (start == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    int i, counter = 0;
    struct Node *s, *ptr;
    s = start;
    if (pos == 1) {
        start = s->next;
    }

    else {
        while (s != NULL) {
            s = s->next;
            counter++;
        }

        if (pos > 0 && pos <= counter) {
            s = start;
            for (i = 1;i < pos; i++) {
                ptr = s;
                s = s->next;
            }

            ptr->next = s->next;
        }

        else {
            cout<<"Position out of range"<<endl;
            return;
        }

        delete(s);
    }

    cout << "After delete pos " << pos << ": ";
    display();
}

void LList::updateList(int value, int pos) {    //update value or change the value
    if (start == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    struct Node *s, *ptr;
    s = start;
    if (pos == 1) {
        start->info = value;
    }

    else {
        for (int i = 0;i < pos - 1;i++) {
            if (s == NULL) {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->info = value;
    }

    cout << "After update " << value << " at pos " << pos << ": ";
    display();
}

void LList::searchList(int value) {
    if (start == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    int pos = 0;
    bool flag = false;
    struct Node *s;
    s = start;

    while (s != NULL) {
        pos++;
        if (s->info == value) {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }

    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;

}

void LList::reverseList() {
    if (start == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    if (start->next == NULL) {
        return;
    }


    struct Node *ptr1, *ptr2, *ptr3;

    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;

    while (ptr3 != NULL) {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    start = ptr2;

    cout << "After reverse: ";
    display();
}

void LList::display() {
    if (start == NULL) {
        cout<<"{Empty}"<<endl;
        return;
    }

    struct Node *temp;
    temp = start;

    while (temp != NULL) {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    LList ll1;
    start = NULL;

    ll1.insert_begin(0);
    ll1.insert_begin(1);
    ll1.insert_begin(2);
    ll1.insert_begin(3);
    ll1.insert_begin(4);
    ll1.insert_last(5);
    ll1.insert_last(6);
    ll1.insert_last(7);
    ll1.insert_pos(8, 4);
    ll1.insert_pos(9, 5);

    ll1.reverseList();
    ll1.sortList();

    ll1.delete_pos(5);
    ll1.delete_pos(15);
    ll1.delete_pos(9);

    ll1.updateList(10, 8);
    ll1.updateList(10, 1);
    ll1.updateList(10, 3);

    for (int i=0; i<15; i++)
        ll1.searchList(i);

    return 0;
}
