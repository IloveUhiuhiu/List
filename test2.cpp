
#include <bits/stdc++.h>
using namespace std;
template <class T>
class node
{   
public:
    T data;
    node *prev;
    node *next;
    node(T data)
    {
        this->data = data; // phần dữ liệu của một node
        this->next = NULL; // con trỏ trỏ tới node kế tiếp nó
        this->prev = NULL; // con trỏ trỏ tới node trước nó
    }
};
template <class T>
class List
{
private:
    int _size;
    node *head; // con trỏ trỏ tới node đầu tiên
    node *tail; // con trỏ trỏ tới node cuối cùng
public:
    // hàm dựng constructor
    List();
    // hàm hủy destructor
    ~List();
    // hàm thêm một node vào cuối danh sách
    void push_back(T);
    // hàm thêm một node vào vị trí bất kì
    void add(int, T);
    // xóa một node bất kì
    void erase(int);
    // xóa toàn bộ dư liệu và xóa bộ nhớ
    void clear();
    // xóa dữ liệu theo khoảng
    void erase(int,int);
    // trả về kích thước của danh sách
    int getSize();
    // đa năng hóa toán tử []
    T& operator[] (int);
    // hiển thị danh sách
    void Display();
};
// hàm dựng constructor
List::List()
{
    this->head = NULL;
    this->tail = NULL;
    this->_size = 0;
}
// hàm hủy destructor
List::~List()
{
    while (this->head)
    {
        node *next = this->head->next;
        delete this->head;
        this->_size--;
        this->head = next;
    }
}
// hàm thêm một node vào cuối danh sách
void List::push_back(T data)
{
    node *new_node = new node(data);
    if (this->head == NULL)
    {
        this->head = this->tail = new_node;
    }
    else
    {
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    }
    this->_size++;
}
// hàm thêm một node vào vị trí bất kì
void List::add(int index, T data)
{
    if (index < 0 || index >= this->_size)
        return;
    node *new_node = new node(data);
    if (this->_size == 0)
    {
        this->head = this->tail = new_node;
    }
    else
    {
        if (index == 0)
        {
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }
        else if (index == this->_size)
        {
            push_back(data);
        }
        else
        {
            node *p = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            new_node->prev = p;
            p->next->prev = new_node;
            p->next = new_node;
        }
    }
    this->_size++;
}
// xóa một node bất kì
void List::erase(int index)
{
    if (index < 0 || index >= this->_size)
        return;
    if (this->_size == 0)
    {
        return;
    }
    else if (this->_size == 1)
    {
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else
    {
        if (index == 0)
        {
            node *p = this->head->next;
            p->prev = NULL;
            delete this->head;
            this->head = p;
        }
        else if (index == this->_size - 1)
        {
            node *p = this->tail->prev;
            p->next = NULL;
            delete this->tail;
            this->tail = p;
        }
        else
        {
            node *p = this->head;
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
    }
    this->_size--;
}
// xóa toàn bộ dư liệu và xóa bộ nhớ
void List::clear()
{
    if (this->_size == 0)
    {
        return;
    }
    else if (this->_size == 1)
    {
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else
    {
        node *p = this->head;
        node *pnext = this->head->next;
        for (int i = 0; i < this->_size - 1; i++)
        {
            delete p;
            p = pnext;
            pnext = pnext->next;
        }
        delete p;
    }
    this->_size = 0;
}
// xóa dữ liệu theo khoảng
void List::erase(int begin,int end) {
    if (begin >= 0 && begin <= end && end < this->_size) {
        for (int i=begin; i<=end;i++) {
            erase(i);
        }
    }
}
// trả về kích thước của danh sách
int List:: getSize() {
    return this->_size;
}
// đa năng hóa toán tử []
T& List::operator [] (int index) {
    static T NGU;
    if (index >= 0 && index < this->_size) {

        node* p = this->head;
        for (int i=0; i<index; i++) {
            p = p->next;
        }
        return p->data;
    } else {
        return NGU;
    }
}
void List::Display () {
    node *p = this->head;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
}
int main() {
    List L;
    for (int i=0; i<10; i++) {
        L.push_back(i);
    }
    L.Display();
}