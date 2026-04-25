#ifndef COFFEESHOP_LOGIC_H
#define COFFEESHOP_LOGIC_H

// 前置声明友元类
class ShopInspector;

class coffeeshop
{
    // 友元声明：ShopInspector 可访问私有成员
    friend class ShopInspector;

public:
    coffeeshop();

    bool validateInput(int small, int medium, int large);
    void sellCoffee(int &smallSold, int &mediumSold, int &largeSold,
                    int buySmall, int buyMedium, int buyLarge);
    int getTotalOunces(int smallSold, int mediumSold, int largeSold);
    double getTotalMoney(int smallSold, int mediumSold, int largeSold);

private:
    static const int SMALL_OZ = 9;
    static const int MEDIUM_OZ = 12;
    static const int LARGE_OZ = 15;

    // 改为非const，允许友元访问（逻辑层不会修改）
    static double SMALL_PRICE;
    static double MEDIUM_PRICE;
    static double LARGE_PRICE;
};

// ========== 新增：函数对象（仿函数）==========
// 用于对价格应用倍率调整
class PriceMultiplier
{
public:
    explicit PriceMultiplier(double factor) : m_factor(factor) {}

    // 重载 operator()，成为函数对象
    double operator()(double price) const
    {
        return price * m_factor;
    }

private:
    double m_factor;
};

#endif