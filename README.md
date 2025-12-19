Low-Level Design (LLD) Practice Repository

This repository contains my practical exercises and implementations of various Low-Level Design (LLD) problems in C++. The focus is on object-oriented design principles, design patterns, and clean architecture with an emphasis on real-world system design.

⸻

Table of Contents
	1.	Purpose￼
	2.	Technologies￼
	3.	Key Concepts Practiced￼
	4.	Problems & Implementations￼
	5.	How to Run￼
	6.	Best Practices￼
	7.	License￼

⸻

Purpose

The aim of this repository is to practice LLD concepts by implementing them in C++ with:
	•	Interfaces & Abstraction
	•	Dependency Injection & Composition
	•	Polymorphism
	•	Thread-safe Data Structures
	•	Thread Pools & Synchronization
	•	File I/O & Resource Management

This helps build strong design intuition, modular code, and testable systems.

⸻

Technologies
	•	Language: C++17 / C++20
	•	Compiler: g++, clang
	•	Tools: CMake (optional), Visual Studio Code

⸻

| Concept | Description |
|---------|-------------|
| Interfaces (Pure Virtual Classes) | Define behavior contracts for modular and testable code |
| Abstract Classes | Share common behavior while enforcing method overrides |
| Dependency Injection | Decouple components for flexibility and testing |
| Composition over Inheritance | Prefer “HAS-A” relationships over “IS-A” when possible |
| Polymorphism | Dynamic dispatch through base class pointers/references |
| RAII & Smart Pointers | Automatic resource management using `unique_ptr` and `shared_ptr` |
| Thread Safety & Synchronization | Use of mutexes, condition variables, and thread-safe queues |
| Thread Pool Implementation | Reusable worker pool for parallel task execution |
| Unit Testing & Mock Objects | Test components in isolation using mocks |
| File I/O | Read/write operations with resource safety |


⸻

# Problems & Implementations

## 1. Notification System
- Demonstrates interfaces, dependency injection, polymorphism, and mock testing
- Supports Email, SMS, and Push notifications

## 2. Thread Pool
- Implements a fixed-size worker pool
- Supports task queue, condition variables, and safe shutdown

## 3. Thread-Safe Queue
- Generic blocking queue
- Handles multiple producers and consumers safely

## 4. File Reading & Writing Utility
- Reads/writes files safely using RAII principles
- Supports error handling and resource management

## 5. Other LLD Exercises
- Various abstract class vs interface designs
- Dependency injection patterns
- Mock objects for testing services

Each problem includes well-commented C++ code, explanations of OOP concepts used, and sometimes unit tests.

⸻

How to Run
	1.	Clone the repository:

git clone https://github.com/yourusername/lld-practice.git
cd lld-practice

	2.	Compile an example (e.g., Notification System):

g++ -std=c++17 notification_system.cpp -o notification_system
./notification_system

	3.	Run tests:

./notification_system   # includes mock/test functions

You can replace the file name with any problem you want to run.

⸻

Best Practices Followed
	•	Always use smart pointers for ownership (unique_ptr, shared_ptr)
	•	Virtual destructors for interface/base classes
	•	Explicit override keyword for all overridden virtual functions
	•	Scoped blocks for deterministic resource cleanup
	•	Clear separation of interface vs implementation
	•	Dependency Injection for flexibility and testability

⸻

License

This repository is for personal learning and practice.
Feel free to fork and use it for educational purposes.
