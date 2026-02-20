# Binary-Tree-Template-CPP

This C++ project provides a generic template implementation of a **Binary Tree (AB - Arbore Binar)** using a vector-based representation. The project demonstrates how to manage hierarchical data structures for various data types, such as strings and custom objects like cars.

---

## Features

* **Generic Implementation**: Uses C++ templates to support any data type (`TElem`), allowing for trees of strings, integers, or custom structures.
* **Vector-Based Storage**: Efficiently manages tree nodes using `std::vector` for both elements and validity flags.
* **Tree Construction**: Supports creating leaf nodes and building complex trees by combining root elements with subtrees.
* **Subtree Management**: Includes functionality to dynamically add or retrieve left and right subtrees.
* **Tree Traversal**: Features a `visitTree` method that applies a function to every valid node in the tree.

---

## Node Mapping Logic

The binary tree is implemented using an array-based representation within a `std::vector`. Instead of using pointers, parent-child relationships are calculated through indices:



| Relationship | Formula | Code Implementation |
| :--- | :--- | :--- |
| **Root** | Index 1 | `rad = 1;` |
| **Left Child** | $i \times 2$ | `elems[2 * i] = st.elems[i];` |
| **Right Child** | $(i \times 2) + 1$ | `elems[2 * i + 1] = dr.elems[i];` |
| **Parent Node** | $\lfloor k/2 \rfloor$ | Internal logic for position tracking |

---

## Architecture

| Component | Responsibility |
| :--- | :--- |
| **AB<TElem>** | The core template class defining binary tree operations and internal vector storage. |
| **main.cpp** | Provides implementation examples, including Electronics categories and a Car inventory. |
| **visitTree** | A higher-order function utility for traversing and processing node data. |

---

## Usage Examples

The application demonstrates the binary tree's flexibility through two main scenarios in `main.cpp`:

### 1. Electronics Category Tree
Constructs a hierarchy for electronics where "Electronics" is the root, with "Laptops" and "Phones" as sub-branches.

### 2. Car Inventory Tree
Organizes `masina` (car) structures containing IDs, years, and prices into a binary tree.
* **Car Structure**: Includes `id`, `an` (year), and `pret` (price).
* **Output Example**: Displays formatted information like "ID: 101 An: 2020 Pret: 15000 EUR".

---

## Technical Specifications

* **Dynamic Resizing**: Internal vectors automatically resize when adding subtrees that exceed current capacity.
* **Validity Flags**: A separate `std::vector<bool> valid` tracks which indices contain active tree elements to prevent invalid access.
* **Exception Handling**: The `element()` method throws a `std::runtime_error` if the tree is empty.
