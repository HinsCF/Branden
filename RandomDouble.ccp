#include <iostream>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

// Modify as needed
constexpr int MIN = 10;
constexpr int MAX = 100;

int main()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    for (int n = 0; n < 5; ++n) {
        cout << setprecision(10)
             << distr(eng) << "\n";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
