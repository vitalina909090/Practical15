#include <iostream>
#include <filesystem>
#include <fstream>
#include <Windows.h>

namespace fs = std::filesystem;
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    fs::path folderPath = "data_folder";
    if (!fs::exists(folderPath)) {
        fs::create_directory(folderPath);
        cout << "Папка " << folderPath << " создана\n";
    }
    else {
        cout << "Папка уже существует\n";
    }

    fs::path filePath = folderPath / "data.txt";
    ofstream file(filePath);
    if (file.is_open()) {
        file << "Учимся работать с файлами в C++!" << endl;
        file.close();
        cout << "Файл " << filePath << " создан и записан\n";
    }

    fs::path copyPath = folderPath / "data_copy.txt";
    fs::copy(filePath, copyPath, fs::copy_options::overwrite_existing);
    cout << "Файл скопирован в " << copyPath << "\n";

    if (fs::exists(folderPath)) {
        cout << "Папка " << folderPath << " существует\n";

        cout << "Содержимое папки " << folderPath << ":\n";
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            cout << "- " << entry.path().filename() << "\n";
        }
    }

    fs::remove(copyPath);
    cout << "Файл " << copyPath << " удален\n";

    fs::remove_all(folderPath);
    cout << "Папка " << folderPath << " удаленa\n";

    return 0;
}
