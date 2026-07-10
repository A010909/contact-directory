# 📇 Terminal Contact Directory

A lightweight, persistent contact management system written in C. This project serves as a foundational exercise bridging the gap between basic syntax and applied computer science concepts, specifically memory management, data structures, and file I/O operations.

---

## 🏗️ Project Architecture & Application Flow

The application manages data dynamically in memory during runtime and will eventually persist it to a text-based database.

### 🔄 Execution Lifecycle

1. **Initialization:** Program starts and pointers are initialized (`root = NULL`).
2. **Load Data (Upcoming Phase):** Reads `contacts.txt`, parses the stored text, and rebuilds the linked list in memory.
3. **Interactive Menu Loop:**
   - Prompt user for choice (Add, View, Exit).
   - Capture input securely, stripping trailing newlines.
   - Execute corresponding linked-list operations.
4. **Save Data (Upcoming Phase):** Upon choosing "Exit", traverses the linked list and writes all node data back to `contacts.txt`.
5. **Memory Cleanup (Upcoming Phase):** Traverses the list one final time, calling `free()` on every node to return memory to the OS.

---

## 🗺️ Development Roadmap

The project is structured into sequential phases to isolate complexity and ensure stability at every level.

### ✅ Phase 1: Data Structures & Core Logic (Completed)

- [x] Define the `card` struct (Name, Phone, `*next` pointer).
- [x] Implement dynamic memory allocation (`malloc`) for new contact nodes.
- [x] Build traversal logic to append nodes safely to the end of the list.
- [x] Build traversal logic to read and display all nodes.

### ✅ Phase 2: User Interface & Input Sanitization (Completed)

- [x] Create an interactive `do-while` menu loop.
- [x] Implement secure string reading using `fgets()` instead of `scanf()`.
- [x] Sanitize strings by stripping newline characters (`strcspn`).
- [x] Prevent input buffer skipping by handling lingering carriage returns (`getchar()`).

### ⏳ Phase 3: Data Persistence (Next Step)

- [ ] Implement a `save_contacts()` function using `fopen("contacts.txt", "w")`.
- [ ] Traverse the linked list and write data sequentially using `fprintf()`.
- [ ] Implement a `load_contacts()` function using `fopen("contacts.txt", "r")`.
- [ ] Parse lines from the file, convert them to structs, and reconstruct the list on startup.

### ⏳ Phase 4: Memory Management & Advanced Features

- [ ] Implement `free_all_nodes()` to release heap memory before program termination (preventing memory leaks).
- [ ] **Bonus:** Add a "Search Contact" feature (linear search string comparison).
- [ ] **Bonus:** Add a "Delete Contact" feature (complex pointer reassignment).

---

## 📂 Recommended File Structure

While currently running as a single `main.c` file, the architecture should eventually evolve into a multi-file project for better maintainability:

```text
contacts_directory/
│
├── main.c           # Application entry point and UI loop
├── list_ops.c       # Implementations of create(), display(), free()
├── list_ops.h       # Struct definitions and function prototypes
├── file_io.c        # Implementations for saving and loading data
├── file_io.h        # File operations function prototypes
└── contacts.txt     # (Generated dynamically) The database file
```

## 🚀 Compilation & Execution

_(For the current single-file version)_

```bash
# Compile the program
gcc main.c -o contacts

# Run the executable
./contacts
```

README.md
Displaying README.md.
