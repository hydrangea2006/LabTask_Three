#include "palindrome_logic.h"

// 【函数对象实现】
QString StringCleaner::operator()(const QString &input) {
    QString cleaned = "";
    for (QChar ch : input) {
        if (ch.isLetterOrNumber()) {
            cleaned += ch.toLower();
        }
    }
    return cleaned;
}

// 【构造函数实现】：对象出生时计数器清零
Palindrome_Logic::Palindrome_Logic(const QString &input) {
    m_storedInput = input; // 把外面的输入“存入”自家的保险柜
    qDebug() << "对象已创建，并记录了输入内容：" << m_storedInput;
}
// 【友元函数实现】：不需要加类名作用域，直接点出私有变量
void reportStatus(const Palindrome_Logic &logic) {
    StringCleaner cleaner;
    QString pure = cleaner(logic.m_storedInput); // 直接点出私有的 m_storedInput

    QString half = pure.left(pure.length() / 2);
    qDebug() << "【友元播报】已存输入的一半是：" << half;
}

bool Palindrome_Logic::testPalindrome() {

    // 使用函数对象来进行清洗逻辑
    StringCleaner cleaner;
     QString pure = cleaner(m_storedInput);
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

