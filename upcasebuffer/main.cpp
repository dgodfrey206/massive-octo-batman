#include "upcasebuffer.h"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ostringstream oss;
    io_buffer buf(oss);

    std::ostream os(&buf);
    std::string str("Hello, World how are you?");
    
    os << str;
    std::cout << oss.str() << std::endl;
}
