#!/usr/bin/python3

from time import sleep

def PrimeNumberGen():
    NewPrime = 2
    while True:
        yield NewPrime
        Flag = True
        while (Flag == True):
            NewPrime += 1
            for i in range(2, NewPrime):
                if (NewPrime % i == 0):
                    Flag = True
                    break
                else:
                    Flag = False

def main():
    Iter = PrimeNumberGen()
    while True:
        print(next(Iter))
        sleep(0.1)


if __name__ == '__main__':
    main()