#include "coffeeshop_logic.h"

// 定义静态常量
const double coffeeshop::SMALL_PRICE = 1.75;
const double coffeeshop::MEDIUM_PRICE = 1.90;
const double coffeeshop::LARGE_PRICE = 2.00;

coffeeshop::coffeeshop()
{
}

// 输入验证
bool coffeeshop::validateInput(int small, int medium, int large)
{
    if (small < 0 || medium < 0 || large < 0)
        return false;

    if (small == 0 && medium == 0 && large == 0)
        return false;

    return true;
}

// 销售咖啡（更新数量）
void coffeeshop::sellCoffee(int &smallSold, int &mediumSold, int &largeSold,
                            int buySmall, int buyMedium, int buyLarge)
{
    smallSold += buySmall;
    mediumSold += buyMedium;
    largeSold += buyLarge;
}

// 计算总盎司
int coffeeshop::getTotalOunces(int smallSold, int mediumSold, int largeSold)
{
    return smallSold * SMALL_OZ +
           mediumSold * MEDIUM_OZ +
           largeSold * LARGE_OZ;
}

// 计算总金额
double coffeeshop::getTotalMoney(int smallSold, int mediumSold, int largeSold)
{
    return smallSold * SMALL_PRICE +
           mediumSold * MEDIUM_PRICE +
           largeSold * LARGE_PRICE;
}