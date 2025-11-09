🗂️ File Explorer – Capstone Project
🎯 Objective

This project implements a console-based File Explorer using C++17 that enables users to interact with the operating system’s filesystem through text commands.
It demonstrates practical file management operations and applies key concepts from the Linux Operating System module.

💡 Overview

The File Explorer runs entirely from the terminal and uses the <filesystem> library for directory and file operations.
It offers a simple yet powerful interface to explore folders, create or remove files, and access metadata such as size, permissions, and modification time.

⚙️ Features

📁 View files and directories in the current location

🚀 Navigate using cd and back commands

✏️ Create, delete, rename, and copy files

🔍 Search for files recursively by name

ℹ️ Display detailed file information (size, permissions, modification date)

🧭 Available Commands
Command	Description
list	Lists files and folders in the current directory
cd <folder>	Enters the specified folder
back	Goes back to the previous directory
create <file>	Creates a new file
delete <file>	Deletes the specified file
rename <old> <new>	Renames a file or folder
copy <src> <dest>	Copies a file to the destination
search <name>	Searches for a file by name (recursive)
info <file>	Shows detailed file information
exit	Closes the application
💻 Example Usage
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

IDE: Visual Studio Code

Compiler: MinGW (g++)

Supported Platforms: Windows, Linux, and WSL

👨‍💻 Author

Surya Misra
Capstone Project – Linux OS Track
Department of Computer Science and Engineering
