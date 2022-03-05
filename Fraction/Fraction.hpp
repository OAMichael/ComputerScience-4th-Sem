#include <iostream>
#include <cmath>
#pragma once

#define ACCURACY 1e-8

// A namespace for all fraction stuff
namespace Frac {

    // Greatest common diviser function
    int& gcd(int& a, int& b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

//======================================= Main object =======================================//
    
    class Fraction {

    private:
        int numerator_;
        int denominator_;
        int gcd_;

    public:

        int get_num() const { return numerator_;   }
        int get_den() const { return denominator_; }

        void set_num(const int& num) { 
            numerator_   = num;
            return;
        }

        void set_den(const int& den) { 
            if(den == 0)
                throw std::exception();
            
            denominator_ = den;
            return;
        }

        // Reducing function-member
        void reduce() {
            int num = numerator_;
            int den = denominator_;

            gcd_ = gcd(num, den);
            numerator_   /= gcd_;
            denominator_ /= gcd_;

            return;
        }

        double decimal() { return static_cast<double>(numerator_) / denominator_; }

//------------------------------ Overloading assignment operator -------------------------------//

        const Fraction& operator=(const Fraction& Frac) {
            if (this == &Frac) { return *this; }

            numerator_   = Frac.numerator_;
            denominator_ = Frac.denominator_;
            return *this;
        }

//------------------------------------ Overloading negation ------------------------------------//

        const Fraction operator-() {
            Fraction A{-this->numerator_, this->denominator_};
            A.reduce();
            return A;
        }

//------------------------------------- Adding overloading -------------------------------------//

        const Fraction operator+(const int& Value) {
            Fraction A{numerator_ + Value * denominator_, denominator_};
            A.reduce();
            return A;
        }

        const Fraction operator+(const Fraction& Other) {
            Fraction A{numerator_ * Other.get_den() + Other.get_num() * denominator_, 
                                                          denominator_ * Other.get_den()};
            A.reduce();
            return A;
        }

        const Fraction& operator+=(const int& Value) {
            *this = *this + Value;
            return *this;
        }

        const Fraction& operator+=(const Fraction& Other) {
            *this = *this + Other;
            return *this;
        }

        const Fraction& operator++() {
            *this = *this + 1;
            return *this;
        }

        const Fraction operator++(int) {
            Fraction temp = *this;
            ++temp;
            return temp;
        }

//---------------------------------- Subtracting overloading -----------------------------------//

        const Fraction operator-(const int& Value) {
            Fraction A{numerator_ - Value * denominator_, denominator_};
            A.reduce();
            return A;
        }

        const Fraction operator-(const Fraction& Other) {
            Fraction A{numerator_ * Other.get_den() - Other.get_num() * denominator_, 
                                                          denominator_ * Other.get_den()};
            A.reduce();
            return A;
        }

        const Fraction& operator-=(const int& Value) {
            *this = *this - Value;
            return *this;
        }

        const Fraction& operator-=(const Fraction& Other) {
            *this = *this - Other;
            return *this;
        }

        const Fraction& operator--() {
            *this = *this - 1;
            return *this;
        }

        const Fraction operator--(int) {
            Fraction temp = *this;
            --temp;
            return temp;
        }

//--------------------------------- Multiplication overloading ---------------------------------//

        const Fraction operator*(const int& Value) {
            Fraction A{Value * numerator_, denominator_};
            A.reduce();
            return A;
        }

        const Fraction operator*(const Fraction& Other) {
            Fraction A{numerator_ * Other.get_num(), denominator_ * Other.get_den()};
            A.reduce();
            return A;
        }

        const Fraction& operator*=(const int& Value) {
            *this = *this * Value;
            return *this;
        }

        const Fraction& operator*=(const Fraction& Other) {
            *this = *this * Other;
            return *this;
        }

//------------------------------------ Division overloading ------------------------------------//

        const Fraction operator/(const int& Value) {
            Fraction A{numerator_, Value * denominator_};
            A.reduce();
            return A;
        }

        const Fraction operator/(const Fraction& Other) {
            Fraction A{numerator_ * Other.get_den(), denominator_ * Other.get_num()};
            A.reduce();
            return A;
        }

        const Fraction& operator/=(const int& Value) {
            *this = *this / Value;
            return *this;
        }

        const Fraction& operator/=(const Fraction& Other) {
            *this = *this / Other;
            return *this;
        }
//-------------------------------- Constructors and destructors --------------------------------//

        Fraction() {
            numerator_ = 0;
            denominator_ = 1;
            gcd_ = 1;
        };

        Fraction(const int& num, const int& den) : numerator_{num}, denominator_{den} {
            if (den == 0)
                throw std::exception();
        };

        Fraction(const Fraction& Frac) : numerator_(Frac.numerator_), denominator_(Frac.denominator_) {};

        ~Fraction() {};

    };

//====================================== External logic ======================================//

    // Function converting decimal to regular fraction
    const Fraction dec_to_reg(const double& dec) {
        double tmp = dec;
        int whole = static_cast<int>(floor(tmp));
        double frac = dec - whole;

        int cntr = 1;
        while(frac > ACCURACY && cntr < 1e8) {
            cntr *= 10;
            frac *= 10;
            frac -= floor(frac);
        }

        Fraction A{static_cast<int>((dec - whole) * cntr), cntr};
        A.reduce();
        A = A + whole;

        return A;
    }

    const Fraction operator+(const Fraction& Frac, const double& Value) {
        Fraction A = dec_to_reg(Value);
        A = A + Frac;
        return A;
    }

    const Fraction operator+(const double& Value, const Fraction& Frac) {
        Fraction A = dec_to_reg(Value);
        Fraction B = A + Frac;
        B.reduce();
        return B;
    }

//------------------------------------ Iostreams overloading -----------------------------------//

    std::ostream& operator<<(std::ostream& out, const Fraction& obj) {
        if(obj.get_den() < 0) {
            out << -obj.get_num() << "/" << -obj.get_den();
        }
        else
            out << obj.get_num() << "/" << obj.get_den();
        
        return out;
    }

    std::istream& operator>>(std::istream& in,  Fraction& obj) {
        int num, den;
        char slash;
        in >> num >> slash >> den;

        if(!in.good()) {
            std::cout << "Bad input" << std::endl;
            return in;
        }

        try {
            obj.set_num(num);
            obj.set_den(den);
        }
        catch(const std::exception& e) {
            std::cout << "The denominator cannot be 0" << std::endl;
        }
        return in;
    }

//----------------------------------- Comparison overloading -----------------------------------//

    bool operator==(const Fraction& A_, const Fraction& B_) {
        Fraction A = A_;
        Fraction B = B_;

        A.reduce();
        B.reduce();

        if(A.get_num() != B.get_num())
            return 0;

        if(A.get_den() != B.get_den())
            return 0;

        return 1;
    }

    bool operator>(const Fraction& A_, const Fraction& B_) {
        Fraction A = A_;
        Fraction B = B_;

        A.reduce();
        B.reduce();

        if( static_cast<double>(A.get_num()) / A.get_den() > static_cast<double>(B.get_num()) / B.get_den() )
            return 1;
        return 0;
    }

    bool operator<(const Fraction& A_, const Fraction& B_) {
        Fraction A = A_;
        Fraction B = B_;

        A.reduce();
        B.reduce();

        if( static_cast<double>(A.get_num()) / A.get_den() < static_cast<double>(B.get_num()) / B.get_den() )
            return 1;
        return 0;
    }

    bool operator!=(const Fraction& A, const Fraction& B) {
        if(A == B)
            return 0;
        return 1;
    }

    bool operator>=(const Fraction& A, const Fraction& B) {
        if(A == B || A > B)
            return 1;
        return 0;
    }

    bool operator<=(const Fraction& A, const Fraction& B) {
        if(A == B || A < B)
            return 1;
        return 0;
    }

//------------------- Overloading operators for reverse operations (s.t. 2 + A) ------------------//

    const Fraction operator+(const int& Value, const Fraction& Frac) {
        Fraction A{Value * Frac.get_den() + Frac.get_num(), Frac.get_den()};
        A.reduce();
        return A;
    }

    const Fraction operator-(const int& Value, const Fraction& Frac) {
        Fraction A{Value * Frac.get_den() - Frac.get_num(), Frac.get_den()};
        A.reduce();
        return A;
    }

    const Fraction operator*(const int& Value, const Fraction& Frac) {
        Fraction A{Value * Frac.get_num(), Frac.get_den()};
        A.reduce();
        return A;
    }

    const Fraction operator/(const int& Value, const Fraction& Frac) {
        Fraction A{Value * Frac.get_den(), Frac.get_num()};
        A.reduce();
        return A;
    }
}