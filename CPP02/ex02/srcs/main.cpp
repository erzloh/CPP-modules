#include <iostream>
#include "Fixed.hpp"

// int main() {
//     // Erstellen von zwei Fixed-Objekten
//     Fixed a(5);
//     Fixed b(2.5f);

//     // Testen der Vergleichsoperatoren
//     if (a > b) {
//         std::cout << "a ist größer als b." << std::endl;
//     } else {
//         std::cout << "a ist nicht größer als b." << std::endl;
//     }

//     // Testen der arithmetischen Operatoren
//     Fixed sum = a + b;
//     Fixed difference = a - b;
//     Fixed product = a * b;
//     Fixed quotient = a / b;

//     std::cout << "Summe: " << sum << std::endl;
//     std::cout << "Differenz: " << difference << std::endl;
//     std::cout << "Produkt: " << product << std::endl;
//     std::cout << "Quotient: " << quotient << std::endl;

//     // Testen der Inkrement- und Dekrementoperatoren
//     Fixed c = a++;
//     Fixed d = b--;
//     std::cout << "a nach Post-Inkrement: " << a << std::endl;
//     std::cout << "c nach Post-Inkrement: " << c << std::endl;
//     std::cout << "b nach Post-Dekrement: " << b << std::endl;
//     std::cout << "d nach Post-Dekrement: " << d << std::endl;

//     // Testen von toFloat und toInt
//     float floatVal = a.toFloat();
//     int intVal = b.toInt();
//     std::cout << "a als Float: " << floatVal << std::endl;
//     std::cout << "b als Integer: " << intVal << std::endl;

//     // Testen von static Min und Max
//     Fixed minVal = Fixed::min(a, b);
//     Fixed maxVal = Fixed::max(a, b);
//     std::cout << "Minimum: " << minVal << std::endl;
//     std::cout << "Maximum: " << maxVal << std::endl;

//     return 0;
// }

int main ( void ) {
    Fixed        a;
    Fixed const  b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}