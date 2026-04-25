#ifndef PALINDROME_LOGIC_H
#define PALINDROME_LOGIC_H

#include <QString>

class Palindrome_Logic
{
public:
    Palindrome_Logic();
    bool testPalindrome(const QString &input);

private:
    QString cleanString(const QString &input);
};

#endif