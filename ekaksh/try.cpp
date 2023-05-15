#include <iostream>
#include "matplotlibcpp.h"
#include <vector>
#include <iostream>

namespace plt = matplotlibcpp; // Define a namespace alias for matplotlibcpp

int main() {
    // Generate data for the plot
    std::vector<double> x;
    std::vector<double> y;
    for (double i = 0.1; i <= 10.0; i += 0.1) {
        x.push_back(i);
        y.push_back(1.0 / i); // Generate y-values with a log distribution
    }

    // Create a plot
    plt::plot(x, y); // Plot x and y values

    // Set plot title and labels
    plt::title("Log Distribution Graph");
    plt::xlabel("X Axis");
    plt::ylabel("Y Axis");

    // Set logarithmic scale on the x-axis
    plt::xscale("log");

    // Show the plot
    plt::show();

    return 0;
}
