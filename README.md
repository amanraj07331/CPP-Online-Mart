# 🛒 CPP-Online-Mart
This is a console-based **Online Shopping Management System** written in C++ using object-oriented programming (OOP). The system simulates a simple virtual store that allows a user to browse, select, and purchase items like **Mobiles**, **Laptops**, and **Programming Courses**. After shopping, the system prints a **detailed bill**.

---

## 🚀 Features

- Interactive menu-driven interface.
- Product categories:
  - 📱 Mobiles (Apple, Redmi, Samsung)
  - 💻 Laptops (HP, Lenovo, MacBook)
  - 📚 Programming Courses (C, C++, Java, Python)
- Customer cart management.
- Auto-generated bill with quantity, price, and total cost.
- Uses **OOP concepts**: Inheritance, Virtual functions, Maps, Classes.
- Thread-based delay and screen-clearing for realistic shopping flow.

---


## 🏗️ Project Structure

```cpp
├── main.cpp            // Entire program code
├── fillItems()         // Populates the shop's inventory
├── class customer      // Manages user input and bill generation
├── class shop          // Base class for product categories
├── class mobile        // Derived class for mobiles
├── class laptop        // Derived class for laptops
├── class courses       // Derived class for programming courses
```

##🧠 Concepts Used
map STL for storing inventory and cart items

Inheritance and polymorphism

Use of virtual functions

Thread handling with:


📄 License
This project is open-source and available under the MIT License.

🙌 Acknowledgements
Created by Aman Raj

Inspired by OOPs practices and real-world e-commerce systems.
