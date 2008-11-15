#include <iostream>
#include <stack>

using namespace std;

struct Two_bytes {
	unsigned char low;
	unsigned char high;
};

union IntByte {
	short i;
	Two_bytes bytes;
};

int main() 
{
	IntByte uni;
	uni.i = 585;
	std::cout << "Test:"
			  << uni.i 
			  << std::endl;
	std::cout << (short)uni.bytes.low << " " << (short)uni.bytes.high << std::endl;
}

