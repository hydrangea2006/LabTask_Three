#include "windchill_logic.h"
#include <cmath>
#include <QRegularExpression>

Windchill_Logic::Windchill_Logic() {}

bool Windchill_Logic::validateInput(const QString &tempInput, const QString &windInput) {
    if (!isValidNumber(tempInput, false)) return false;
    if (!isValidNumber(windInput, true)) return false;
    return true;
}

bool Windchill_Logic::isValidNumber(const QString &input, bool isWindSpeed) {
    QString trimmed = input.trimmed();
    if (trimmed.isEmpty()) return false;
    if (trimmed.length() > 10) return false;

    QRegularExpression regex("^-?(\\d*\\.?\\d+|\\d+\\.?\\d*)$");
    if (!regex.match(trimmed).hasMatch()) return false;

    if (trimmed.count('.') > 1) return false;
    if (trimmed.contains('.')) {
        if (trimmed.split('.').last().length() > 2) return false;
    }

    double val = trimmed.toDouble();
    if (isWindSpeed) {
        return (val >= 0 && val <= 212);
    } else {
        return (val >= -100 && val <= 212);
    }
}

double Windchill_Logic::calculateWindChill(double T, double V) {
    double vPow = std::pow(V, 0.16);
    return 35.74 + (0.6215 * T) - (35.75 * vPow) + (0.4275 * T * vPow);
}