#ifndef COFFEESHOP_LOGIC_H
#define COFFEESHOP_LOGIC_H

class coffeeshop
{
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
    static const double SMALL_PRICE;
    static const double MEDIUM_PRICE;
    static const double LARGE_PRICE;
};

#endif