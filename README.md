# 🔗 clsDbLinkedList – Generic Doubly Linked List (C++)

`clsDbLinkedList<T>` is a robust, template-based C++ class that implements a **Doubly Linked List** from scratch. This project demonstrates advanced manual memory management, pointer manipulation, and the power of C++ Templates to create reusable data structures.

---

## 🛠 Features & Services

The library provides a comprehensive set of operations for efficient list management:

| Category | Features |
| :--- | :--- |
| **Insertion** | `InsertAtBeginning`, `InsertAtEnd`, `InsertAfter`, `InsertBefore`, `AddAt(index)`. |
| **Deletion** | `DeleteFirstNode`, `DeleteLastNode`, `DeleteNode(value)`, `Clear()`. |
| **Traversal** | Bidirectional traversal, `Search`, `GetNode`, `GetItem(index)`. |
| **Utility** | `Size`, `IsEmpty`, `UpdateItem`, `Reverse`. |
| **Design** | Fully **Templated** class, Internal `Node` structure, manual pointer handling. |

---



## 📊 Core Methods Matrix

### 📥 Insertion Methods
`InsertAtBeginning(value)`, `InsertAtEnd(value)`, `InsertAfter(TargetNode, value)`, `InsertBefore(TargetNode, value)`.

### 📤 Deletion & Maintenance
`DeleteFirstNode()`, `DeleteLastNode()`, `DeleteNode(NodePtr)`, `Clear()`, `UpdateItem(index, newValue)`.

### 🔍 Search & Retrieval
`Find(value)`, `GetNode(index)`, `GetItem(index)`, `Size()`, `IsEmpty()`.

---

## 💻 Example Usage

### 1️⃣ Basic Insertion & Printing
```cpp
clsDbLinkedList<int> list;

list.InsertAtEnd(10);
list.InsertAtEnd(20);
list.InsertAtBeginning(5);

list.PrintList(); // Output: 5 10 20
```
### 2️⃣ Advanced Operations
```cpp

clsDbLinkedList<string> names;

names.InsertAtEnd("Ahmed");
names.InsertAtEnd("Ali");
names.InsertAfter(names.Find("Ahmed"), "Omar");

cout << "Size: " << names.Size(); // Output: 3
names.Reverse();
names.PrintList(); // Output: Ali Omar Ahmed
```
---
## 🎯 Project Purpose
This project is a deep dive into data structures, focusing on:

- Manual Memory Management: Handling new and delete to prevent memory leaks.

- Template Programming: Making the list "Generic" to support any data type (int, string, objects).

- Pointer Logic: Managing Next and Previous pointers to maintain list integrity.

- OOP Principles: Encapsulation of the Node structure within the main class.
---

## 📝 Technical Implementation Details
- Node Structure: Each node contains a Value, and two pointers (Next, Prev).

- Dynamic Sizing: The list grows and shrinks in memory at runtime.

- Safety: Includes checks for empty lists and null pointers during operations.
---

## 📜 License
This project is provided for educational use and data structure practice only.
