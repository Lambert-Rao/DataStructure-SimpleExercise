#include <stdexcept>
#include <sstream>

template<typename T>
class List;

template<typename T>
class ListNode {
    friend class List<T>;

public:
    explicit ListNode(const T &data) : element(data) {}

    ListNode(const T &data, ListNode<T> *next, ListNode<T> *prev) : element(data), next(next), prev(prev) {}

private:
    T element;
    ListNode<T> *next = nullptr;
    ListNode<T> *prev = nullptr;
};

template<typename T>
class List {
    friend class ListNode<T>;

public:
    List() = default;

    List(const List<T> &rhs) = delete;

    List(initializer_list<T> il);

    ~List();

    void erase(int index);

    int index_of(const T &rhs) const;

    T operator[](int index) const;

    void insert(int index, const T &rhs);

    void push_back(const T &data);

    explicit operator string() const;


protected:
    ListNode<T> *head = nullptr;
    ListNode<T> *tail = nullptr;
    int size = 0;

    void check_index(int index) const;
};

template<typename T>
List<T>::~List() {
    ListNode<T> *p = head;
    while (p != nullptr) {
        ListNode<T> *tmp = p;
        p = p->next;
        delete tmp;
    }

}

template<typename T>
T List<T>::operator[](int index) const {
    check_index(index);
    ListNode<T> *p = head;
    for (int i = 0; i < index; i++)
        p = p->next;
    return p->element;
}

template<typename T>
List<T>::List(initializer_list<T> il) {
    size = il.size();
    for (auto it = il.begin(); it != il.end(); it++) {
        push_back(*it);
    }

}

template<typename T>
void List<T>::push_back(const T &data) {
    if (head == nullptr) {
        head = new ListNode<T>(data);
        tail = head;
    } else {
        tail->next = new ListNode<T>(data, nullptr, tail);
        tail = tail->next;
    }

}

template<typename T>
int List<T>::index_of(const T &rhs) const {
    ListNode<T> *p = head;
    int index = 0;
    while (p != nullptr) {
        if (p->element == rhs)
            return index;
        p = p->next;
        ++index;
    }
    return -1;
}

template<typename T>
void List<T>::erase(int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("index out of range");
    if (index == 0) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    } else if (index == size - 1) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    } else {
        ListNode<T> *p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

template<typename T>
List<T>::operator string() const {
    ostringstream oss;
    oss << "address of head: " << head << endl
        << "address of tail: " << tail << endl
        << "size: " << size << endl
        << "elements: " << endl;
    for (ListNode<T> *p = head; p != nullptr; p = p->next)
        oss << p->element << ' ';
    return oss.str();
}

template<typename T>
void List<T>::insert(int index, const T &rhs) {
    check_index(index);
    if (index == 0) {
        head = new ListNode<T>(rhs, head, nullptr);
        head->next->prev = head;
    } else if (index == size - 1) {
        tail = new ListNode<T>(rhs, nullptr, tail);
        tail->prev->next = tail;
    } else {
        ListNode<T> *p = head;
        for (int i = 0; i != index; i++)
            p = p->next;
        auto *tmp = new ListNode<T>(rhs, p, p->prev);
        p->prev->next = tmp;
        p->prev = tmp;
    }

}

template<typename T>
void List<T>::check_index(int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("index out of range");

}

template<typename T>
ostream& operator<<(ostream& os, const List<T>& rhs)
{
    os << static_cast<string>(rhs);
    return os;
}