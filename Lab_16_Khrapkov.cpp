#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

using namespace std;


class File 
{
    wstring name;
    int size;
    wstring creationDate;
    int accessCount;

public:
    
    File(wstring n, int s, wstring d, int a) : name(n), size(s), creationDate(d), accessCount(a) {}

   
    void setName(wstring n) { name = n; }
    void setSize(int s) { size = s; }
    void setCreationDate(wstring d) { creationDate = d; }
    void setAccessCount(int a) { accessCount = a; }

   
    wstring getName() const { return name; }
    int getSize() const { return size; }
    wstring getCreationDate() const { return creationDate; }
    int getAccessCount() const { return accessCount; }

   
    void show() const 
    {
        wcout << L"Назва: " << name << L", Розмір: " << size << L" KB, Дата створення: " << creationDate << L", Кількість звернень: " << accessCount << endl;
    }
};


void sortByName(vector<File>& files) 
{
    sort(files.begin(), files.end(), [](const File& a, const File& b)
        {
        return a.getName() < b.getName();
        });
}


void showFilesBySize(const vector<File>& files, int minSize) 
{
    for (const auto& file : files) 
    {
        if (file.getSize() > minSize) 
        {
            file.show();
        }
    }
}


void showFilesByAccessCount(const vector<File>& files, int accessLimit)
{
    for (const auto& file : files)
    {
        if (file.getAccessCount() > accessLimit)
        {
            file.show();
        }
    }
}

int main() 
{
    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);

    vector<File> files = 
    {
        File(L"звіт.docx", 120, L"2024-05-01", 10),
        File(L"фото.jpg", 2500, L"2024-04-20", 5),
        File(L"презентація.pptx", 3000, L"2024-05-05", 20),
        File(L"дані.xlsx", 500, L"2024-03-15", 15),
        File(L"музика.mp3", 4000, L"2024-05-10", 25)
    };

    wcout << L"Список файлів:" << endl;
    for (const auto& file : files) 
    {
        file.show();
    }

    
    sortByName(files);
    wcout << L"\nСписок файлів, відсортований за назвою:" << endl;
    for (const auto& file : files)
    {
        file.show();
    }

   
    int minSize = 1000;
    wcout << L"\nФайли, розмір яких більше " << minSize << L" KB:" << endl;
    showFilesBySize(files, minSize);

    
    int accessLimit = 10;
    wcout << L"\nФайли, кількість звернень до яких більше " << accessLimit << L":" << endl;
    showFilesByAccessCount(files, accessLimit);

    return 0;
}
