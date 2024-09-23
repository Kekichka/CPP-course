#include <iostream>
#include <cmath>  

double calculate_y(double x, double a, double y_val) {
    if (pow(x, 2) + pow(y_val, 2) <= pow(a, 2)) {
        return x / (15 * pow(x, 2));
    } else {
        return pow(x, 2) + exp(x);
    }
}

int main() {
    double x_min = -3.0, x_max = 3.0, hx = 0.5;
    double a = 5.3, y_val = 1.1;
    
    for (double x = x_min; x <= x_max; x += hx) {
        double y = calculate_y(x, a, y_val);
        std::cout << "For x = " << x << ", y = " << y << std::endl;
    }

    return 0;
}
