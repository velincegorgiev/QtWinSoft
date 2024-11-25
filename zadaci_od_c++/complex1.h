#ifndef COMPLEX1_H
#define COMPLEX1_H

#include <iostream>

class Complex {
public:
   Complex(double = 0.0, double = 0.0);
   Complex operator+(const Complex&) const;
   Complex operator-(const Complex&) const;
   Complex operator*(const Complex&) const;
   Complex operator*(int) const;
   Complex operator*(double) const;
   bool operator==(const Complex&) const;
   bool operator!=(const Complex&) const;
   Complex& operator+=(const Complex&);
   Complex& operator-=(const Complex&);
   Complex& operator*=(const Complex&);
   Complex& operator*=(int);
   Complex& operator*=(double);
   friend std::ostream& operator<<(std::ostream&, const Complex&);
   friend std::istream& operator>>(std::istream&, Complex&);

private:
   double real;
   double imaginary;
};

#endif
