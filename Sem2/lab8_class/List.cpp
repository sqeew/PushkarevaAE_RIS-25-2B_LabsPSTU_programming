#include "List.h"
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>
using namespace std;

List::List() {
    head = nullptr;
    cur = 0;
    size = 0;
}

List::List(int n) {
    head = nullptr;
    cur = 0;
    size = n;
}

List::List(const List& a) {
    head = nullptr;
    cur = 0;
    size = a.size;

    if (a.head == nullptr) return;

    Node* temp = a.head;
    Node** current = &head; 

    while (temp != nullptr) {
        *current = new Node;
        (*current)->data = temp->data;
        (*current)->next = nullptr;

        current = &((*current)->next);
        temp = temp->next;
        cur++;
    }
}


List::~List() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    cur = 0;
}

void List::del() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head->data;
        delete head;
        head = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next->data;
        delete temp->next;
        temp->next = nullptr;
    }
    cur--;
}

void List::add() {
    Object* p = nullptr;
    cout << "1.Person\n2.Employee\n";
    int y;
    cin >> y;

    if (y == 1) {
        Person* a = new Person;
        a->input();
        p = a;
    }
    else if (y == 2) {
        Employee* b = new Employee;
        b->input();
        p = b;
    }
    else {
        return;
    }

    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cur++;
}

void List::add(Object* p) {
    if (cur >= size && size > 0) {
        cout << "List is full!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cur++;
}

void List::show() {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        temp->data->show(); 
        temp = temp->next;
    }
}

void List::ShowName(int k) {
    if (k < 1 || k > cur) {
        cout << "Wrong number!" << endl;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    cout << "Name: " << temp->data->Get_name()<< endl;
}

int List :: operator()() {
    return cur;
}