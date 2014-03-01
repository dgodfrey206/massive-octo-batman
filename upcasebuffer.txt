#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <sstream>

class io_buffer : public std::streambuf
{
public:
    io_buffer(std::ostream& os, int buf_size = 4)
        : os_(os), buffer(buf_size)
    {
        os_.clear();
        char* beg = buffer.data();
        setp(beg, beg + buffer.size());
    }
    
    int_type overflow(int_type c)
    {   
        if (os_ && !traits_type::eq_int_type(c, traits_type::eof()))
        {
            *pptr() = traits_type::to_char_type(std::toupper(c));
            pbump(1);
            
            if (flush())
            {
                pbump(-buffer.size());
                setp(buffer.data(), buffer.data() + buffer.size());
                return c;
            } else
                return traits_type::eof();
        }
        
        return traits_type::eof();
    }
    
    bool flush()
    {
        for (auto& c: buffer)
            c = std::toupper(c);
        return os_.write(pbase(), pptr() - pbase());
    }
    
    int sync()
    {
        return flush() ? 0 : -1;
    }
private:
    std::ostream& os_;
    std::vector<char> buffer;
};

int main()
{
    std::ostringstream oss;
    io_buffer buf(oss);

    std::ostream os(&buf);
    std::string str("Hello, World how are you?");
    
    os << str;
    std::cout << oss.str() << std::endl;
}