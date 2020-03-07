#include <iostream>
#include <sstream>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::endl;

namespace TestTask {
    const unsigned int STR_LENGTH = 7;

    bool isEqualCodeAndNumber (std::string &str1, std::string &str2);
    void getCodeAndNumber (std::string &str, std::string &strCode);
    bool isStringsEqual (std::string &str1, std::string &str2);
    bool isLetter (char symbol);
    bool isNumber (char symbol);
}

// -----------------------------------------------------------------------------
// Main в данной программе играет роль теста - запускает основую функцию с разными вариантами строк
// -----------------------------------------------------------------------------
int main (int argc, char *argv []) {

    const int TEST_COUNT = 5;

    std::string testStr1[TEST_COUNT] = {"AFL1",    "D2 25", "D2 25", "D225",  "MD 1234"};
    std::string testStr2[TEST_COUNT] = {"AFL0001", "D2025", "D225",  "D2025", "1234"   };

    for (int i = 0; i < TEST_COUNT; ++i) {
        cout << "str 1: " << testStr1[i] << endl
             << "str 2: " << testStr2[i] << endl
             << endl;

        cout << TestTask::isEqualCodeAndNumber(testStr1[i], testStr2[i]) << "\n\n-----\n\n";
    }

    return 0;
}

// -----------------------------------------------------------------------------
// Основная функция сравнения
// -----------------------------------------------------------------------------
bool TestTask::isEqualCodeAndNumber (std::string &str1, std::string &str2) {

    // Если длина хотя бы одной из строк больше 7, выходим
    if ((str1.size() > TestTask::STR_LENGTH)
       || (str2.size() > TestTask::STR_LENGTH)) {
        return false;
    }

    // Если хотя бы одна из строк пустая, выходим
    if (str1.empty() || str2.empty()) {
        return false;
    }

    std::string strCode1;
    std::string strCode2;

    getCodeAndNumber (str1, strCode1);
    getCodeAndNumber (str2, strCode2);

//    cout << "code 1: " << strCode1 << endl
//         << "code 2: " << strCode2 << endl
//         << endl;
//
//    cout << "number 1: " << str1 << endl
//         << "number 2: " << str2 << endl
//         << endl;
//
//    cout << "codes: " << isStringsEqual(strCode1, strCode2) << endl
//         << "numbers: " << isStringsEqual(str1, str2) << endl
//         << endl;

    // Если не равны по отдельности код и номер, выходим
    if (! isStringsEqual(strCode1, strCode2) || ! isStringsEqual(str1, str2)) {
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// Проверяем, равны ли строки
// -----------------------------------------------------------------------------
bool TestTask::isStringsEqual (std::string &str1, std::string &str2) {
    // Если размеры не совпадают, строки точно не равны - выходим
    if (str1.size() != str2.size()) {
        return false;
    }

    // Поэлементно сравниваем строки
    if (! strcmp(str1.c_str(), str2.c_str())) {
        return true;
    }
    else return false;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Разделяем строку на код и номер рейса
// -----------------------------------------------------------------------------
void TestTask::getCodeAndNumber (std::string &str, std::string &strCode) {

    std::ostringstream code;

    // Разбираем варианты кодов:

    // код вида AAA (три буквы)
    if (isLetter(str[0]) && isLetter(str[1]) && isLetter(str[2])) {
        code << str[0] << str[1] << str[2];
        str.erase(0, 3);
    }

    else
    if (  (isNumber(str[0]) && isLetter(str[1]))  // код вида 1A
       || (isLetter(str[0]) && isNumber(str[1]))  // код вида A1
       || (isLetter(str[0]) && isLetter(str[1]))  // код вида AA
    ) {
        code << str[0] << str[1];
        str.erase(0, 2);
    }

    strCode = code.str();

    // Убираем пробелы и лидирующие нули в номере рейса
    while (*(str.begin()) == ' ' || *(str.begin()) == '0') {
        str.erase(str.begin());
    }
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Проверка, является ли символ буквой
// -----------------------------------------------------------------------------
bool TestTask::isLetter (char symbol) {
    if ((symbol >= 'A') && (symbol <= 'Z')) {
        return true;
    }

    // Не нашли соответствие среди символов
    return false;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Проверка, является ли символ числом
// -----------------------------------------------------------------------------
bool TestTask::isNumber (char symbol) {
    if ((symbol >= '0') && (symbol <= '9')) {
        return true;
    }

    // Не нашли соответствие среди символов
    return false;
}
// -----------------------------------------------------------------------------

