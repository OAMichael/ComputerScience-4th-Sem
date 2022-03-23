#!/usr/bin/python3

#--------------------------------------- Main object ---------------------------------------#
class Fraction:
    __slots__ = ('__numerator', '__denominator', '__gcd',)

    def __init__(self, numerator = 0, denominator = -1):
        if denominator == 0:
            raise ZeroDivisionError("division by zero")
        self.__numerator = numerator
        self.__denominator = denominator
  
#----------------------------------------- Getters -----------------------------------------#  
    @property
    def num(self):
        return self.__numerator

    @property
    def den(self):
        return self.__denominator

#----------------------------------------- Deleters ----------------------------------------#  
    @property
    def del_num(self):
        del self.__numerator

    @property
    def del_den(self):
        del self.__denominator

#---------------------------- Greatest common diviser function -----------------------------#  
    @staticmethod
    def gcd(self):
        x = self.__numerator
        y = self.__denominator
        while y:
            x %= y
            x, y = y, x
        return x

#---------------------------- Reducing fraction and reversing ------------------------------#  
    def reduce(self):
        gcd_loc = self.gcd(self)
        self.__numerator = int(self.__numerator / gcd_loc)
        self.__denominator = int(self.__denominator / gcd_loc)

    def reverse(self):
        self.__numerator, self.__denominator = self.__denominator, self.__numerator
        return self

    def reduced(self):
        gcd_loc = self.gcd(self)
        A = Fraction(int(self.__numerator / gcd_loc), int(self.__denominator / gcd_loc))
        return A

    def reversed(self):
        A = Fraction(self.__denominator, self.__numerator)
        return A

#------------------------------- Overloading common operators ------------------------------#  
    def __add__(self, other):
        A = Fraction(self.__numerator * other.den + self.__denominator * other.num, self.__denominator * other.den)
        A.reduce()
        return A
    def __sub__(self, other):
        A = Fraction(self.__numerator * other.den - self.__denominator * other.num, self.__denominator * other.den)
        A.reduce()
        return A
    def __mul__(self, other):
        A = Fraction(self.__numerator * other.num, self.__denominator * other.den)
        A.reduce()
        return A
    def __truediv__(self, other):
        if other.__numerator == 0:
            raise ZeroDivisionError("division by zero")
        A = Fraction(self.__numerator * other.den, self.__denominator * other.num)
        A.reduce()
        return A
    def __pow__(self, other):
        A = Fraction(self.__numerator   ** (other.__numerator / other.__denominator), 
                     self.__denominator ** (other.__numerator / other.__denominator))
        A.reduce()
        return A

#----------------------------- Overloading assignment operators ----------------------------#  
    def __iadd__(self, other):
        self = self + other
        return self
    def __isub__(self, other):
        self = self - other
        return self
    def __imul__(self, other):
        self = self * other
        return self
    def __itruediv__(self, other):
        if other.__numerator == 0:
            raise ZeroDivisionError("division by zero")
        self = self / other
        return self
    def __ipow__(self, other):
        self = self ** other
        return self

#---------------------------- Overloading comparative operators ----------------------------#  
    def __eq__(self, other):
        if self.__numerator * other.__denominator == self.__denominator * other.__numerator:
            return 1
        else:
            return 0
    def __ne__(self, other):
        if self == other:
            return 0
        else:
            return 1
    def __lt__(self, other):
        if self.__numerator * other.__denominator < self.__denominator * other.__numerator:
            return 1
        else:
            return 0
    def __gt__(self, other):
        if self.__numerator * other.__denominator > self.__denominator * other.__numerator:
            return 1
        else:
            return 0
    def __le__(self, other):
        if self == other or self < other:
            return 1
        else:
            return 0
    def __ge__(self, other):
        if self == other or self > other:
            return 1
        else:
            return 0

#----------------------------------- Overloading negation ----------------------------------#  
    def __neg__(self):
        A = Fraction(-self.__numerator, self.__denominator)
        return A

#------------------------------------ Overloading output -----------------------------------#  
    def __str__(self):
        if self.__denominator < 0:
            self.__numerator *= -1
            self.__denominator *= -1

        return f'{self.__numerator}/{self.__denominator}'


def main():
#----------------------------------- Testing all features ----------------------------------#  

    x = Fraction(int(input()), int(input()))
    y = Fraction(int(input()), int(input()))
    x_init = x

    print(f'x = {x}')
    print(f'y = {y}')
    print(f'x + y  = {x + y}')
    print(f'x - y  = {x - y}')
    print(f'x * y  = {x * y}')
    print(f'x / y  = {x / y}')
    print(f'x ** y = {x ** y}')
    
    x += y
    print(f'x += y =  {x}')
    x = x_init

    x -= y
    print(f'x -= y =  {x}')
    x = x_init
    
    x *= y
    print(f'x *= y =  {x}')
    x = x_init
    
    x /= y
    print(f'x /= y =  {x}')
    x = x_init
    
    x **= y
    print(f'x **= y = {x}')
    x = x_init

    print(f'x == y: {x == y}')
    print(f'x != y: {x != y}')
    print(f'x < y:  {x < y}')
    print(f'x > y:  {x > y}')
    print(f'x <= y: {x <= y}')
    print(f'x >= y: {x >= y}')
    print(f'-x = {-x}')

    print(f'reversed = {x.reversed()}')
    print(f'reduced  = {x.reduced() }')
    print(f'reverse  = {x.reverse() }')
    x = x_init
    print(f'reduce   = {x.reverse() }')


if __name__ == '__main__':
    main()