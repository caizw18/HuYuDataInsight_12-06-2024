#include <iostream>
#include <cmath>

double normalCDF(double x) {
    return 0.5 * erfc(-x * std::sqrt(0.5));
}

double blackScholesPrice(double S, double K, double r, double T, double sigma, bool isCall) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (isCall) {
        return S * normalCDF(d1) - K * std::exp(-r * T) * normalCDF(d2);
    }
    else {
        return K * std::exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
    }
}

int main() {
    double S = 100;   // Current stock price
    double K = 100;   // Strike price
    double r = 0.05;  // Risk-free rate
    double T = 1.0;   // Time to maturity in years
    double sigma = 0.2; // Volatility

    double callPrice = blackScholesPrice(S, K, r, T, sigma, true);
    double putPrice = blackScholesPrice(S, K, r, T, sigma, false);

    std::cout << "Call Price: " << callPrice << std::endl;
    std::cout << "Put Price: " << putPrice << std::endl;

    return 0;
}