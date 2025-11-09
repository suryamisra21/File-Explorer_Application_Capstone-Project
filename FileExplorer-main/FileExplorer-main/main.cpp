#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
namespace fs = std::filesystem;

string formatTime(const fs::file_time_type &ftime) {
    auto sctp = chrono::time_point_cast<chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + chrono::system_clock::now());
    time_t tt = chrono::system_clock::to_time_t(sctp);
    string timeStr = ctime(&tt);
    timeStr.pop_back();
    return timeStr;
}

string getPermissions(const fs::perms p) {
    string perm;
    perm += ((p & fs::perms::owner_read) != fs::perms::none) ? "r" : "-";
    perm += ((p & fs::perms::owner_write) != fs::perms::none) ? "w" : "-";
    perm += ((p & fs::perms::owner_exec) != fs::perms::none) ? "x" : "-";
    perm += ((p & fs::perms::group_read) != fs::perms::none) ? "r" : "-";
    perm += ((p & fs::perms::group_write) != fs::perms::none) ? "w" : "-";
    perm += ((p & fs::perms::group_exec) != fs::perms::none) ? "x" : "-";
    perm += ((p & fs::perms::others_read) != fs::perms::none) ? "r" : "-";
    perm += ((p & fs::perms::others_write) != fs::perms::none) ? "w" : "-";
    perm += ((p & fs::perms::others_exec) != fs::perms::none) ? "x" : "-";
    return perm;
}

void showFileInfo(const fs::path &path, const string &filename) {
    fs::path filePath = path / filename;
    if (!fs::exists(filePath)) {
        cout << "File not found: " << filename << endl;
        return;
    }
    cout << "\n--- File Information ---" << endl;
    cout << "Name: " << filePath.filename().string() << endl;
    cout << "Path: " << fs::absolute(filePath) << endl;
    cout << "Type: " << (fs::is_directory(filePath) ? "Directory" : "File") << endl;
    cout << "Size: " << fs::file_size(filePath) << " bytes" << endl;
    cout << "Last Modified: " << formatTime(fs::last_write_time(filePath)) << endl;
    cout << "Permissions: " << getPermissions(fs::status(filePath).permissions()) << endl;
    cout << "--------------------------\n";
}

void listFiles(const fs::path &path) {
    cout << "\nDirectory: " << fs::absolute(path) << endl;
    cout << "-----------------------------------------" << endl;
    for (const auto &entry : fs::directory_iterator(path)) {
        cout << entry.path().filename().string();
        if (fs::is_directory(entry)) cout << " [DIR]";
        cout << endl;
    }
}

void createFile(const fs::path &path, const string &filename) {
    ofstream file(path / filename);
    if (file) cout << "File created: " << filename << endl;
}
void deleteFile(const fs::path &path, const string &filename) {
    if (fs::exists(path / filename)) {
        fs::remove(path / filename);
        cout << "Deleted: " << filename << endl;
    } else cout << "File not found.\n";
}
void renameFile(const fs::path &path, const string &oldName, const string &newName) {
    fs::path oldP = path / oldName, newP = path / newName;
    if (fs::exists(oldP)) {
        fs::rename(oldP, newP);
        cout << "Renamed " << oldName << " -> " << newName << endl;
    } else cout << "File not found.\n";
}
void copyFile(const fs::path &path, const string &src, const string &dest) {
    fs::path srcP = path / src, destP = path / dest;
    if (fs::exists(srcP)) {
        fs::copy_file(srcP, destP, fs::copy_options::overwrite_existing);
        cout << "Copied " << src << " -> " << dest << endl;
    } else cout << "File not found.\n";
}
void searchFiles(const fs::path &path, const string &keyword) {
    cout << "\nSearching for: " << keyword << endl;
    cout << "-----------------------------------------" << endl;
    bool found = false;
    for (const auto &entry : fs::recursive_directory_iterator(path)) {
        string name = entry.path().filename().string();
        if (name.find(keyword) != string::npos) {
            cout << entry.path() << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}

int main() {
    fs::path currentPath = ".";
    string input;

    cout << "=== File Explorer (Final Version) ===" << endl;
    cout << "Commands:\n"
         << "cd <folder>, back, list, exit\n"
         << "create <file>, delete <file>, rename <old> <new>, copy <src> <dest>\n"
         << "search <name>, info <file>\n";

    while (true) {
        cout << "\n> ";
        getline(cin, input);

        if (input == "exit") break;
        else if (input == "list") listFiles(currentPath);
        else if (input == "back") {
            if (currentPath.has_parent_path()) currentPath = currentPath.parent_path();
            else cout << "Already at root.\n";
        }
        else if (input.rfind("cd ", 0) == 0) {
            fs::path newPath = currentPath / input.substr(3);
            if (fs::exists(newPath) && fs::is_directory(newPath))
                currentPath = newPath;
            else
                cout << "Directory not found.\n";
        }
        else if (input.rfind("create ", 0) == 0) createFile(currentPath, input.substr(7));
        else if (input.rfind("delete ", 0) == 0) deleteFile(currentPath, input.substr(7));
        else if (input.rfind("rename ", 0) == 0) {
            size_t sp = input.find(' ', 7);
            if (sp != string::npos)
                renameFile(currentPath, input.substr(7, sp - 7), input.substr(sp + 1));
            else cout << "Usage: rename <old> <new>\n";
        }
        else if (input.rfind("copy ", 0) == 0) {
            size_t sp = input.find(' ', 5);
            if (sp != string::npos)
                copyFile(currentPath, input.substr(5, sp - 5), input.substr(sp + 1));
            else cout << "Usage: copy <src> <dest>\n";
        }
        else if (input.rfind("search ", 0) == 0) searchFiles(currentPath, input.substr(7));
        else if (input.rfind("info ", 0) == 0) showFileInfo(currentPath, input.substr(5));
        else cout << "Unknown command. Try 'list' to see files.\n";
    }

    cout << "Exiting File Explorer...\n";
    return 0;
}
