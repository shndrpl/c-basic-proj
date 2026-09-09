# Contact Manager

A simple command-line contact manager written in C.

## Practice Project

This project is **for practice and learning only**. It was built to practice fundamental C programming concepts, particularly:

* Header files
* File I/O
* Dynamic memory allocation
* Linked lists
* Hash tables

The goal of the project is to understand how these concepts work together in a small C program rather than to create a production-ready contact management system.

## Features

* Add contacts
* Search contacts
* Edit contacts
* Delete contacts
* Save contacts to a text file
* Load contacts into memory

Each contact contains:

* Name
* Phone
* Address
* Email

## Main Concepts

### Header File

`customLib.h` contains the `node` structure, function declarations, and the hash table size used by the program.

### Linked List

Each contact is represented by a dynamically allocated `node`. Nodes are connected using a `next` pointer.

### Hash Table

The program uses an array of 26 buckets. Contacts are placed into a bucket based on the first character of their name. Each bucket contains a linked list to handle multiple contacts.

### File I/O

Contacts are stored in `credentials.txt` and loaded into memory when the program starts. New contacts are appended to the file.

## Menu

```text
[0] - Exit
[1] - Add Contact
[2] - Search Contact
[3] - Edit Contact
[4] - Delete Contact
```

## Project Structure

```text
.
├── main.c
├── modes.c
├── fileIO.c
├── customLib.h
└── credentials.txt
```

## Purpose

This is a **learning/practice project** focused mainly on understanding C header files, file I/O, linked lists, hash tables, and dynamic memory management.
