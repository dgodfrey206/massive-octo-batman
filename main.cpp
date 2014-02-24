#include <iostream>
#include <string>
#include "Human.h"

int main()
{
    Human a(5, "David"), b;

    b = make_human(29, "Thomas");
    std::cout << b;
}
