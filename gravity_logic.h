#ifndef GRAVITY_LOGIC_H
#define GRAVITY_LOGIC_H

#include <QString>

// 函数对象（Functor），用于计算自由落体距离
class DistanceFunctor {
public:
    double operator()(double time) const;
};

class Gravity_Logic
{
public:
    Gravity_Logic();
    ~Gravity_Logic();                       // 释放动态内存

    double calculateDistance(double time);  // 原有接口，内部可使用仿函数
    QString generateTable();                // 生成1~10秒的距离表格

    // 友元函数声明（可以访问私有成员 m_gravity）
    friend void printCustomDistance(const Gravity_Logic& logic, double time);

private:
    double m_gravity;                       // 重力加速度（实例变量）
    double* m_distances;                    // 动态分配的数组，存储1~10秒的距离
};

#endif