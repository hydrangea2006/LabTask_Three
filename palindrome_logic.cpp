#include "palindrome_logic.h"

Palindrome_Logic::Palindrome_Logic() {}

QString Palindrome_Logic::cleanString(const QString &input) {
    QString cleaned = "";
    for (QChar ch : input) {
        if (ch.isLetterOrNumber()) {
            cleaned += ch.toLower();
        }
    }
    return cleaned;
}

bool Palindrome_Logic::testPalindrome(const QString &input) {
    QString pure = cleanString(input);
    if (pure.isEmpty()) return false;

    int left = 0;
    int right = pure.length() - 1;
    while (left < right) {
        if (pure[left] != pure[right]) return false;
        left++;
        right--;
    }
    return true;
}