# 📇 Terminal Contact Directory

A contact management system written in C.

---

## 🏗️ Project Features

- [x] Create contact
- [ ] Delete Contact
- [x] Show all Contacts
- [ ] Search contact
- [ ] Favorites
- [ ] Sort by date, Sort by Alphabet (under planning)

### 🔄 Execution Lifecycle

1. **Initialization:** Program starts and pointers are initialized (`root = NULL`).
2. **Load Data (Upcoming Phase):** Reads `contacts.txt`, parses the stored text, and rebuilds the linked list in memory.
3. **Interactive Menu Loop:**
   - Prompt user for choice (Add, View, Exit).
   - Execute corresponding linked-list operations.
4. **Save Data (Upcoming Phase):** Upon choosing "Exit", traverses the linked list and writes all node data back to `contacts.txt`.
5. **Memory Cleanup (Upcoming Phase):** Traverses the list one final time, calling `free()` on every node to return memory to the OS.

---

## 🗺️ Development Roadmap

### ✅ Phase 1: Data Structures & Core Logic (Completed)

- [x] Define the `card` struct (Name, Phone, `*next` pointer).
- [x] Implement dynamic memory allocation (`malloc`) for new contact nodes.
- [x] Build traversal logic to append nodes safely to the end of the list.
- [x] Build traversal logic to read and display all nodes.

### ✅ Phase 2: User Interface (Completed)

- [x] Create an interactive `do-while` menu loop.
- [x] Implement secure string reading using `fgets()` instead of `scanf()`.

### ✅ Phase 3: Data Persistence (Next Step)

- [x] Implement a `save()` function
- [x] Traverse the linked list and write data sequentially
- [x] Implement a `load()` function using
- [x] Parse lines from the file, convert them to structs, and reconstruct the list on startup.
- [x] Create A Makefile to compile multiple files at one go.

### ⏳ Phase 4: Memory Management & Advanced Features

- [ ] Implement `free_all_nodes()` to release heap memory before program termination (preventing memory leaks).
- [ ] Add a "Search Contact" feature
- [ ] Add a "Delete Contact" feature
- [ ] Add a "Sort" feature

---

## ✅ Points to keep in check

- [x] **User Experience:** The list of contacts will be shown at very first when starting the programme, then the other features will be shoen as an option.
- [x] **First time running:** Will create a file automatically to store the data in the root directory and the user will not have any interactions to do with this file.

---

## 📂 Recommended File Structure

While currently running as a single `main.c` file, the architecture should eventually evolve into a multi-file project for better maintainability:

```text
contacts_directory/
│
├── main.c           # Application entry point and UI loop ✅
├── list_ops.c       # Implementations of create(), display(), free() ✅
├── list_ops.h       # Struct definitions and function prototypes ✅
├── Makefile         # Compile multiple files at once ✅
├── README.md        # Documentation ✅
└── contacts.txt     # (Generated dynamically) The database file ✅
```

## 🚀 Final Note

Currently it is in development phase so it may not meet up to its readme documents but it eventually will. 🙏
