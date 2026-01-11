# Smart Library Management System (C++ OOP)

## 📖 Overview
This project is a console-based Library Management System built in C++ using Object-Oriented Programming. It allows librarians to register users, assign and track borrowed books, manage returns, and view user records using an in-memory database powered by STL containers.

---

## 🧠 OOP & STL Concepts Used
- Inheritance (`Librarian` inherits from `User`)
- Static data members shared across all users
- Encapsulation with protected data
- Polymorphism via virtual methods
- STL `unordered_map` for fast in-memory storage
- Namespaces for logical grouping

---

## 🗂️ Core Classes

### `User`
Stores all registered users in a shared static map.
- ID
- Name
- Email
- Phone number  
Provides protected access and a virtual `show_user_info()` function.

### `Librarian`
Extends `User` and controls all operations:
- Create users
- Delete users
- Assign books
- Mark book return
- View user and book data  

It also maintains a `record` map to track which user has which book and since when.

---

## ⚙️ Features
- Register users with ID, name, email, and phone
- Remove users
- Assign books to users
- Mark book resubmission
- View user details
- View borrowed book records
- Input-driven menu system

---

## ▶️ How to Run
```bash
g++ main.cpp -o library
./library
