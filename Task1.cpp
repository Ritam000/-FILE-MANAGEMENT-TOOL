#include <iostream>  // For input/output operations
#include <fstream>   // For file handling operations
#include <string>    // To use the string class
using namespace std; // Avoids prefixing std:: to standard library elements

int main()
{
    string filename = "data.txt"; // Name of the text file to read/write/append
    int choice;                   // Variable to store the user's menu choice

    // Menu loop
    do
    {
        // Display the menu
        cout << "\n--- FILE MANAGEMENT MENU ---\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Take the user's choice
        cin.ignore();  // Clear the newline character left in the input buffer

        if (choice == 1)
        {
            // Open the file in write (overwrite) mode
            ofstream file(filename);
            if (!file)
            { // Check if file opening failed
                cerr << "Error opening file for writing.\n";
                continue; // Skip rest of loop and prompt menu again
            }

            string content;
            cout << "Enter text to write (end with a blank line):\n";
            while (true)
            {
                getline(cin, content); // Read a line of input from the user
                if (content.empty())
                    break;               // Exit loop if user enters a blank line
                file << content << endl; // Write the line to the file
            }
            file.close(); // Close the file after writing
            cout << "File written successfully.\n";
        }
        else if (choice == 2)
        {
            // Open the file in append mode
            ofstream file(filename, ios::app);
            if (!file)
            { // Check if file opening failed
                cerr << "Error opening file for appending.\n";
                continue;
            }

            string content;
            cout << "Enter text to append (end with a blank line):\n";
            while (true)
            {
                getline(cin, content); // Read a line of input from the user
                if (content.empty())
                    break;               // Exit loop if user enters a blank line
                file << content << endl; // Append the line to the file
            }
            file.close(); // Close the file after appending
            cout << "File appended successfully.\n";
        }
        else if (choice == 3)
        {
            // Open the file for reading
            ifstream file(filename);
            if (!file)
            { // Check if file opening failed
                cerr << "Error opening file for reading.\n";
                continue;
            }

            cout << "\n--- File Contents ---\n";
            string line;
            while (getline(file, line))
            {                         // Read each line of the file
                cout << line << endl; // Print the line to the console
            }
            file.close(); // Close the file after reading
        }
        else if (choice == 4)
        {
            // Exit the program
            cout << "Exiting the program.\n";
        }
        else
        {
            // Invalid choice entered
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4); // Repeat menu until user chooses to exit

    return 0; // End of main function
}
