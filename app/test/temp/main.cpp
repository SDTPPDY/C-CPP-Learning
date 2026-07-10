#include <bits/stdc++.h>
using namespace std;

class List {
  private:
    int data;
    List* link;

  public:
    List();
    List(const List& other);
    List(const vector<int>& vec);
    void append(const int& val);
    void insertElement(int pos, const int& val);
    void deleteElement(const int& val);
    void travalList() const;
    void getLength() const;
    bool isEqual(const List& other) const;
    void connect(const List& other);
    bool isEmpty() const;
};

List::List() : data(0), link(NULL) {}

List::List(const List& other) : data(other.data), link(NULL) {
    if (other.link != NULL) {
        link = new List(*other.link);
    }
}

List::List(const vector<int>& vec) : data(0), link(NULL) {
    for (const int& val : vec) {
        append(val);
    }
}

void List::append(const int& val) {
    List* newNode = new List();
    newNode->data = val;
    newNode->link = NULL;
    if (link == NULL) {
        link = newNode;
    }
    else {
        List* temp = link;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

void List::insertElement(int pos, const int& val) {
    List* newNode = new List();
    newNode->data = val;
    newNode->link = NULL;
    if (pos == 0) {
        newNode->link = link;
        link = newNode;
    }
    else {
        List* temp = link;
        for (int i = 0; i < pos; ++i) {
            temp = temp->link;
        }

        newNode->link = temp->link;
        temp->link = newNode;
    }
}

void List::deleteElement(const int& val) {
    List* curr = link;
    if (link->data == val) {
        link = link->link;
        delete curr;
        return;
    }

    while (curr->link != NULL && curr->link->data != val)
        curr = curr->link;

    if (curr->link == NULL) {
        cout << "Element " << val << " not Found." << endl;
    }
    else {
        List* temp = curr->link;
        curr->link = temp->link;
        delete temp;
    }

    return;
}

void List::travalList() const {
    List* curr = link;
    while (curr) {
        cout << "->" << curr->data;
        curr = curr->link;
    }
    cout << endl;
}

void List::getLength() const {
    List* curr = link;
    int count = 0;
    while (curr) {
        ++count;
        curr = curr->link;
    }

    cout << "The length of this List is " << count << "." << endl;
}

bool List::isEqual(const List& other) const {
    List* curr1 = link;
    List* curr2 = other.link;

    while (curr1 && curr2) {
        if (curr1->data != curr2->data)
            return false;
        curr1 = curr1->link;
        curr2 = curr2->link;
    }

    return (curr1 == NULL && curr2 == NULL);
}

bool List::isEmpty() const {
    return link == NULL;
}

void List::connect(const List& other) {
    if (link == NULL) {
        link = new List(*other.link);
    }
    else {
        if (other.isEmpty())
            return;

        List* temp = other.link;
        while (temp) {
            append(temp->data);
            temp = temp->link;
        }
    }

    cout << "After connect:" << endl;
}
