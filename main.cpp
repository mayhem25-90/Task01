#include <iostream>
#include <sstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::endl;

namespace TestTask {
    const unsigned int STR_LENGTH = 7;

    const unsigned int LETTERS_COUNT = 26 + 1;
    char letters[LETTERS_COUNT] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const unsigned int NUMBERS_COUNT = 10 + 1;
    char numbers[NUMBERS_COUNT] = "0123456789";


    bool isEqualCodeAndNumber (std::string str1, std::string str2);
    void getCodeAndNumber (std::string &str, std::string &strCode);
    bool isStringsEqual (std::string str1, std::string str2);
    bool isLetter (char symbol);
    bool isNumber (char symbol);
}


int main (int argc, char *argv []) {

    cout << TestTask::isEqualCodeAndNumber("AFL1", "AFL0001") << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("D2 25", "D2025")  << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("D2 25", "D225")  << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("D2025", "D225")  << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("MD 1234", "1234")  << "\n-----\n\n";

    return 0;
}

// -----------------------------------------------------------------------------
// Основная функция сравнения
// -----------------------------------------------------------------------------
bool TestTask::isEqualCodeAndNumber (std::string str1, std::string str2) {

cout << "str 1: " << str1 << endl
     << "str 2: " << str2 << endl
     << endl;

    // Если длина хотя бы одной из строк больше 7, выходим
    if ((str1.size() > TestTask::STR_LENGTH)
       || (str1.size() > TestTask::STR_LENGTH)) {
        return false;
    }

    // Если хотя бы одна из строк пустая, выходим
    if ((str1.size() < 1) || (str1.size() < 1)) {
        return false;
    }

    std::string strCode1;
    std::string strCode2;

    getCodeAndNumber (str1, strCode1);
    getCodeAndNumber (str2, strCode2);

cout << "code 1: " << strCode1 << endl
     << "code 2: " << strCode2 << endl
     << endl;

cout << "number 1: " << str1 << endl
     << "number 2: " << str2 << endl
     << endl;

cout << "codes: " << isStringsEqual(strCode1, strCode2) << endl
     << "numbers: " << isStringsEqual(str1, str2) << endl
     << endl;

    // Если не равны по отдельности код и номер, выходим
    if (! isStringsEqual(strCode1, strCode2) || ! isStringsEqual(str1, str2)) {
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// Проверяем, равны ли строки
// -----------------------------------------------------------------------------
bool TestTask::isStringsEqual (std::string str1, std::string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    for (unsigned i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Разделяем строку на код и номер рейса
// -----------------------------------------------------------------------------
void TestTask::getCodeAndNumber (std::string &str, std::string &strCode) {

    std::ostringstream code;

    if (isNumber(str[0]) && isLetter(str[1])) {
        code << str[0] << str[1];
        str.erase(0, 2);
    }

    if (isLetter(str[0])) {
        if (isNumber(str[1])) {
            code << str[0] << str[1];
            str.erase(0, 2);
        }

        if (isLetter(str[1])) {
            if (isLetter(str[2])) {
                code << str[0] << str[1] << str[2];
                str.erase(0, 3);
            }
            else {
                code << str[0] << str[1];
                str.erase(0, 2);
            }
        }
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
    for (int i = 0; i < TestTask::LETTERS_COUNT; ++i) {
        if (symbol == TestTask::letters[i]) {
            return true;
        }
    }

    // Не нашли соответствие среди символов
    return false;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Проверка, является ли символ числом
// -----------------------------------------------------------------------------
bool TestTask::isNumber (char symbol) {
    for (int i = 0; i < TestTask::NUMBERS_COUNT; ++i) {
        if (symbol == TestTask::numbers[i]) {
            return true;
        }
    }

    // Не нашли соответствие среди символов
    return false;
}
// -----------------------------------------------------------------------------

