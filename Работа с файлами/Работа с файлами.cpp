// Работа с файлами.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

void compareFiles(const char* str1, const char* str2) {
    const char* path1 = "text1.txt";
    const char* path2 = "text2.txt";
    FILE* file1;
    FILE* file2;

    
    if (fopen_s(&file1, path1, "w")) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << path1 << std::endl;
        return;
    }

    if (fopen_s(&file2, path2, "w")) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << path2 << std::endl;
        fclose(file1);
        return;
    }

    
    fputs(str1, file1);
    fputs(str2, file2);

    
    fclose(file1);
    fclose(file2);

    
    if (fopen_s(&file1, path1, "r")) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << path1 << std::endl;
        return;
    }

    if (fopen_s(&file2, path2, "r")) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << path2 << std::endl;
        fclose(file1);
        return;
    }

    char line1[256];
    char line2[256];
    int lineNumber = 1;

    
    while (fgets(line1, sizeof(line1), file1) && fgets(line2, sizeof(line2), file2)) {
        
        line1[strcspn(line1, "\n")] = '\0';
        line2[strcspn(line2, "\n")] = '\0';

        if (strcmp(line1, line2) != 0) {
            std::cout << "Несовпадение в строке " << lineNumber << ":" << std::endl;
            std::cout << "Файл 1: " << line1 << std::endl;
            std::cout << "Файл 2: " << line2 << std::endl;
        }
        lineNumber++;
    }

    
    while (fgets(line1, sizeof(line1), file1)) {
        line1[strcspn(line1, "\n")] = '\0';
        std::cout << "Файл 1 имеет дополнительную строку " << lineNumber << ": " << line1 << std::endl;
        lineNumber++;
    }

    while (fgets(line2, sizeof(line2), file2)) {
        line2[strcspn(line2, "\n")] = '\0';
        std::cout << "Файл 2 имеет дополнительную строку " << lineNumber << ": " << line2 << std::endl;
        lineNumber++;
    }

    
    fclose(file1);
    fclose(file2);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = text;
    shift = shift % 26; // 

    for (size_t i = 0; i < text.size(); ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            result[i] = base + (text[i] - base + shift) % 26;
        }
    }


    return result;
}


int main()
{
 
    setlocale(LC_ALL, "Ru");
   /* const char* str1 = "Привет\nКак дела?\nДо свидания";
    const char* str2 = "Привет\nКак вы?\nДо свидания";

    compareFiles(str1, str2);*/

    
   


    /*------------------------------------------------------------------------------------------------------------------*/

    /*std::string text;
    int shift;

    std::cout << "Введите текст для шифрования: ";
    std::getline(std::cin, text);

    std::cout << "Введите позицию: ";
    std::cin >> shift;

    std::string encryptedText = caesarCipher(text, shift);

    std::ofstream outFile("encrypted_text.txt");
    if (outFile.is_open()) {
        outFile << encryptedText;
        outFile.close();
        std::cout << "Зашифрованный текст записан в файл 'encrypted_text.txt'" << std::endl;
    }
    else {
        std::cerr << "Невозможно открыть файл для записи" << std::endl;
    }*/
/*----------------------------------------------------------------------------------------------------------------------------------*/

    /*3 задание скину в следующем файле*/


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
