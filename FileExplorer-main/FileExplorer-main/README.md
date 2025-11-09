:

🗂️ File Explorer – Capstone Project
🎯 Project Objective

The goal of this project is to design and implement a console-based File Explorer in C++17, allowing users to interact seamlessly with the operating system’s filesystem.
The application provides an intuitive command-line interface to perform essential file management operations such as navigating directories, creating/deleting files, copying, renaming, and retrieving file details.

This project serves as a practical demonstration of C++ filesystem operations and applies key concepts from the Linux Operating System module.

💡 Project Description

The File Explorer runs entirely in the terminal, offering a clean, text-based interface for file operations.
It leverages the <filesystem> library introduced in C++17, enabling robust handling of files and directories.
The system emphasizes simplicity and functionality — helping users efficiently explore folders, manage data, and extract metadata such as file size, type, and modification time.

⚙️ Key Features

✅ View files and directories in the current location
✅ Navigate through folders using cd and back commands
✅ Create, delete, rename, and copy files
✅ Search for files recursively by name
✅ Display detailed file information (size, permissions, last modified time)

🧭 Supported Commands
Command	Description
list	Displays files and folders in the current directory
cd <folder>	Opens the specified folder
back	Moves up one directory level
create <file>	Creates a new file
delete <file>	Deletes the specified file
rename <old> <new>	Renames a file or folder
copy <src> <dest>	Copies a file from source to destination
search <name>	Searches for a file by name (recursive)
info <file>	Displays detailed file information
exit	Exits the application

💻 Example Execution
> list
main.cpp
README.md
test.txt

> create data.txt
File created: data.txt

> info data.txt
Name: data.txt
Type: File
Size: 0 bytes
Last Modified: Sat Nov 08 22:41:18 2025
Permissions: rw-rw-rw-

🧩 Technologies Used

Language: C++17

Libraries: <filesystem>, <fstream>, <chrono>

Development Environment: Visual Studio Code

Compiler: MinGW (g++)

Platform Compatibility: Windows, Linux, and WSL

👨‍💻 Author

Surya Misra
Capstone Project – Linux OS Track
Department of Computer Science and Engineering