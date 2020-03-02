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
    cout << TestTask::isEqualCodeAndNumber("D2 25", "D225")   << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("D2025", "D225")   << "\n-----\n\n";
    cout << TestTask::isEqualCodeAndNumber("MD 1234", "1234") << "\n-----\n\n";

    return 0;
}

// -----------------------------------------------------------------------------
// �������� ������� ���������
// -----------------------------------------------------------------------------
bool TestTask::isEqualCodeAndNumber (std::string str1, std::string str2) {

//    cout << "str 1: " << str1 << endl
//         << "str 2: " << str2 << endl
//         << endl;

    // ���� ����� ���� �� ����� �� ����� ������ 7, �������
    if ((str1.size() > TestTask::STR_LENGTH)
       || (str1.size() > TestTask::STR_LENGTH)) {
        return false;
    }

    // ���� ���� �� ���� �� ����� ������, �������
    if ((str1.size() < 1) || (str1.size() < 1)) {
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

    // ���� �� ����� �� ����������� ��� � �����, �������
    if (! isStringsEqual(strCode1, strCode2) || ! isStringsEqual(str1, str2)) {
        return false;
    }

    return true;
}

// -----------------------------------------------------------------------------
// ���������, ����� �� ������
// -----------------------------------------------------------------------------
bool TestTask::isStringsEqual (std::string str1, std::string str2) {
    // ���� ������� �� ���������, ������ ����� �� ����� - �������
    if (str1.size() != str2.size()) {
        return false;
    }

    // ����������� ���������� ������ (�� ��������� ������� - �������)
    for (std::string::iterator i1 = str1.begin(), i2 = str2.begin();
            i1 < str1.end(); ++i1, ++i2) {
        if (*i1 != *i2) {
            return false;
        }
    }

    return true;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// ��������� ������ �� ��� � ����� �����
// -----------------------------------------------------------------------------
void TestTask::getCodeAndNumber (std::string &str, std::string &strCode) {

    std::ostringstream code;

    // ��������� �������� �����:

    // ��� ���� AAA (��� �����)
    if (isLetter(str[0]) && isLetter(str[1]) && isLetter(str[2])) {
        code << str[0] << str[1] << str[2];
        str.erase(0, 3);
    }

    else
    if (  (isNumber(str[0]) && isLetter(str[1]))  // ��� ���� 1A
       || (isLetter(str[0]) && isNumber(str[1]))  // ��� ���� A1
       || (isLetter(str[0]) && isLetter(str[1]))  // ��� ���� AA
    ) {
        code << str[0] << str[1];
        str.erase(0, 2);
    }

    strCode = code.str();

    // ������� ������� � ���������� ���� � ������ �����
    while (*(str.begin()) == ' ' || *(str.begin()) == '0') {
        str.erase(str.begin());
    }
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// ��������, �������� �� ������ ������
// -----------------------------------------------------------------------------
bool TestTask::isLetter (char symbol) {
    for (int i = 0; i < TestTask::LETTERS_COUNT; ++i) {
        if (symbol == TestTask::letters[i]) {
            return true;
        }
    }

    // �� ����� ������������ ����� ��������
    return false;
}
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// ��������, �������� �� ������ ������
// -----------------------------------------------------------------------------
bool TestTask::isNumber (char symbol) {
    for (int i = 0; i < TestTask::NUMBERS_COUNT; ++i) {
        if (symbol == TestTask::numbers[i]) {
            return true;
        }
    }

    // �� ����� ������������ ����� ��������
    return false;
}
// -----------------------------------------------------------------------------

