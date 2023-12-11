
## ( ON-GOING PROJECT )
**Title:** Simple Console-Based Authentication System

**Description:**

Simple Console-Based Authentication System , basic user authentication program implemented in C++. This console application allows users to register new accounts, securely store hashed passwords, and log in using a straightforward text file-based authentication mechanism.

**Key Features:**

1. **User Registration:** Users can register by providing a unique username and a password. The system uses the ***DJB2 hash function*** to securely hash passwords before storing them.

2. **Login Functionality:** Registered users can log in by entering their username and password. The system validates the entered credentials against the stored hashed passwords.

3. **Username Existence Check:** The system checks if a username already exists during the registration process, preventing the creation of duplicate accounts.

4. **Text File Storage:** User information, including usernames and hashed passwords, is stored in a text file (`passwd.txt`). The file format is clearly defined for ease of understanding.

5. **Menu-Driven Interface:** The application features a menu-driven interface that allows users to choose between registration, login, and program exit.
   (more to be added)

**Usage:**

1. **Registration:**
    - Users select the registration option, enter a unique username, and provide a password.
    - The system checks if the username already exists and, if not, securely stores the new user's information.

2. **Login:**
    - Registered users log in by entering their username and password.
    - The system verifies the entered credentials against the stored information, granting access upon successful validation.

3. **Menu Navigation:**
    - The user navigates through the program using a menu, choosing between registration, login, and program exit options.
---
### To do:
- logged in menu
- password change for logged in user
- account info with a class implementation
- integrate simple command-line applications ( simple calculator, Tic-Tac-Toe (X,O), ... )
---
**Note:**
- This project serves as a learning exercise and demonstrates fundamental concepts of authentication and C++ programming.

