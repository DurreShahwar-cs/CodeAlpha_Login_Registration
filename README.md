# CodeAlpha Login and Registration System

A C++ console project that registers users in a local file and verifies login details.

## Features
- Register a username and password
- Reject duplicate usernames
- Basic password-length validation
- Save user records to `users.txt`
- Verify login credentials

## Compile and run
```bash
g++ main.cpp -o login
./login
```
On Windows PowerShell, run `.\login.exe` after compiling with `g++ main.cpp -o login.exe`.

## Security note
This is an educational demonstration only. It stores passwords as plain text, which is not suitable for real accounts. Production systems should use a reputable password-hashing library, secure storage, and additional protections. Do not use a real or reused password in this demo.
