#pragma once
#include <iostream>

template <class T>
class clsDbLinkedList {

public:

    class Node {


    public:

        Node* Prev;

        T Value;

        Node* Next;

        Node() {
            Prev = nullptr;
            Next = nullptr;
        }
    };



private:

    Node* Head = nullptr;

    short _Size = 0;

private:
    ~clsDbLinkedList() {
        Clear();
    }

    bool IsEmpty() const {
        return Head == nullptr;
    }

    void AddAtBeginning(T item) {


        Node* NewNode = new Node;
        NewNode->Value = item;

        if (IsEmpty()) {
            Head = NewNode;
        }
        else {
            NewNode->Next = Head;
            Head->Prev = NewNode;
            Head = NewNode;
        }

        _Size++;
    }

    void AddAtEnd(T item) {

        if (IsEmpty()) {
            AddAtBeginning(item);
            return;
        }

        Node* NewNode = new Node;
        NewNode->Value = item;

        Node* temp = Head;
        while (temp->Next != nullptr)
            temp = temp->Next;

        temp->Next = NewNode;
        NewNode->Prev = temp;

        _Size++;
    }

    void AddAfter(T item, T NewItem) {

        Node* itemNode = Find(item);

        if (itemNode != nullptr) {
            Node* NewNode = new Node;
            NewNode->Value = NewItem;

            NewNode->Next = itemNode->Next;
            NewNode->Prev = itemNode;

            if (itemNode->Next != nullptr)
                itemNode->Next->Prev = NewNode;

            itemNode->Next = NewNode;
            _Size++;
        }
        else {
            std::cout << "\n[Error] Item not found.\n";
        }
    }

    bool InsertAfter(short index, T NewValue) {

        Node* current = GetNode(index);
        if (current == nullptr)
            return false;

        AddAfter(current->Value, NewValue);
        return true;
    }

    void AddBefore(T item, T NewItem) {

        Node* itemNode = Find(item);

        if (itemNode != nullptr) {
            if (itemNode == Head) {
                AddAtBeginning(NewItem);
                return;
            }

            Node* NewNode = new Node;
            NewNode->Value = NewItem;

            NewNode->Next = itemNode;
            NewNode->Prev = itemNode->Prev;
            itemNode->Prev->Next = NewNode;
            itemNode->Prev = NewNode;

            _Size++;
        }
        else {
            std::cout << "\n[Error] Item not found.\n";
        }
    }

    void DeleteBeginning() {

        if (IsEmpty())
            return;

        Node* temp = Head;
        Head = Head->Next;

        if (Head != nullptr)
            Head->Prev = nullptr;

        delete temp;
        _Size--;
    }

    void DeleteEnd() {

        if (IsEmpty())
            return;

        if (Head->Next == nullptr) {
            DeleteBeginning();
            return;
        }

        Node* temp = Head;
        while (temp->Next != nullptr)
            temp = temp->Next;

        temp->Prev->Next = nullptr;
        delete temp;
        _Size--;
    }

    void DeleteItem(T item) {

        Node* itemNode = Find(item);

        if (itemNode != nullptr) {
            if (itemNode == Head) {
                DeleteBeginning();
            }
            else if (itemNode->Next == nullptr) {
                itemNode->Prev->Next = nullptr;
                delete itemNode;
                _Size--;
            }
            else {
                itemNode->Prev->Next = itemNode->Next;
                itemNode->Next->Prev = itemNode->Prev;
                delete itemNode;
                _Size--;
            }
        }
        else {
            std::cout << "\n[Error] Item not found.\n";
        }
    }

    void PrintList() const {

        Node* temp = Head;

        while (temp != nullptr) {
            std::cout << temp->Value << "\t";
            temp = temp->Next;
        }

        std::cout << std::endl;
    }

    Node* Find(T item) const {

        Node* temp = Head;

        while (temp != nullptr) {
            if (temp->Value == item)
                return temp;

            temp = temp->Next;
        }

        return nullptr;
    }

    short Size() const {

        return _Size;
    }

    void Clear() {
        while (!IsEmpty())
            DeleteBeginning();
    }

    void Reverse() {

        if (IsEmpty())
            return;

        Node* current = Head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->Prev;
            current->Prev = current->Next;
            current->Next = temp;
            current = current->Prev;
        }

        if (temp != nullptr)
            Head = temp->Prev;
    }

    Node* GetNode(short index) const {

        if (IsEmpty() || index < 0 || index >= _Size)
            return nullptr;

        short counter = 0;
        Node* current = Head;

        while (current != nullptr) {
            if (counter == index)
                return current;

            current = current->Next;
            counter++;
        }

        return nullptr;
    }

    T GetItem(short index) const {

        Node* current = GetNode(index);
        if (current == nullptr)
            return T(); // Default value
        return current->Value;
    }

    bool UpdateItem(short index, T NewValue) {

        Node* current = GetNode(index);
        if (current == nullptr)
            return false;

        current->Value = NewValue;
        return true;
    }
};