#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string USERS_FILE = "users.txt";

// This is a simple learning demo. Plain-text passwords are NOT secure.
// Real applications should use a vetted password-hashing library.

bool usernameExists(const string& username) {
    ifstream file(USERS_FILE);
    string savedUser, savedPassword;
    while (file >> savedUser >> savedPassword) {
        if (savedUser == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Choose a username (no spaces): ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "That username is already registered.\n";
        return;
    }

    cout << "Choose a password (no spaces): ";
    cin >> password;

    if (password.length() < 6) {
        cout << "Password must be at least 6 characters long.\n";
        return;
    }

    ofstream file(USERS_FILE, ios::app);
    if (!file) {
        cout << "Could not open the user file. Check folder permissions.\n";
        return;
    }
    file << username << ' ' << password << '\n';
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, savedUser, savedPassword;
    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file(USERS_FILE);
    while (file >> savedUser >> savedPassword) {
        if (savedUser == username && savedPassword == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return;
        }
    }
    cout << "Login failed: username or password is incorrect.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====================================\n";
        cout << "  CODEALPHA LOGIN & REGISTRATION\n";
        cout << "====================================\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";

        if (!(cin >> choice)) {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Select 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
