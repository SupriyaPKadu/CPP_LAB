/*Q.No 1. Bookshop Management System
File handling has been effectively used for each feature of this project
Operations
1. Add Book Records:
2. Show Book Records:
3. Check Availability:
4. Modify Book Records:
5. Delete Book Records: */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int quantity;

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << ", Quantity: " << quantity << endl;
    }
};

void addBook();
void showBooks();
void checkAvailability();
void modifyBook();
void deleteBook();

int main() {
    int choice;
    do {
        cout << "\nBookshop Management System\n";
        cout << "1. Add Book Records\n";
        cout << "2. Show Book Records\n";
        cout << "3. Check Availability\n";
        cout << "4. Modify Book Records\n";
        cout << "5. Delete Book Records\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: checkAvailability(); break;
            case 4: modifyBook(); break;
            case 5: deleteBook(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void addBook() {
    ofstream outFile("books.txt", ios::app);
    Book book;
    cout << "Enter Book ID: ";
    cin >> book.id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, book.title);
    cout << "Enter Author Name: ";
    getline(cin, book.author);
    cout << "Enter Quantity: ";
    cin >> book.quantity;

    outFile << book.id << endl;
    outFile << book.title << endl;
    outFile << book.author << endl;
    outFile << book.quantity << endl;
    outFile.close();
    cout << "Book added successfully!\n";
}

void showBooks() {
    ifstream inFile("books.txt");
    Book book;
    cout << "\nBook Records:\n";
    while (inFile >> book.id) {
        inFile.ignore();
        getline(inFile, book.title);
        getline(inFile, book.author);
        inFile >> book.quantity;
        inFile.ignore();
        book.display();
    }
    inFile.close();
}

void checkAvailability() {
    ifstream inFile("books.txt");
    Book book;
    int id;
    cout << "Enter Book ID to check availability: ";
    cin >> id;

    bool found = false;
    while (inFile >> book.id) {
        inFile.ignore();
        getline(inFile, book.title);
        getline(inFile, book.author);
        inFile >> book.quantity;
        inFile.ignore();
        
        if (book.id == id) {
            found = true;
            cout << "Book is available. Quantity: " << book.quantity << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!\n";
    }
    inFile.close();
}

void modifyBook() {
    fstream file("books.txt", ios::in | ios::out);
    Book book;
    int id, pos = -1;

    cout << "Enter Book ID to modify: ";
    cin >> id;

    while (file >> book.id) {
        file.ignore();
        getline(file, book.title);
        getline(file, book.author);
        file >> book.quantity;
        file.ignore();

        if (book.id == id) {
            pos = file.tellg();
            cout << "Enter new Title: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Enter new Author: ";
            getline(cin, book.author);
            cout << "Enter new Quantity: ";
            cin >> book.quantity;

            file.seekp(pos - sizeof(Book) * 3);
            file << book.id << endl;
            file << book.title << endl;
            file << book.author << endl;
            file << book.quantity << endl;
            cout << "Book modified successfully!\n";
            break;
        }
    }
    if (pos == -1) {
        cout << "Book not found!\n";
    }
    file.close();
}

void deleteBook() {
    ifstream inFile("books.txt");
    ofstream outFile("temp.txt");
    Book book;
    int id;

    cout << "Enter Book ID to delete: ";
    cin >> id;

    bool found = false;
    while (inFile >> book.id) {
        inFile.ignore();
        getline(inFile, book.title);
        getline(inFile, book.author);
        inFile >> book.quantity;
        inFile.ignore();

        if (book.id == id) {
            found = true;
            cout << "Book deleted successfully!\n";
            continue;
        }
        outFile << book.id << endl;
        outFile << book.title << endl;
        outFile << book.author << endl;
        outFile << book.quantity << endl;
    }
    if (!found) {
        cout << "Book not found!\n";
    }

    inFile.close();
    outFile.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");
}
















































































































































































































































