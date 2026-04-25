#ifndef PALINDROME_LOGIC_H
#define PALINDROME_LOGIC_H

#include <QString>
#include <QDebug>

// 前置声明
class Palindrome_Logic;

void reportStatus(const Palindrome_Logic &logic);

class StringCleaner {
public:
    QString operator()(const QString &input);
};

class Palindrome_Logic
{
public:
    Palindrome_Logic(const QString &input);

    bool testPalindrome();
    int getCheckCount() const;

    friend void reportStatus(const Palindrome_Logic &logic);

private:
    QString cleanString(const QString &input);
    QString m_storedInput;
};

#endif