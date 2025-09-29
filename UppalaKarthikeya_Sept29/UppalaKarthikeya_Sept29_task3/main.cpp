#include "Functions.h"

// Example polynomial function: f(x) = x^2 + 2x + 1
int polynomial(int x)
{
    return x * x + 2 * x + 1;
}

int main()
{
    
    double a = 3.5, b = 7.9;
    std::cout << "Before exchange: a = " << a << ", b = " << b << "\n";
    exchange(&a, &b);
    std::cout << "After exchange:  a = " << a << ", b = " << b << "\n";

    
    int value = 3;
    std::cout << "evaluate(" << value << ", polynomial) = "
              << evaluate(value, polynomial) << "\n";

    // Initialize vowel array with "AEIOU"
    char vowel[6] = "AEIOU";
    std::cout << "Vowel array (method 1): " << vowel << "\n";

    char vowel2[6];
    std::strcpy(vowel2, "AEIOU");
    std::cout << "Vowel array (method 2): " << vowel2 << "\n";

    return 0;
}
