// Austin Westfall 
// CIS 1202 800 
// 7/18/23

#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
T half(T value)
{
    if constexpr (is_floating_point_v<T>) {
        return value / 2;
    }
    else if constexpr (is_integral_v<T>) {
        return (value + 1) / 2;
    }
    else {
        static_assert(is_floating_point_v<T> || is_integral_v<T>, "Unsupported type");
    }
}

int main()
{
    int intValue;
    float floatValue;
    double doubleValue;

    cout << "Enter an integer value: ";
    cin >> intValue;

    cout << "Enter a float value: ";
    cin >> floatValue;

    cout << "Enter a double value: ";
    cin >> doubleValue;

    cout << "Half of " << intValue << " is: " << half(intValue) << endl;
    cout << "Half of " << floatValue << " is: " << half(floatValue) << endl;
    cout << "Half of " << doubleValue << " is: " << half(doubleValue) << endl;

    return 0;
}