#include <iostream>
#include "Fraction.hpp"

using namespace Frac;
using std::cout, std::endl;

int main()
{
	Fraction A{1, 2};
	Fraction B{2, 5};
	Fraction A_ = A;

//================================ Testing all features ================================//

	cout << "A = " << A << " = " << A.decimal() << endl;
	cout << "B = " << B << " = " << B.decimal() << endl << endl;

	cout << "A > B: "  << (A > B)  << endl;
	cout << "A < B: "  << (A < B)  << endl;
	cout << "A >= B: " << (A >= B) << endl;
	cout << "A <= B: " << (A <= B) << endl;
	cout << "A == B: " << (A == B) << endl << endl;

	Fraction D = dec_to_reg(3.1416);
	cout << "D = " << D << endl << endl; 

	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "A / B = " << A / B << endl << endl;

	cout << "A += B = " << (A += B) << endl;
	A = A_;
	cout << "A -= B = " << (A -= B) << endl;
	A = A_;
	cout << "A *= B = " << (A *= B) << endl;
	A = A_;
	cout << "A /= B = " << (A /= B) << endl << endl;
	A = A_;

	cout << "A + 2 = " << A + 2 << endl;
	cout << "A - 2 = " << A - 2 << endl;
	cout << "A * 2 = " << A * 2 << endl;
	cout << "A / 2 = " << A / 2 << endl << endl;

	cout << "2 + A = " << 2 + A << endl;
	cout << "2 - A = " << 2 - A << endl;
	cout << "2 * A = " << 2 * A << endl;
	cout << "2 / A = " << 2 / A << endl << endl;

	cout << "A += 2 = " << (A += 2) << endl;
	A = A_;
	cout << "A -= 2 = " << (A -= 2) << endl;
	A = A_;
	cout << "A *= 2 = " << (A *= 2) << endl;
	A = A_;
	cout << "A /= 2 = " << (A /= 2) << endl << endl;
	A = A_;

	cout << "-A = " << -A << endl;
	cout << "A++ = " << A++ << endl;
	A = A_;
	cout << "++A = " << ++A << endl;
	A = A_;
	cout << "A-- = " << A-- << endl;
	A = A_;
	cout << "--A = " << --A << endl;

	return 0;
}