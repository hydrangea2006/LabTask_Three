#include "gravity_logic.h"
#include <cmath>

const double G = 9.8;

// 仿函数的实现
double DistanceFunctor::operator()(double time) const {
    return 0.5 * G * time * time;
}

// 构造函数：初始化重力值，动态分配数组
Gravity_Logic::Gravity_Logic()
    : m_gravity(G), m_distances(new double[11]())  // 索引0~10，索引0未使用
{
}

// 析构函数：释放动态分配的内存
Gravity_Logic::~Gravity_Logic() {
    delete[] m_distances;
}

// 原有的距离计算函数（仍可使用，但内部也可直接使用公式）
double Gravity_Logic::calculateDistance(double time) {
    return 0.5 * m_gravity * time * time;
}

// 生成表格：使用仿函数计算距离，并保存到动态数组中
QString Gravity_Logic::generateTable() {
    DistanceFunctor distFunc;   // 创建仿函数对象
    QString result;
    result.append("Time (seconds)\tDistance (meters)\n");
    result.append("================================\n");

    for (int t = 1; t <= 10; ++t) {
        // 使用仿函数计算距离
        double distance = distFunc(static_cast<double>(t));
        // 存入动态数组（供后续可能使用）
        m_distances[t] = distance;
        result.append(QString("%1\t\t%2\n").arg(t).arg(distance, 0, 'f', 2));
    }
    return result;
}

// 友元函数实现：打印指定时间点的距离（演示访问私有成员 m_gravity）
void printCustomDistance(const Gravity_Logic& logic, double time) {
    double dist = 0.5 * logic.m_gravity * time * time;
    qDebug("Custom friend function: at t=%.2f s, distance=%.2f m", time, dist);
    // 注意：若要在Qt Widget中显示，可改为信号或直接操作UI，这里仅作演示
}