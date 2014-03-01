#include <iostream>
#include <vector>

class io_buffer : public std::streambuf
{
public:
	io_buffer(std::ostream& os, int buf_size = 4);
	int_type overflow(int_type c);
	bool flush();
	int sync();
private:
	std::ostream& os_;
	std::vector<char> buffer;
};