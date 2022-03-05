#include <iostream>
#include "Fraction.hpp"

using namespace Frac;

int main()
{
	Fraction A{1, 2};
	Fraction B{2, 5};
	Fraction A_ = A;

//================================ Testing all features ================================//
	
	Fraction D = dec_to_reg(3.1416);
	std::cout << "D = " << D << std::endl; 
	std::cout << "A = " << A << " = " << A.decimal() << std::endl;
	std::cout << "B = " << B << " = " << B.decimal() << std::endl;

	std::cout << "A + B = " << A + B << std::endl;
	std::cout << "A - B = " << A - B << std::endl;
	std::cout << "A * B = " << A * B << std::endl;
	std::cout << "A / B = " << A / B << std::endl;

	std::cout << "A += B = " << (A += B) << std::endl;
	A = A_;
	std::cout << "A -= B = " << (A -= B) << std::endl;
	A = A_;
	std::cout << "A *= B = " << (A *= B) << std::endl;
	A = A_;
	std::cout << "A /= B = " << (A /= B) << std::endl;
	A = A_;

	std::cout << "A + 2 = " << A + 2 << std::endl;
	std::cout << "A - 2 = " << A - 2 << std::endl;
	std::cout << "A * 2 = " << A * 2 << std::endl;
	std::cout << "A / 2 = " << A / 2 << std::endl;

	std::cout << "2 + A = " << 2 + A << std::endl;
	std::cout << "2 - A = " << 2 - A << std::endl;
	std::cout << "2 * A = " << 2 * A << std::endl;
	std::cout << "2 / A = " << 2 / A << std::endl;

	std::cout << "A += 2 = " << (A += 2) << std::endl;
	A = A_;
	std::cout << "A -= 2 = " << (A -= 2) << std::endl;
	A = A_;
	std::cout << "A *= 2 = " << (A *= 2) << std::endl;
	A = A_;
	std::cout << "A /= 2 = " << (A /= 2) << std::endl;
	A = A_;

	std::cout << "-A = " << -A << std::endl;
	std::cout << "A++ = " << A++ << std::endl;
	A = A_;
	std::cout << "++A = " << ++A << std::endl;
	A = A_;
	std::cout << "A-- = " << A-- << std::endl;
	A = A_;
	std::cout << "--A = " << --A << std::endl;
	A = A_;

	return 0;
}