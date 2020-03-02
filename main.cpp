#include <iostream>
#include <sstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::cout;
using std::endl;

namespace testTask {
    const unsigned int STR_LENGTH = 7;

    const unsigned int LETTERS_COUNT = 26 + 1;
    char letters[LETTERS_COUNT] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const unsigned int NUMBERS_COUNT = 10 + 1;
    char numbers[NUMBERS_COUNT] = "0123456789";
}

bool isEqualCodeAndNumber (std::string str1, std::string str2);
void getCodeAndNumber (std::string &str, std::string &strCode);
bool isLetter (char symbol);
bool isNumber (char symbol);
bool isEqual (std::string str1, std::string str2);


int main (int argc, char *argv []) {

    bool t = isEqualCodeAndNumber("AFL1", "AFL11111");

    cout << t << endl;

    return 0;
}

bool isEqualCodeAndNumber (std::string str1, std::string str2) {
//    cout << "s1 sz " << str1.size() << endl;
//    cout << "s2 sz " << str2.size() << endl;

    // Если длина хотя бы одной из строк больше 7, выходим
    if ((str1.size() > testTask::STR_LENGTH) || (str1.size() > testTask::STR_LENGTH)) {
        return false;
    }

    // Если хотя бы одна из строк пустая, выходим
    if ((str1.size() < 1) || (str1.size() < 1)) {
        return false;
    }


    std::string strCode1;
//    std::string strNumber1;
    std::string strCode2;
//    std::string strNumber2;

    getCodeAndNumber (str1, strCode1);
    getCodeAndNumber (str2, strCode2);

cout << "code 1: " << strCode1 << endl
     << "code 2: " << strCode2 << endl
     << endl;

cout << "number 1: " << str1 << endl
     << "number 2: " << str2 << endl
     << endl;

    // Находим размеры большей и меньшей строк
    unsigned maxLength = (str1.size() > str2.size()) ? str1.size() : str2.size();
//    unsigned minLength = (str1.size() < str2.size()) ? str1.size() : str2.size();

    // Итератор для 2й строки
//    unsigned j = 0;

    // Проходим по большей строке
//    for (unsigned i = 0; i < STR_LENGTH; ++i) {
    for (unsigned i = 0, j = 0; ((i < maxLength) || (j < maxLength));) {

cout << "s1 "<<str1[i]<< "; s2 "<<str2[i]<<endl;

        // Сравниваем символы
        if (str1[i] != str2[j]) {
            return false;
        }

        if (i < str1.size() - 1) {
            ++i;
        }
//        else return false;


        ++i;
        ++j;

//        if (j < minLength) {
//            ++j;
//        }
//        else return false;

        // Пока длины строк позволяют...
//        if ((i < str1.size() && (i < str2.size()) {
//            //
//        }
    }

    return true;
}

//
bool isEqual (std::string str1, std::string str2) {
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

// Разделяем строку на код и номер
void getCodeAndNumber (std::string &str, std::string &strCode) {

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
}

// Проверка, является ли символ буквой
bool isLetter (char symbol) {
    for (int i = 0; i < testTask::LETTERS_COUNT; ++i) {
        if (symbol == testTask::letters[i]) {
            return true;
        }
    }

    // Не нашли соответствие среди символов
    return false;
}

// Проверка, является ли символ числом
bool isNumber (char symbol) {
    for (int i = 0; i < testTask::NUMBERS_COUNT; ++i) {
        if (symbol == testTask::numbers[i]) {
            return true;
        }
    }

    // Не нашли соответствие среди символов
    return false;
}

