# Smart Library Management System (C++ OOP)

## 📖 Overview
This project is a console-based Library Management System written in C++ using Object-Oriented Programming. It simulates how libraries manage users, books, and borrowing operations through a structured class design.

---

## 🧠 OOP Concepts Used
- Abstract base class
- Inheritance
- Polymorphism
- Encapsulation
- Static data members
- Composition (Library has Books and Users)

---

## 🗂️ Class Structure

### `User` (Abstract)
- ID, Name
- `showInfo()` (virtual)

### `Student` (Derived)
- Can borrow and return books

### `Librarian` (Derived)
- Can add and remove books

### `Book`
- Book ID
- Title
- Author
- Availability status

### `Library`
- Stores books and users
- Controls borrowing and returning

---

## ⚙️ Features
- Add and remove books
- Register users
- Search books
- Borrow and return books
- Track issued and available books

---

## ▶️ How to Run

```bash
g++ main.cpp -o library
./library
