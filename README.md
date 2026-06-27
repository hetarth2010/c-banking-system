# PR. 10 Banking System (C++)

A robust, object-oriented console application written in C++ that models a simplified banking environment. This project serves as a practical assessment demonstrating the strict application of core Object-Oriented Programming (OOP) concepts, including inheritance, encapsulation, and runtime polymorphism.

---

## 📋 Project Requirements & OOP Criteria

This project successfully fulfills the **four fundamental pillars of OOP** as outlined in the evaluation criteria:

1. **Class & Object**: Implementation of concrete entities modeling real-world accounts with active states and behaviors.
2. **Encapsulation**: Critical fields are restricted using `protected` and `private` keywords. Account fields cannot be modified externally and are accessed strictly via secure public interface methods (`deposit()`, `withdraw()`).
3. **Inheritance**: Derived sub-classes (`SavingsAccount` and `CheckingAccount`) extend the base `BankAccount` class to reuse shared attributes and logic while adding unique custom features.
4. **Polymorphism**: The system uses runtime (dynamic) polymorphism via a tracking vector of base pointers (`BankAccount*`) to execute overridden virtual methods dynamically during program runtime.

---

## 🛠️ Class Structure

### 1. Base Class: `BankAccount` (Abstract)
*   **Attributes (`protected`):**
    *   `accountNumber` (string) — Unique identifier for the account.
    *   `accountHolderName` (string) — Name of the client.
    *   `balance` (double) — Current monetary value stored.
*   **Methods (`public`):**
    *   `deposit(amount)` — Safely adds funds to the balance if the input value is positive.
    *   `withdraw(amount)` — Evaluates account rules to process a standard cash withdrawal.
    *   `displayAccountInfo()` — Pure virtual function enforcing custom output formatting in sub-classes.

### 2. Derived Class: `SavingsAccount`
*   **Attributes (`private`):**
    *   `interestRate` (double) — Percentage rate applied to the current balance.
*   **Methods:**
    *   `applyInterest()` — Computes interest and updates the active balance.
    *   `displayAccountInfo()` — *Overridden* to display custom metrics along with active interest rates.

### 3. Derived Class: `CheckingAccount`
*   **Attributes (`private`):**
    *   `overdraftLimit` (double) — Maximum amount a client can borrow beyond zero.
*   **Methods:**
    *   `withdraw(amount)` — *Overridden* to allow overdraft spending limits safely.
    *   `displayAccountInfo()` — *Overridden* to display checking details along with available overdraft capacity.

---



## 🚀 How To Compile and Run

Ensure you have a standard C++ compiler installed (such as GCC/G++).

1. **Clone the repository:**
   ```bash
   git clone <YOUR_GITHUB_REPOSITORY_LINK>
   cd <YOUR_REPOSITORY_DIRECTORY>
   ```

2. **Compile the source file:**
   ```bash
   g++ -std=c++11 main.cpp -o BankingSystem
   ```

3. **Execute the application:**
   ```bash
   ./BankingSystem
   ```

---

## 📸 Output Screenshots
<img width="523" height="305" alt="Screenshot 2026-06-27 132758" src="https://github.com/user-attachments/assets/c3a0dbe2-e098-457a-884c-c1966c173739" />

