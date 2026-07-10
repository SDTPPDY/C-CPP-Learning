

template <typename T>
List<T>::List() : link(NULL) {}

template <typename T>
List<T>::~List() {
    List<T>* cur = link;
    while (cur != NULL) {
        List<T>* tmp = cur;
        cur = cur->link;
        tmp->link = NULL;
        delete tmp;
    }
    link = NULL;
}

template <typename T>
void List<T>::append(const T& val) {
    List* ptr = this;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new List;
    ptr->link->data = val;
    ptr->link->link = NULL;
}

template <typename T>
void List<T>::insertElement(int pos, const T& val) {
    List* ptr = this;
    int cnt = 0;
    while (ptr->link != NULL && cnt <= pos) {
        ptr = ptr->link;
        cnt++;
    }
    List* node = new List;
    node->data = val;
    node->link = ptr->link;
    ptr->link = node;
}

template <typename T>
void List<T>::deleteElement(const T& val) {
    List* ptr = this;
    bool found = false;
    while (ptr->link != NULL) {
        if (ptr->link->data == val) {
            List* tmp = ptr->link;
            ptr->link = ptr->link->link;
            tmp->link = NULL;
            delete tmp;
            found = true;
        }
        else {
            ptr = ptr->link;
        }
    }
    if (!found) {
        cout << "\nElement " << val << " not Found.";
    }
}

template <typename T>
void List<T>::travalList() const {
    cout << endl;
    const List* cur = this->link;
    while (cur != NULL) {
        cout << "->" << cur->data;
        cur = cur->link;
    }
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
