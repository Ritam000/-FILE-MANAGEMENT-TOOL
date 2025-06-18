# FILE-MANAGEMENT-TOOL

*COMPANY NAME*: CODTECH IT SOLUTIONS

*NAME*: RITAM KUNDU

*INTERN ID*: CT04DN1212

*DOMAIN*: C++ Programming

*DURATION*: 4 WEEKS

*MENTOR*: Neela Santhosh

The provided C++ program is a simple yet practical implementation of a console-based file management utility that demonstrates essential file handling operations such as writing, appending, and reading data from a text file. The program was developed using the Visual Studio Code (VS Code) editor, a modern, cross-platform, open-source code editor developed by Microsoft that is highly favored by developers due to its lightweight architecture, robust extension ecosystem, and deep integration with tools like Git and C++ toolchains. This program is built using the C++ Standard Template Library (STL), particularly relying on the <iostream>, <fstream>, and <string> headers. The <iostream> library is used for handling standard input and output operations via cin and cout, which allow the user to interact with the console; <fstream> is employed to manage file operations such as opening, writing to, reading from, and appending to files using file stream objects like ifstream (input file stream) and ofstream (output file stream); and <string> allows easy manipulation and storage of textual data. All these components are part of the ISO C++ standard libraries, making the program portable, efficient, and easy to maintain without requiring third-party dependencies.
In this particular implementation, a menu-driven interface is provided in a loop that continuously prompts the user until they choose to exit the program. The menu offers four choices: writing to the file (which overwrites existing content), appending new data to the file, reading the current contents of the file, and exiting the application. When the user chooses to write to the file, the program opens a file named data.txt using ofstream in default mode, which clears the file’s existing content. It then prompts the user to enter lines of text, which are written to the file until the user submits a blank line. In the case of appending, the file is opened using ofstream in append mode (ios::app), ensuring that any new input from the user is added at the end of the file without affecting previous content. For reading, the file is accessed via ifstream, and each line is read using getline() and printed to the console. Proper error handling is implemented in all cases to ensure that the program gracefully handles scenarios where the file cannot be opened due to issues such as missing permissions or non-existent files.
The development of this program in Visual Studio Code offers several advantages. VS Code supports C++ development via the Microsoft C/C++ extension, which provides features such as IntelliSense (code completion and parameter info), debugging, syntax highlighting, and easy navigation through symbols. With additional extensions like Code Runner, developers can quickly execute their code and view output directly within the integrated terminal. Furthermore, the cross-platform nature of both C++ and VS Code ensures that this program can be written and compiled on Windows, macOS, and Linux systems using standard compilers like GCC, Clang, or MSVC. This code serves as an excellent educational tool for beginners learning file I/O operations in C++ and is applicable in academic environments, coding labs, or for building foundational skills in systems programming. Additionally, the logic used here can be scaled to develop more complex applications, such as text editors, log management systems, or configuration utilities. Its simplicity, clarity, and modular structure make it a valuable reference for understanding how real-world data can be stored, retrieved, and manipulated using C++.


OUTPUT:

![Image](https://github.com/user-attachments/assets/2ca93d1b-194e-4e8a-90db-4b94f454fd8b)
